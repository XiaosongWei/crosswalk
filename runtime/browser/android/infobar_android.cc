// Copyright 2013 The Chromium Authors. All rights reserved.
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/runtime/browser/android/infobar_android.h"

#include "base/android/jni_android.h"
#include "base/android/jni_string.h"
#include "base/strings/string_util.h"
#include "components/infobars/core/infobar.h"
#include "components/infobars/core/infobar_delegate.h"
#include "jni/InfoBar_jni.h"

#include "xwalk/runtime/browser/infobar_service.h"

namespace xwalk {

// InfoBarAndroid -------------------------------------------------------------

InfoBarAndroid::InfoBarAndroid(scoped_ptr<infobars::InfoBarDelegate> delegate)
    : infobars::InfoBar(delegate.Pass()) {
}

InfoBarAndroid::~InfoBarAndroid() {
  if (!java_info_bar_.is_null()) {
    JNIEnv* env = base::android::AttachCurrentThread();
    Java_InfoBar_onNativeDestroyed(env, java_info_bar_.obj());
  }
}

void InfoBarAndroid::ReassignJavaInfoBar(InfoBarAndroid* replacement) {
  DCHECK(replacement);
  if (!java_info_bar_.is_null()) {
    replacement->SetJavaInfoBar(java_info_bar_);
    java_info_bar_.Reset();
  }
}

void InfoBarAndroid::SetJavaInfoBar(
    const base::android::JavaRef<jobject>& java_info_bar) {
  DCHECK(java_info_bar_.is_null());
  java_info_bar_.Reset(java_info_bar);
  JNIEnv* env = base::android::AttachCurrentThread();
  Java_InfoBar_setNativeInfoBar(env, java_info_bar.obj(),
                                reinterpret_cast<intptr_t>(this));
}

jobject InfoBarAndroid::GetJavaInfoBar() {
  return java_info_bar_.obj();
}

bool InfoBarAndroid::HasSetJavaInfoBar() const {
  return !java_info_bar_.is_null();
}

void InfoBarAndroid::OnButtonClicked(JNIEnv* env,
                                     jobject obj,
                                     jint action,
                                     jstring action_value) {
  std::string value = base::android::ConvertJavaStringToUTF8(env, action_value);
  ProcessButton(action, value);
}

void InfoBarAndroid::OnCloseButtonClicked(JNIEnv* env, jobject obj) {
  if (!owner()) return;
  delegate()->InfoBarDismissed();
  RemoveSelf();
}

void InfoBarAndroid::CloseJavaInfoBar() {
  if (!java_info_bar_.is_null()) {
    JNIEnv* env = base::android::AttachCurrentThread();
    Java_InfoBar_closeInfoBar(env, java_info_bar_.obj());
  }
}

int InfoBarAndroid::GetEnumeratedIconId() {
  return 0;
}


// Native JNI methods ---------------------------------------------------------

bool RegisterNativeInfoBar(JNIEnv* env) {
  return RegisterNativesImpl(env);
}

}  // namespace xwalk
