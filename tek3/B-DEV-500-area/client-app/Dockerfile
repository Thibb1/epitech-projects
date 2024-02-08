# syntax=docker/dockerfile:1

FROM reactnativecommunity/react-native-android:latest
ENV PATH /opt/gradle/bin:/app/node_modules/.bin:$PATH
WORKDIR /app
COPY package.json yarn.lock ./
RUN yarn install
COPY . .
RUN react-native bundle \
    --dev true \
    --platform android \
    --entry-file index.js \
    --bundle-output ./android/app/src/main/assets/index.android.bundle \
    --assets-dest ./android/app/src/main/res
RUN cd android && ./gradlew -s assembleDebug
RUN mkdir /build
ENTRYPOINT cp /app/android/app/build/outputs/apk/debug/app-debug.apk /build/base.apk