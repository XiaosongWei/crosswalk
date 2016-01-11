// Copyright 2014 The Chromium Authors. All rights reserved.
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/runtime/browser/save_password_infobar_delegate.h"

#include "components/infobars/core/infobar.h"
#include "components/password_manager/core/browser/password_bubble_experiment.h"
#include "components/password_manager/core/browser/password_manager_client.h"
#include "content/public/browser/web_contents.h"
#include "ui/base/l10n/l10n_util.h"
#include "net/base/registry_controlled_domains/registry_controlled_domain.h"

#include "xwalk/runtime/browser/infobar_service.h"
#include "xwalk/grit/xwalk_resources.h"

namespace {

int GetCancelButtonText(password_manager::CredentialSourceType source_type) {
  return source_type ==
      password_manager::CredentialSourceType::CREDENTIAL_SOURCE_API
      ? IDS_PASSWORD_MANAGER_SAVE_PASSWORD_SMART_LOCK_NO_THANKS_BUTTON
      : IDS_PASSWORD_MANAGER_BLACKLIST_BUTTON;
}

}  // namespace

namespace xwalk {

// static
void SavePasswordInfoBarDelegate::Create(
    content::WebContents* web_contents,
    scoped_ptr<password_manager::PasswordFormManager> form_to_save,
    password_manager::CredentialSourceType source_type) {
  if (!InfoBarService::FromWebContents(web_contents)) {
    InfoBarService::CreateForWebContents(web_contents);
  }
  InfoBarService::FromWebContents(web_contents)
      ->AddInfoBar(CreateSavePasswordInfoBar(
          make_scoped_ptr(new SavePasswordInfoBarDelegate(
              web_contents, form_to_save.Pass(),
              source_type))));
}

SavePasswordInfoBarDelegate::~SavePasswordInfoBarDelegate() {
}

SavePasswordInfoBarDelegate::SavePasswordInfoBarDelegate(
    content::WebContents* web_contents,
    scoped_ptr<password_manager::PasswordFormManager> form_to_save,
    password_manager::CredentialSourceType source_type)
    : ConfirmInfoBarDelegate(),
      form_to_save_(form_to_save.Pass()),
      infobar_response_(password_manager::metrics_util::NO_RESPONSE),
      source_type_(source_type) {
  title_link_range_ = gfx::Range();
  title_ = l10n_util::GetStringUTF16(IDS_SAVE_PASSWORD);
}

infobars::InfoBarDelegate::Type
SavePasswordInfoBarDelegate::GetInfoBarType() const {
  return PAGE_ACTION_TYPE;
}

infobars::InfoBarDelegate::InfoBarAutomationType
SavePasswordInfoBarDelegate::GetInfoBarAutomationType() const {
  return PASSWORD_INFOBAR;
}

int SavePasswordInfoBarDelegate::GetIconID() const {
  return kNoIconID;
}

bool SavePasswordInfoBarDelegate::ShouldExpire(
    const NavigationDetails& details) const {
  return !details.is_redirect && ConfirmInfoBarDelegate::ShouldExpire(details);
}

void SavePasswordInfoBarDelegate::InfoBarDismissed() {
  DCHECK(form_to_save_.get());
  infobar_response_ = password_manager::metrics_util::INFOBAR_DISMISSED;
}

base::string16 SavePasswordInfoBarDelegate::GetMessageText() const {
  return title_;
}

base::string16 SavePasswordInfoBarDelegate::GetButtonLabel(
    InfoBarButton button) const {
  return l10n_util::GetStringUTF16((button == BUTTON_OK)
                                       ? IDS_PASSWORD_MANAGER_SAVE_BUTTON
                                       : GetCancelButtonText(source_type_));
}

bool SavePasswordInfoBarDelegate::Accept() {
  DCHECK(form_to_save_.get());
  form_to_save_->Save();
  infobar_response_ = password_manager::metrics_util::REMEMBER_PASSWORD;
  return true;
}

bool SavePasswordInfoBarDelegate::Cancel() {
  DCHECK(form_to_save_.get());
  if (source_type_ ==
      password_manager::CredentialSourceType::CREDENTIAL_SOURCE_API) {
    InfoBarDismissed();
  } else {
    form_to_save_->PermanentlyBlacklist();
    infobar_response_ = password_manager::metrics_util::NEVER_REMEMBER_PASSWORD;
  }
  return true;
}

bool SavePasswordInfoBarDelegate::LinkClicked(
    WindowOpenDisposition disposition) {
  return true;
}

}  // namespace xwalk
