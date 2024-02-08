import React from 'react';
import {Pressable} from 'react-native';

interface DefaultPressableProps {
  onPress?: null;
  width?: number | string;
  height?: number | string;
  radius?: number;
}

function DefaultPressable(props: React.HTMLProps<DefaultPressableProps>) {
  const {onPress, width, height, radius} = props;
  return (
    <Pressable
      style={({pressed}) => [
        {
          backgroundColor:
            props.disabled || pressed ? 'rgba(0, 0, 0, 0.4)' : 'transparent',
          borderRadius: radius || 5,
          justifyContent: 'space-evenly',
          alignItems: 'center',
          flexDirection: 'row',
          padding: 5,
          width: width || 'auto',
          height: height || 'auto',
        },
        props.style,
      ]}
      onPress={onPress}
      disabled={props.disabled}>
      {props.children}
    </Pressable>
  );
}
export default DefaultPressable;
