// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "VickyLeuKmpPolyv",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "VickyLeuKmpPolyv",
            targets: ["VickyLeuKmpPolyv"]
        )
    ],
    targets: [
        .target(
            name: "VickyLeuKmpPolyv",
            dependencies: [
                .target(name: "polyv")
            ],
            path: "Sources/VickyLeuKmpPolyv",
            linkerSettings: [
                .linkedFramework("UIKit"),
                .linkedFramework("Foundation"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("CoreMedia"),
                .linkedFramework("CoreVideo"),
                .linkedFramework("VideoToolbox"),
                .linkedFramework("AudioToolbox"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("CFNetwork"),
                .linkedFramework("WebKit"),
                .linkedLibrary("c++"),
                .linkedLibrary("z"),
                .linkedLibrary("resolv"),
                .linkedLibrary("sqlite3"),
                .unsafeFlags(["-weak_framework", "PhotosUI"])
            ]
        ),
        .binaryTarget(
            name: "polyv",
            path: "polyv/polyv.xcframework"
        )
    ]
)
