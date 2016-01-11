// Copyright 2015 The Chromium Authors. All rights reserved.
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_RUNTIME_BROWSER_ANDROID_SAVE_PASSWORD_INFOBAR_H_
#define XWALK_RUNTIME_BROWSER_ANDROID_SAVE_PASSWORD_INFOBAR_H_

#include "xwalk/runtime/browser/save_password_infobar_delegate.h"
#include "xwalk/runtime/browser/android/confirm_infobar.h"

namespace xwalk {

// The Android infobar that offers the user the ability to save a password
// for the site.
class SavePasswordInfoBar : public ConfirmInfoBar {
 public:
  explicit SavePasswordInfoBar(
      scoped_ptr<SavePasswordInfoBarDelegate> delegate);

  ~SavePasswordInfoBar() override;

  static bool Register(JNIEnv* env);

 private:
  // ConfirmInfoBar:
  base::android::ScopedJavaLocalRef<jobject> CreateRenderInfoBar(
      JNIEnv* env) override;
  void OnLinkClicked(JNIEnv* env, jobject obj) override;

  DISALLOW_COPY_AND_ASSIGN(SavePasswordInfoBar);
};

}  // namespace xwalk

#endif  // XWALK_RUNTIME_BROWSER_ANDROID_SAVE_PASSWORD_INFOBAR_H_
