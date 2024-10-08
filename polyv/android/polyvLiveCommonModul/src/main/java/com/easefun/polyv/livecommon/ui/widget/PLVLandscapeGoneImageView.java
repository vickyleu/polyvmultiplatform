package com.easefun.polyv.livecommon.ui.widget;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.res.Configuration;
import android.util.AttributeSet;
import android.view.View;
import android.widget.ImageView;

import androidx.annotation.Nullable;

import com.plv.thirdpart.blankj.utilcode.util.ScreenUtils;

@SuppressLint("AppCompatCustomView")
public class PLVLandscapeGoneImageView extends ImageView {

    public PLVLandscapeGoneImageView(Context context) {
        this(context, null);
    }

    public PLVLandscapeGoneImageView(Context context, @Nullable AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public PLVLandscapeGoneImageView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        setVisibility(ScreenUtils.isLandscape() ? View.GONE : View.VISIBLE);
    }

    @Override
    protected void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            setVisibility(View.GONE);
        } else {
            setVisibility(View.VISIBLE);
        }
    }
}
