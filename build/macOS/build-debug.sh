THIS_PATH=$(dirname $0)
xcodebuild -project "${THIS_PATH}/SLib.xcodeproj" -scheme SLib -configuration Debug -derivedDataPath "${THIS_PATH}/build"