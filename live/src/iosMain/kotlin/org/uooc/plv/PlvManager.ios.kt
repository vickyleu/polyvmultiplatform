package org.uooc.plv

import coil3.PlatformContext
import kotlinx.coroutines.CompletableDeferred
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.IO
import kotlinx.coroutines.withContext
import platform.UIKit.UIApplication
import platform.UIKit.UINavigationController
import platform.UIKit.addChildViewController
import what.the.fuck.polyv.PLVChannelTypeAlone
import what.the.fuck.polyv.PLVChannelTypePPT
import what.the.fuck.polyv.PLVLCCloudClassViewController
import what.the.fuck.polyv.PLVMultiLanguageManager
import what.the.fuck.polyv.PLVMultiLanguageModeZH
import what.the.fuck.polyv.PLVRoomLoginClient

actual class PlvManager private actual constructor() {
    actual companion object {
        private var _instance: PlvManager? = null
        actual val instance: PlvManager
            get() = _instance ?: PlvManager().also { _instance = it }
    }

    actual fun init(context: PlatformContext) {
        // HttpDNS默认开启，如需关闭，解开注释
//    [PLVLiveVideoConfig sharedInstance].enableHttpDNS = NO;
        // 如需启用IPV6，解开注释，启用IPV6之后，将自动选择IP，取消HttpDNS
//    [PLVLiveVideoConfig sharedInstance].enableIPV6 = YES;
//       PLVLiveVideoConfig
    }

    private var isLogged=false
    actual fun isLogin(): Boolean {
        return isLogged
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
            withContext(Dispatchers.Main){
                PLVMultiLanguageManager.sharedManager().updateLanguage(PLVMultiLanguageModeZH)
                withContext(Dispatchers.IO) {
                    PLVRoomLoginClient.loginLiveRoomWithChannelType(
                        PLVChannelTypePPT or PLVChannelTypeAlone,
                        channelId = channelId,
                        userId = userId,
                        appId = appId,
                        appSecret = appSecret,
                        roomUser = { roomUser ->
                            roomUser?.apply {
                                viewerId = chatUserId
                                viewerName = nickName
                                viewerAvatar = avatar
                            }
                        },
                        completion = {
                            isLogged = true
                            UIApplication.sharedApplication.keyWindow?.rootViewController?.apply {
                                val controller = PLVLCCloudClassViewController()
                                val navigationController =  (this as? UINavigationController)
                                if (navigationController != null) {
                                    navigationController.pushViewController(controller, true)
                                    completer.complete(true to "直播登录成功")
                                }else{
                                    this.presentViewController(controller, true) {
                                        completer.complete(true to "直播登录成功")
                                    }
                                }
                            } ?: run {
                                completer.complete(false to "直播登录失败")
                            }
                        },
                        failure = { err ->
                            isLogged = false
                            completer.complete(false to (err ?: "直播登录失败"))
                        }
                    )
                }
            }

            return@withContext completer.await()
        }
    }
}