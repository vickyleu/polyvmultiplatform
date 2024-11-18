#!/bin/bash

WORKSPACE_NAME="./fakePod/iosApp.xcworkspace"

# Cleanup
rm -rf fakePod/build


if [ $? -ne 0 ]; then
    echo "pod install failed. Exiting..."
    exit 1
fi

build_xcframework() {
    # Build for iOS Device
    xcodebuild archive \
      -workspace $WORKSPACE_NAME \
      -scheme $1 \
      -destination "generic/platform=iOS Simulator" \
      -configuration Release only_active_arch=no \
      -sdk iphoneos \
      -archivePath fakePod/build/ios_devices.xcarchive \
      SKIP_INSTALL=NO \
      BUILD_LIBRARIES_FOR_DISTRIBUTION=YES \
      OTHER_SWIFT_FLAGS="-Xfrontend -module-interface-preserve-types-as-written"

    if [ $? -ne 0 ]; then
        echo "Build $1 for iOS Device failed. Exiting..."
        exit 1
    fi

    # Build for iOS Simulator
    xcodebuild archive \
      -workspace $WORKSPACE_NAME \
      -scheme $1 \
      -destination "generic/platform=iOS" \
      -configuration Release only_active_arch=no \
      -sdk iphonesimulator \
      -archivePath fakePod/build/ios_simulator.xcarchive \
      SKIP_INSTALL=NO \
      BUILD_LIBRARIES_FOR_DISTRIBUTION=YES \
      OTHER_SWIFT_FLAGS="-Xfrontend -module-interface-preserve-types-as-written"


    if [ $? -ne 0 ]; then
        echo "Build $1 for iOS Simulator failed. Exiting..."
        exit 1
    fi

    # Create XCFramework
    xcodebuild -create-xcframework \
      -framework fakePod/build/ios_devices.xcarchive/Products/Library/Frameworks/$1.framework \
      -framework fakePod/build/ios_simulator.xcarchive/Products/Library/Frameworks/$1.framework \
      -output fakePod/build/$1.xcframework

    # Remove archives
    rm -rf fakePod/build/ios_devices.xcarchive
    rm -rf fakePod/build/ios_simulator.xcarchive

    if [ $? -ne 0 ]; then
        echo "Create $1 XCFramework failed. Exiting..."
        exit 1
    fi
}

build_xcframework polyv_ui


if [ $? -ne 0 ]; then
    echo "Build for iOS Simulator failed. Exiting..."
    exit 1
fi
