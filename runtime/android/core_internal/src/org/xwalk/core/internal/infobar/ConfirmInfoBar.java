// Copyright 2013 The Chromium Authors. All rights reserved.
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

package org.xwalk.core.internal.infobar;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.os.Process;
import android.util.SparseArray;
import android.view.View;
import android.widget.TextView;

import org.chromium.ui.base.WindowAndroid;
import org.chromium.ui.base.WindowAndroid.PermissionCallback;

/**
 * An infobar that presents the user with several buttons.
 *
 * TODO(newt): merge this into InfoBar.java.
 */
public class ConfirmInfoBar extends InfoBar {
    /** Text shown on the primary button, e.g. "OK". */
    private final String mPrimaryButtonText;

    /** Text shown on the secondary button, e.g. "Cancel".*/
    private final String mSecondaryButtonText;

    /** Text shown on the extra button, e.g. "More info". */
    private final String mTertiaryButtonText;

    /** Notified when one of the buttons is clicked. */
    private final InfoBarListeners.Confirm mConfirmListener;

    private WindowAndroid mWindowAndroid;

    public ConfirmInfoBar(InfoBarListeners.Confirm confirmListener, int iconDrawableId,
            Bitmap iconBitmap, String message, String linkText, String primaryButtonText,
            String secondaryButtonText) {
        super(confirmListener, iconDrawableId, iconBitmap, message);
        mPrimaryButtonText = primaryButtonText;
        mSecondaryButtonText = secondaryButtonText;
        mTertiaryButtonText = linkText;
        mConfirmListener = confirmListener;
    }

    /**
     * Specifies the {@link ContentSettingsType}s that are controlled by this InfoBar.
     *
     * @param windowAndroid The WindowAndroid that will be used to check for the necessary
     *                      permissions.
     * @param contentSettings The list of {@link ContentSettingsType}s whose access is guarded
     *                        by this InfoBar.
     */
    protected void setContentSettings(
            WindowAndroid windowAndroid, int[] contentSettings) {
        mWindowAndroid = windowAndroid;
        assert windowAndroid != null
                : "A WindowAndroid must be specified to request access to content settings";
    }

    @Override
    public void createContent(InfoBarLayout layout) {
        layout.setButtons(mPrimaryButtonText, mSecondaryButtonText, mTertiaryButtonText);
    }

    @Override
    public void onButtonClicked(final boolean isPrimaryButton) {
        if (mWindowAndroid == null || !isPrimaryButton || getContext() == null) {
            onButtonClickedInternal(isPrimaryButton);
            return;
        }
    }

    private void onButtonClickedInternal(boolean isPrimaryButton) {
        if (mConfirmListener != null) {
            mConfirmListener.onConfirmInfoBarButtonClicked(this, isPrimaryButton);
        }

        int action = isPrimaryButton ? InfoBar.ACTION_TYPE_OK : InfoBar.ACTION_TYPE_CANCEL;
        onButtonClicked(action, "");
    }
}
