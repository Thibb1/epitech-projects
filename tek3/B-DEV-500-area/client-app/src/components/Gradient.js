import React from 'react';
import LinearGradient from 'react-native-linear-gradient';
import {StyleSheet} from 'react-native';

function Gradient(props) {
  return (
    <LinearGradient
      useAngle={true}
      angle={-45}
      colors={colors.background}
      style={[styles.home, props.style]}>
      {props.children}
    </LinearGradient>
  );
}

const colors = {
  background: [
    'rgb(3, 217, 223)',
    'rgb(79, 151, 232)',
    'rgb(140, 98, 241)',
    'rgb(250, 2, 255)',
  ],
};

const styles = StyleSheet.create({
  home: {
    margin: 0,
    padding: 0,
    maxWidth: '100%',
    flex: 1,
    display: 'flex',
    justifyContent: 'center',
    alignItems: 'center',
    flexDirection: 'column',
  },
});

export default Gradient;
