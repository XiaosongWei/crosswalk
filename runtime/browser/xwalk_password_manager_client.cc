// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/runtime/browser/xwalk_password_manager_client.h"

#include "base/bind_helpers.h"
#include "base/command_line.h"
#include "base/memory/singleton.h"
#include "base/metrics/histogram.h"
#include "base/prefs/pref_service.h"
#include "base/strings/string16.h"
#include "base/strings/utf_string_conversions.h"
//#include "chrome/browser/browsing_data/browsing_data_helper.h"
//#include "chrome/browser/password_manager/password_store_factory.h"
//#include "chrome/browser/password_manager/save_password_infobar_delegate.h"
//#include "chrome/browser/password_manager/sync_metrics.h"
//#include "chrome/browser/profiles/profile.h"
//#include "chrome/browser/sync/profile_sync_service.h"
//#include "chrome/browser/sync/profile_sync_service_factory.h"
//#include "chrome/browser/ui/autofill/password_generation_popup_controller_impl.h"
//#include "chrome/browser/ui/passwords/manage_passwords_ui_controller.h"
//#include "chrome/common/channel_info.h"
//#include "chrome/common/chrome_switches.h"
//#include "chrome/common/url_constants.h"
#include "components/autofill/content/browser/content_autofill_driver.h"
#include "components/autofill/content/browser/content_autofill_driver_factory.h"
#include "components/autofill/content/common/autofill_messages.h"
#include "components/autofill/core/browser/password_generator.h"
#include "components/autofill/core/common/password_form.h"
#include "components/password_manager/content/browser/content_password_manager_driver.h"
#include "components/password_manager/content/browser/password_manager_internals_service_factory.h"
#include "components/password_manager/content/common/credential_manager_messages.h"
#include "components/password_manager/core/browser/browser_save_password_progress_logger.h"
#include "components/password_manager/core/browser/log_receiver.h"
#include "components/password_manager/core/browser/login_database.h"

#include "components/password_manager/core/browser/password_form_manager.h"

#include "components/password_manager/core/browser/password_store_default.h"
#include "components/password_manager/core/browser/password_manager_internals_service.h"
#include "components/password_manager/core/browser/password_manager_metrics_util.h"
#include "components/password_manager/core/browser/password_manager_util.h"
#include "components/password_manager/core/common/credential_manager_types.h"
#include "components/password_manager/core/common/password_manager_pref_names.h"
#include "components/password_manager/core/common/password_manager_switches.h"
#include "components/password_manager/sync/browser/sync_store_result_filter.h"
#include "components/version_info/version_info.h"

#include "content/public/browser/browser_context.h"
#include "content/public/browser/browser_thread.h"

#include "content/public/browser/navigation_entry.h"
#include "content/public/browser/render_view_host.h"
#include "content/public/browser/web_contents.h"
//#include "google_apis/gaia/gaia_urls.h"
#include "net/base/url_util.h"
//#include "third_party/re2/re2/re2.h"

#if defined(OS_ANDROID)
//#include "chrome/browser/android/tab_android.h"
//#include "chrome/browser/password_manager/generated_password_saved_infobar_delegate_android.h"
//#include "chrome/browser/ui/android/snackbars/auto_signin_snackbar_controller.h"
#endif

using password_manager::ContentPasswordManagerDriverFactory;
using password_manager::PasswordManagerInternalsService;
using password_manager::PasswordManagerInternalsServiceFactory;

namespace xwalk {

// Shorten the name to spare line breaks. The code provides enough context
// already.
typedef autofill::SavePasswordProgressLogger Logger;

DEFINE_WEB_CONTENTS_USER_DATA_KEY(XWalkPasswordManagerClient);

/*
// This routine is called when PasswordManagerClient is constructed.
// Currently we report metrics only once at startup. We require
// that this is only ever called from a single thread in order to
// avoid needing to lock (a static boolean flag is then sufficient to
// guarantee running only once).
void ReportMetrics(bool password_manager_enabled,
                   password_manager::PasswordManagerClient* client) {
  static base::PlatformThreadId initial_thread_id =
      base::PlatformThread::CurrentId();
  DCHECK_EQ(base::PlatformThread::CurrentId(), initial_thread_id);

  static bool ran_once = false;
  if (ran_once)
    return;
  ran_once = true;

  password_manager::PasswordStore* store = client->GetPasswordStore();
  // May be null in tests.
  if (store) {
    store->ReportMetrics(client->GetSyncUsername(),
                         client->GetPasswordSyncState() ==
                             password_manager::SYNCING_WITH_CUSTOM_PASSPHRASE);
  }
  UMA_HISTOGRAM_BOOLEAN("PasswordManager.Enabled", password_manager_enabled);
}
*/

void DummyStartSyncProxy(syncer::ModelType type) {
   LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
}

// static
void XWalkPasswordManagerClient::CreateForWebContentsWithAutofillClient(
    content::WebContents* contents,
    autofill::AutofillClient* autofill_client) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  if (FromWebContents(contents))
    return;

  contents->SetUserData(
      UserDataKey(),
      new XWalkPasswordManagerClient(contents, autofill_client));
}

XWalkPasswordManagerClient::XWalkPasswordManagerClient(
    content::WebContents* web_contents,
    autofill::AutofillClient* autofill_client)
    : content::WebContentsObserver(web_contents),
      //profile_(Profile::FromBrowserContext(web_contents->GetBrowserContext())),
      pref_service_(autofill_client->GetPrefs()),
      password_manager_(this),
      driver_factory_(nullptr),
      credential_manager_dispatcher_(web_contents, this),
      //observer_(nullptr),
      can_use_log_router_(false) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  ContentPasswordManagerDriverFactory::CreateForWebContents(web_contents, this,
                                                            autofill_client);
  driver_factory_ =
      ContentPasswordManagerDriverFactory::FromWebContents(web_contents);

  PasswordManagerInternalsService* service =
      PasswordManagerInternalsServiceFactory::GetForBrowserContext(
          web_contents->GetBrowserContext()/*profile_*/);
  if (service)
    can_use_log_router_ = service->RegisterClient(this);
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  saving_passwords_enabled_.Init(
      password_manager::prefs::kPasswordManagerSavingEnabled, pref_service_);
  //ReportMetrics(*saving_passwords_enabled_, this);

  //Xiaosong
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  // Given that LoginDatabase::Init() takes ~100ms on average; it will be called
  // by PasswordStore::Init() on the background thread to avoid UI jank.
  base::FilePath login_db_file_path = web_contents->GetBrowserContext()->GetPath();
  login_db_file_path = login_db_file_path.Append("xwalklogin");
  scoped_ptr<password_manager::LoginDatabase> login_db(
      new password_manager::LoginDatabase(login_db_file_path));  
  //scoped_ptr<password_manager::LoginDatabase> login_db(
  //    password_manager::CreateLoginDatabase(web_contents->GetBrowserContext()->GetPath()));

  scoped_refptr<base::SingleThreadTaskRunner> main_thread_runner(
      base::ThreadTaskRunnerHandle::Get());
  scoped_refptr<base::SingleThreadTaskRunner> db_thread_runner(
      content::BrowserThread::GetMessageLoopProxyForThread(
          content::BrowserThread::DB));

  //scoped_refptr<PasswordStore> ps;
  // For now, we use PasswordStoreDefault. We might want to make a native
  // backend for PasswordStoreX (see below) in the future though.
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__ << " main_thread_runner: " << main_thread_runner.get()
      << " db_thread_runner: " << db_thread_runner.get();
  password_store_ = new password_manager::PasswordStoreDefault(
      main_thread_runner, db_thread_runner, login_db.Pass());
  DCHECK(password_store_);
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__ << " to init password store @@ " << password_store_;
  if (!password_store_->Init(base::Bind(&DummyStartSyncProxy))) {
    // TODO(crbug.com/479725): Remove the LOG once this error is visible in the
    // UI.
    LOG(WARNING) << "Could not initialize password store.";
    //return nullptr;
  }
 LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;     
}

XWalkPasswordManagerClient::~XWalkPasswordManagerClient() {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  PasswordManagerInternalsService* service =
      PasswordManagerInternalsServiceFactory::GetForBrowserContext(
          web_contents()->GetBrowserContext()/*profile_*/);
  if (service)
    service->UnregisterClient(this);
}

bool XWalkPasswordManagerClient::IsAutomaticPasswordSavingEnabled() const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  return base::CommandLine::ForCurrentProcess()->HasSwitch(
             password_manager::switches::kEnableAutomaticPasswordSaving);
}

bool XWalkPasswordManagerClient::IsPasswordManagementEnabledForCurrentPage()
    const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__; return true;
  /*
  DCHECK(web_contents());
  content::NavigationEntry* entry =
      web_contents()->GetController().GetLastCommittedEntry();
  bool is_enabled = false;
  if (!entry) {
    // TODO(gcasto): Determine if fix for crbug.com/388246 is relevant here.
    is_enabled = true;
  } else if (IsURLPasswordWebsiteReauth(entry->GetURL())) {
    // Disable the password manager for online password management.
    is_enabled = false;
  } else if (EnabledForSyncSignin()) {
    is_enabled = true;
  } else {
    // Do not fill nor save password when a user is signing in for sync. This
    // is because users need to remember their password if they are syncing as
    // this is effectively their master password.
    is_enabled = entry->GetURL().host() != chrome::kChromeUIChromeSigninHost;
  }
  if (IsLoggingActive()) {
    password_manager::BrowserSavePasswordProgressLogger logger(this);
    logger.LogBoolean(
        Logger::STRING_PASSWORD_MANAGEMENT_ENABLED_FOR_CURRENT_PAGE,
        is_enabled);
  }
  return is_enabled;
  */
}

bool XWalkPasswordManagerClient::IsSavingEnabledForCurrentPage() const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  return saving_passwords_enabled_ && !IsOffTheRecord() &&
         !DidLastPageLoadEncounterSSLErrors() &&
         IsPasswordManagementEnabledForCurrentPage();
}

std::string XWalkPasswordManagerClient::GetSyncUsername() const {
  return "";
}

bool XWalkPasswordManagerClient::IsSyncAccountCredential(
    const std::string& username,
    const std::string& realm) const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__ << " username " << username;
  return false;
}

bool XWalkPasswordManagerClient::PromptUserToSaveOrUpdatePassword(
    scoped_ptr<password_manager::PasswordFormManager> form_to_save,
    password_manager::CredentialSourceType type,
    bool update_password) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  form_to_save->Save();
  /*

    if (form_to_save->IsBlacklisted())
      return false;
    std::string uma_histogram_suffix(
        password_manager::metrics_util::GroupIdToString(
            password_manager::metrics_util::MonitoredDomainGroupId(
                form_to_save->pending_credentials().signon_realm, GetPrefs())));
    SavePasswordInfoBarDelegate::Create(
        web_contents(), form_to_save.Pass(), uma_histogram_suffix, type);
  */
  return true;
}

bool XWalkPasswordManagerClient::PromptUserToChooseCredentials(
    ScopedVector<autofill::PasswordForm> local_forms,
    ScopedVector<autofill::PasswordForm> federated_forms,
    const GURL& origin,
    base::Callback<void(const password_manager::CredentialInfo&)> callback) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  return true;
  //return ManagePasswordsUIController::FromWebContents(web_contents())->
  //    OnChooseCredentials(local_forms.Pass(), federated_forms.Pass(), origin,
  //                        callback);
}

void XWalkPasswordManagerClient::ForceSavePassword() {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  password_manager::ContentPasswordManagerDriver* driver =
      driver_factory_->GetDriverForFrame(web_contents()->GetFocusedFrame());
  driver->ForceSavePassword();
}

void XWalkPasswordManagerClient::NotifyUserAutoSignin(
    ScopedVector<autofill::PasswordForm> local_forms) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  DCHECK(!local_forms.empty());
/*  
#if defined(OS_ANDROID)
  TabAndroid *tab = TabAndroid::FromWebContents(web_contents());
  ShowAutoSigninSnackbar(tab, local_forms[0]->username_value);
#else
  ManagePasswordsUIController::FromWebContents(web_contents())->
      OnAutoSignin(local_forms.Pass());

#endif
*/
}

void XWalkPasswordManagerClient::AutomaticPasswordSave(
    scoped_ptr<password_manager::PasswordFormManager> saved_form) {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
/*    
#if defined(OS_ANDROID)
  GeneratedPasswordSavedInfoBarDelegateAndroid::Create(web_contents());
#else
  if (IsTheHotNewBubbleUIEnabled()) {
    ManagePasswordsUIController* manage_passwords_ui_controller =
        ManagePasswordsUIController::FromWebContents(web_contents());
    manage_passwords_ui_controller->OnAutomaticPasswordSave(
        saved_form.Pass());
  }
#endif
*/
}

void XWalkPasswordManagerClient::PasswordWasAutofilled(
    const autofill::PasswordFormMap& best_matches) const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
/*    
  ManagePasswordsUIController* manage_passwords_ui_controller =
      ManagePasswordsUIController::FromWebContents(web_contents());
  if (manage_passwords_ui_controller && IsTheHotNewBubbleUIEnabled())
    manage_passwords_ui_controller->OnPasswordAutofilled(best_matches);
*/    
}

void XWalkPasswordManagerClient::PasswordAutofillWasBlocked(
    const autofill::PasswordFormMap& best_matches) const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
/*    
  ManagePasswordsUIController* controller =
      ManagePasswordsUIController::FromWebContents(web_contents());
  if (controller && IsTheHotNewBubbleUIEnabled())
    controller->OnBlacklistBlockedAutofill(best_matches);
*/
}

void XWalkPasswordManagerClient::HidePasswordGenerationPopup() {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  //if (popup_controller_)
  //  popup_controller_->HideAndDestroy();
}

PrefService* XWalkPasswordManagerClient::GetPrefs() {
  return pref_service_;
}

password_manager::PasswordStore*
XWalkPasswordManagerClient::GetPasswordStore() const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__ << " password_store: " << password_store_;
  return password_store_.get();
}

password_manager::PasswordSyncState
XWalkPasswordManagerClient::GetPasswordSyncState() const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  return password_manager::NOT_SYNCING_PASSWORDS;
}

void XWalkPasswordManagerClient::OnLogRouterAvailabilityChanged(
    bool router_can_be_used) {
  if (can_use_log_router_ == router_can_be_used)
    return;
  can_use_log_router_ = router_can_be_used;

  NotifyRendererOfLoggingAvailability();
}

void XWalkPasswordManagerClient::LogSavePasswordProgress(
    const std::string& text) const {
  LOG(ERROR) << __FUNCTION__ << ":" << __LINE__;
  if (!IsLoggingActive())
    return;
  PasswordManagerInternalsService* service =
      PasswordManagerInternalsServiceFactory::GetForBrowserContext(
          web_contents()->GetBrowserContext()/*profile_*/);
  if (service)
    service->ProcessLog(text);
}

bool XWalkPasswordManagerClient::IsLoggingActive() const {
  // WebUI tabs do not need to log password saving progress. In particular, the
  // internals page itself should not send any logs.
  return can_use_log_router_ && !web_contents()->GetWebUI();
}

bool XWalkPasswordManagerClient::WasLastNavigationHTTPError() const {
  DCHECK(web_contents());

  scoped_ptr<password_manager::BrowserSavePasswordProgressLogger> logger;
  if (IsLoggingActive()) {
    logger.reset(new password_manager::BrowserSavePasswordProgressLogger(this));
    logger->LogMessage(
        Logger::STRING_WAS_LAST_NAVIGATION_HTTP_ERROR_METHOD);
  }

  content::NavigationEntry* entry =
      web_contents()->GetController().GetVisibleEntry();
  if (!entry)
    return false;
  int http_status_code = entry->GetHttpStatusCode();

  if (logger)
    logger->LogNumber(Logger::STRING_HTTP_STATUS_CODE, http_status_code);

  if (http_status_code >= 400 && http_status_code < 600)
    return true;
  return false;
}

bool XWalkPasswordManagerClient::DidLastPageLoadEncounterSSLErrors() const {
  content::NavigationEntry* entry =
      web_contents()->GetController().GetLastCommittedEntry();
  bool ssl_errors = true;
  if (!entry) {
    ssl_errors = false;
  } else {
    ssl_errors = net::IsCertStatusError(entry->GetSSL().cert_status);
  }
  if (IsLoggingActive()) {
    password_manager::BrowserSavePasswordProgressLogger logger(this);
    logger.LogBoolean(Logger::STRING_SSL_ERRORS_PRESENT, ssl_errors);
  }
  return ssl_errors;
}

bool XWalkPasswordManagerClient::IsOffTheRecord() const {
  return web_contents()->GetBrowserContext()->IsOffTheRecord();
}

password_manager::PasswordManager*
XWalkPasswordManagerClient::GetPasswordManager() {
  return &password_manager_;
}

autofill::AutofillManager*
XWalkPasswordManagerClient::GetAutofillManagerForMainFrame() {
  autofill::ContentAutofillDriverFactory* factory =
      autofill::ContentAutofillDriverFactory::FromWebContents(web_contents());
  return factory
             ? factory->DriverForFrame(web_contents()->GetMainFrame())
                   ->autofill_manager()
             : nullptr;
}

void XWalkPasswordManagerClient::SetTestObserver(
    autofill::PasswordGenerationPopupObserver* observer) {
  //observer_ = observer;
}

bool XWalkPasswordManagerClient::OnMessageReceived(
    const IPC::Message& message,
    content::RenderFrameHost* render_frame_host) {
  bool handled = true;
  IPC_BEGIN_MESSAGE_MAP_WITH_PARAM(XWalkPasswordManagerClient, message,
                                   render_frame_host)
    // Autofill messages:
    IPC_MESSAGE_HANDLER(AutofillHostMsg_ShowPasswordGenerationPopup,
                        ShowPasswordGenerationPopup)
    IPC_MESSAGE_HANDLER(AutofillHostMsg_ShowPasswordEditingPopup,
                        ShowPasswordEditingPopup)
    IPC_END_MESSAGE_MAP()

    IPC_BEGIN_MESSAGE_MAP(XWalkPasswordManagerClient, message)
    IPC_MESSAGE_HANDLER(AutofillHostMsg_HidePasswordGenerationPopup,
                        HidePasswordGenerationPopup)
    IPC_MESSAGE_HANDLER(AutofillHostMsg_GenerationAvailableForForm,
                        GenerationAvailableForForm)
    IPC_MESSAGE_HANDLER(AutofillHostMsg_PasswordAutofillAgentConstructed,
                        NotifyRendererOfLoggingAvailability)
    // Default:
    IPC_MESSAGE_UNHANDLED(handled = false)
  IPC_END_MESSAGE_MAP()

  return handled;
}

gfx::RectF XWalkPasswordManagerClient::GetBoundsInScreenSpace(
    const gfx::RectF& bounds) {
  gfx::Rect client_area = web_contents()->GetContainerBounds();
  return bounds + client_area.OffsetFromOrigin();
}

void XWalkPasswordManagerClient::ShowPasswordGenerationPopup(
    content::RenderFrameHost* render_frame_host,
    const gfx::RectF& bounds,
    int max_length,
    const autofill::PasswordForm& form) {
  // TODO(gcasto): Validate data in PasswordForm.

  gfx::RectF element_bounds_in_screen_space = GetBoundsInScreenSpace(bounds);

  //popup_controller_ =
  //    autofill::PasswordGenerationPopupControllerImpl::GetOrCreate(
  //        popup_controller_, element_bounds_in_screen_space, form, max_length,
  //        &password_manager_,
  //        driver_factory_->GetDriverForFrame(render_frame_host), observer_,
  //        web_contents(), web_contents()->GetNativeView());
  //popup_controller_->Show(true /* display_password */);
}

void XWalkPasswordManagerClient::ShowPasswordEditingPopup(
    content::RenderFrameHost* render_frame_host,
    const gfx::RectF& bounds,
    const autofill::PasswordForm& form) {
  gfx::RectF element_bounds_in_screen_space = GetBoundsInScreenSpace(bounds);
  //popup_controller_ =
  //    autofill::PasswordGenerationPopupControllerImpl::GetOrCreate(
  //        popup_controller_, element_bounds_in_screen_space, form,
  //        0,  // Unspecified max length.
  //        &password_manager_,
  //        driver_factory_->GetDriverForFrame(render_frame_host), observer_,
  //        web_contents(), web_contents()->GetNativeView());
  //popup_controller_->Show(false /* display_password */);
}

void XWalkPasswordManagerClient::GenerationAvailableForForm(
    const autofill::PasswordForm& form) {
  password_manager_.GenerationAvailableForForm(form);
}

void XWalkPasswordManagerClient::NotifyRendererOfLoggingAvailability() {
  if (!web_contents())
    return;

  web_contents()->GetRenderViewHost()->Send(new AutofillMsg_SetLoggingState(
      web_contents()->GetRenderViewHost()->GetRoutingID(),
      can_use_log_router_));
}

/*
bool XWalkPasswordManagerClient::IsURLPasswordWebsiteReauth(
    const GURL& url) const {
  if (url.GetOrigin() != GaiaUrls::GetInstance()->gaia_url().GetOrigin())
    return false;

  // "rart" param signals this page is for transactional reauth.
  std::string param_value;
  if (!net::GetValueForKeyInQuery(url, "rart", &param_value))
    return false;

  // Check the "continue" param to see if this reauth page is for the passwords
  // website.
  param_value.clear();
  if (!net::GetValueForKeyInQuery(url, "continue", &param_value))
    return false;

  // All password sites, including test sites, have autofilling disabled.
  CR_DEFINE_STATIC_LOCAL(RE2, account_dashboard_pattern,
                         ("passwords(-([a-z-]+\\.corp))?\\.google\\.com"));

  return RE2::FullMatch(GURL(param_value).host(), account_dashboard_pattern);
}*/

bool XWalkPasswordManagerClient::IsTheHotNewBubbleUIEnabled() {
return true;
/*
#if !defined(USE_AURA) && !defined(OS_MACOSX)
  return false;
#endif
  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
  if (command_line->HasSwitch(switches::kDisableSavePasswordBubble))
    return false;

  if (command_line->HasSwitch(switches::kEnableSavePasswordBubble))
    return true;

  std::string group_name =
      base::FieldTrialList::FindFullName("PasswordManagerUI");

  // The bubble should be the default case that runs on the bots.
  return group_name != "Infobar";
  */
}

bool XWalkPasswordManagerClient::IsUpdatePasswordUIEnabled() const {
#if defined(OS_MACOSX)
  return false;
#else
  return IsTheHotNewBubbleUIEnabled();
#endif
}

bool XWalkPasswordManagerClient::EnabledForSyncSignin() {
return false;
/*
  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
  if (command_line->HasSwitch(
          password_manager::switches::kDisableManagerForSyncSignin))
    return false;

  if (command_line->HasSwitch(
          password_manager::switches::kEnableManagerForSyncSignin))
    return true;

  // Default is enabled.
  std::string group_name =
      base::FieldTrialList::FindFullName("PasswordManagerStateForSyncSignin");
  return group_name != "Disabled";
  */
}

const GURL& XWalkPasswordManagerClient::GetMainFrameURL() const {
  return web_contents()->GetVisibleURL();
}

const GURL& XWalkPasswordManagerClient::GetLastCommittedEntryURL() const {
  DCHECK(web_contents());
  content::NavigationEntry* entry =
      web_contents()->GetController().GetLastCommittedEntry();
  if (!entry)
    return GURL::EmptyGURL();

  return entry->GetURL();
}

scoped_ptr<password_manager::CredentialsFilter>
XWalkPasswordManagerClient::CreateStoreResultFilter() const {
  return make_scoped_ptr(new password_manager::SyncStoreResultFilter(this));
}

} // namespace xwalk
