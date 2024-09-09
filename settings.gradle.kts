@file:Suppress("UnstableApiUsage")

rootProject.name = "polyvmultiplatform"
enableFeaturePreview("TYPESAFE_PROJECT_ACCESSORS")

pluginManagement {
    repositories.apply {
        removeAll(this)
    }
    dependencyResolutionManagement.repositories.apply {
        removeAll(this)
    }
    listOf(repositories, dependencyResolutionManagement.repositories).forEach {
        it.apply {


            gradlePluginPortal {
                content {
                    excludeGroupByRegex("org.jogamp.*")
                    excludeGroupByRegex("com.vickyleu.*")
                    excludeGroupByRegex("androidx.databinding.*")
                    // 避免无效请求,加快gradle 同步依赖的速度
                    excludeGroupByRegex("com.github.(?!johnrengelman).*")
                }
            }


            google {
                content {
                    excludeGroupByRegex("org.jogamp.*")
                    includeGroupByRegex(".*google.*")
                    includeGroupByRegex(".*android.*")
                    excludeGroupByRegex("com.vickyleu.*")
                    excludeGroupByRegex("com.github.*")
                }
            }
            mavenCentral {
                content {
                    excludeGroupByRegex("org.jogamp.*")
                    excludeGroupByRegex("com.vickyleu.*")
                    excludeGroupByRegex("com.android.tools.*")
                    excludeGroupByRegex("androidx.compose.*")
                    excludeGroupByRegex("com.github.(?!johnrengelman|oshi).*")
                }
            }
            maven(url = "https://androidx.dev/storage/compose-compiler/repository") {
                content {
                    excludeGroupByRegex("org.jogamp.*")
                    excludeGroupByRegex("com.vickyleu.*")
                    excludeGroupByRegex("com.github.*")
                }
            }
            maven(url = "https://maven.pkg.jetbrains.space/public/p/compose/dev") {
                content {
                    excludeGroupByRegex("org.jogamp.*")
                    excludeGroupByRegex("com.vickyleu.*")
                    excludeGroupByRegex("com.github.*")
                }
            }


            maven(url = "https://maven.pkg.jetbrains.space/kotlin/p/kotlin/dev")
        }
    }
}

plugins {
    id("org.gradle.toolchains.foojay-resolver-convention") version "0.7.0"
}


dependencyResolutionManagement {
    //FAIL_ON_PROJECT_REPOS
//    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositoriesMode.set(RepositoriesMode.PREFER_SETTINGS)

    repositories {
        mavenCentral()
        google()
        maven(url = "https://jitpack.io")
        maven{
            setUrl("http://maven.aliyun.com/nexus/content/repositories/releases/")
            isAllowInsecureProtocol = true
        }
        maven(url = "https://maven.aliyun.com/repository/public")
        // 保利威阿里云效
        // 保利威阿里云效
        maven {
            credentials {
                username = "609cc5623a10edbf36da9615"
                password = "EbkbzTNHRJ=P"
            }
            setUrl("https://packages.aliyun.com/maven/repository/2102846-release-8EVsoM/")
        }
        // workaround for https://youtrack.jetbrains.com/issue/KT-51379
        maven {
            setUrl("https://repo.maven.apache.org/maven2")
        }
        maven {
            setUrl("https://repo1.maven.org/maven2/")
        }

        maven {
            setUrl("https://maven.aliyun.com/nexus/content/repositories/releases/")
        }
        maven(url = "https://artifact.bytedance.com/repository/Volcengine/")
        maven {
            setUrl("https://maven.pkg.jetbrains.space/public/p/compose/dev")
        }
        ivy {
            name = "Node.js"
            setUrl("https://nodejs.org/dist")
            patternLayout {
                artifact("v[revision]/[artifact](-v[revision]-[classifier]).[ext]")
            }
            metadataSources {
                artifact()
            }
            content {
                excludeGroupByRegex("com.finogeeks.*")
                excludeGroupByRegex("org.jogamp.*")
                includeModule("org.nodejs", "node")
            }
            isAllowInsecureProtocol = false
        }




        maven {
            setUrl("https://dl.bintray.com/kotlin/kotlin-dev")
        }
        maven {
            setUrl("https://dl.bintray.com/kotlin/kotlin-eap")
        }

        maven("https://maven.pkg.jetbrains.space/kotlin/p/wasm/experimental") {
        }

        maven(url = "https://maven.pkg.jetbrains.space/kotlin/p/kotlin/dev")
        val properties = java.util.Properties().apply {
            runCatching { rootProject.projectDir.resolve("local.properties") }
                .getOrNull()
                .takeIf { it?.exists() ?: false }
                ?.reader()
                ?.use(::load)
        }
        val environment: Map<String, String?> = System.getenv()
        extra["githubToken"] = properties["github.token"] as? String
            ?: environment["GITHUB_TOKEN"] ?: ""
        val repositories = listOf("compose-sonner")
        repositories.forEach {
            maven {
                url = uri("https://maven.pkg.github.com/vickyleu/$it")
                credentials {
                    username = "vickyleu"
                    password = extra["githubToken"]?.toString()
                }
                content {
                    excludeGroupByRegex("com.finogeeks.*")
                    excludeGroupByRegex("org.jogamp.*")
                    excludeGroupByRegex("org.jetbrains.compose.*")
                    excludeGroupByRegex("(?!com|cn).github.(?!vickyleu).*")
                }
            }
        }
    }
}


include(":live")

include(":polyvLiveCloudClassScene").apply {
    project(":polyvLiveCloudClassScene").projectDir = file("./polyv/android/polyvLiveCloudClassScene")
}
include(":polyvLiveCommonModul").apply {
    project(":polyvLiveCommonModul").projectDir = file("./polyv/android/polyvLiveCommonModul")
}
