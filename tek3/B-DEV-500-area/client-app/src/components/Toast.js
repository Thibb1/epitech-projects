import React from 'react';
import ToastAndroid from 'react-native/Libraries/Components/ToastAndroid/ToastAndroid';

export function Toast(message: any) {
  ToastAndroid.showWithGravity(
    message,
    ToastAndroid.SHORT,
    ToastAndroid.CENTER,
  );
}
