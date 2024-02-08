# Run guide

Start react-native server `npm run start`


Connect an android device and run `export ANDROID_HOME=~/Android/sdk && npm run android` in a separate shell

Reload by hitting `r` on the first shell

# Build guide

Install [Android Studio]() and install android SDK to `~/Android/sdk`

Build Release version:
```
cd client-app
react-native bundle --dev false --platform android --entry-file index.js --bundle-output ./android/app/src/main/assets/index.android.bundle --assets-dest ./android/app/src/main/res
cd android
export ANDROID_HOME=~/Android/sdk && ./gradlew assembleRelease
cp app/build/outputs/apk/release/app-release.apk ../../client/public/base.apk
```

Build Debug version:
```
cd client-app
react-native bundle --dev true --platform android --entry-file index.js --bundle-output ./android/app/src/main/assets/index.android.bundle --assets-dest ./android/app/src/main/res
cd android
export ANDROID_HOME=~/Android/sdk && ./gradlew assembleDebug
rm -r app/src/main/res/drawable-*
cp app/build/outputs/apk/debug/app-debug.apk ../../client/public/base-debug.apk
```