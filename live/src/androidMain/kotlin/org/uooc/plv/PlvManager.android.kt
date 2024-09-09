package org.uooc.plv

import android.app.Activity
import android.app.Application
import coil3.PlatformContext
import com.easefun.polyv.livecloudclass.scenes.PLVLCCloudClassActivity
import com.easefun.polyv.livecommon.module.config.PLVLiveChannelConfigFiller
import com.easefun.polyv.livecommon.module.config.PLVLiveSDKConfig
import com.easefun.polyv.livecommon.module.config.PLVLiveScene
import com.plv.livescenes.config.PLVLiveChannelType
import com.plv.livescenes.feature.login.IPLVSceneLoginManager
import com.plv.livescenes.feature.login.PLVLiveLoginResult
import com.plv.livescenes.feature.login.PLVSceneLoginManager
import com.plv.livescenes.model.PLVLiveClassDetailVO
import kotlinx.coroutines.CompletableDeferred
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

actual class PlvManager private actual constructor() {
    private val loginManager = PLVSceneLoginManager()

    actual companion object {
        private var _instance: PlvManager? = null
        actual val instance: PlvManager
            get() = _instance ?: PlvManager().also { _instance = it }
    }

    private var channelType: PLVLiveChannelType? = null
    actual fun init(context: PlatformContext) {
        //初始化登录管理器
        try {
            PLVLiveSDKConfig.init(
                PLVLiveSDKConfig.Parameter(context.applicationContext as Application) //sdk初始化所需参数
                    .isOpenDebugLog(false) //是否打开调试日志
//                    .isOpenDebugLog(BuildConfig.DEBUG) //是否打开调试日志
                    .isEnableHttpDns(false) //是否使用httpdns
            )
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    actual fun isLogin(): Boolean {
        return channelType != null
    }

    actual suspend fun login(
        context: PlatformContext,
        appId: String,
        appSecret: String,
        userId: String,
        channelId: String,
        chatUserId: String,
        nickName: String,
        avatar: String
    ): Pair<Boolean, String> {
        return withContext(Dispatchers.IO) {
            val completer = CompletableDeferred<Pair<Boolean, String>>()
            loginManager.loginLiveNew(
                appId,
                appSecret,
                userId,
                channelId,
                object :
                    IPLVSceneLoginManager.OnLoginListener<PLVLiveLoginResult> {
                    override fun onLoginSuccess(result: PLVLiveLoginResult?) {
                        println("登录成功${result ?: "不成功?????"}")
                        result ?: return
                        PLVLiveChannelConfigFiller.setupAccount(userId, appId, appSecret)
                        val channelType: PLVLiveChannelType = result.channelTypeNew
                        this@PlvManager.channelType = channelType
                        if (PLVLiveScene.isCloudClassSceneSupportType(channelType)) {
                            val launchResult = PLVLCCloudClassActivity.launchLive(
                                context as Activity, channelId,
                                channelType,
                                chatUserId,
                                nickName,
                                avatar,
                                PLVLiveClassDetailVO.LangType.LANG_TYPE_ZH_CN
                            )
                            if (!launchResult.isSuccess) {
                                completer.complete(false to launchResult.errorMessage)
                            } else {
                                completer.complete(true to "")
                            }
                        } else {
                            completer.complete(
                                false to
                                        context.getString(com.easefun.polyv.livecommon.R.string.plv_scene_login_toast_cloudclass_no_support_type)
                            )
                        }
                    }

                    override fun onLoginFailed(
                        p0: String?,
                        p1: Throwable?
                    ) {
                        this@PlvManager.channelType = null
                        completer.complete(false to (p0 ?: "登录失败"))
                    }
                }
            )
            return@withContext completer.await()
        }
    }
}