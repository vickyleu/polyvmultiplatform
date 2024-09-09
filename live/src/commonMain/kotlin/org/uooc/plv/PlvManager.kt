package org.uooc.plv

import coil3.PlatformContext

expect class PlvManager private constructor()  {

    companion object {
        val instance: PlvManager
    }
    fun isLogin(): Boolean

    fun init(context: PlatformContext)

    suspend fun login(
        context: PlatformContext,
        appId: String,
        appSecret: String,
        userId: String,
        channelId: String,
        chatUserId: String,
        nickName: String,
        avatar: String
    ):Pair<Boolean, String>
}