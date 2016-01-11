// Copyright 2013 The Chromium Authors. All rights reserved.
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_RUNTIME_BROWSER_ANDROID_CONFIRM_INFOBAR_H_
#define XWALK_RUNTIME_BROWSER_ANDROID_CONFIRM_INFOBAR_H_

#include <string>

#include "base/basictypes.h"
#include "base/strings/string16.h"
#include "components/infobars/core/confirm_infobar_delegate.h"

#include "xwalk/runtime/browser/android/infobar_android.h"

namespace xwalk {

class ConfirmInfoBar : public InfoBarAndroid {
 public:
  explicit ConfirmInfoBar(scoped_ptr<ConfirmInfoBarDelegate> delegate);
  ~ConfirmInfoBar() override;

 protected:
  base::string16 GetTextFor(ConfirmInfoBarDelegate::InfoBarButton button);
  ConfirmInfoBarDelegate* GetDelegate();
  void OnLinkClicked(JNIEnv* env, jobject obj) override;

  // InfoBarAndroid overrides.
  base::android::ScopedJavaLocalRef<jobject> CreateRenderInfoBar(
      JNIEnv* env) override;

 private:
  void ProcessButton(int action, const std::string& action_value) override;

  base::android::ScopedJavaGlobalRef<jobject> java_confirm_delegate_;

  DISALLOW_COPY_AND_ASSIGN(ConfirmInfoBar);
};

// Registers native methods.
bool RegisterConfirmInfoBarDelegate(JNIEnv* env);

}  // namespace xwalk

#endif  // XWALK_RUNTIME_BROWSER_ANDROID_CONFIRM_INFOBAR_H_
