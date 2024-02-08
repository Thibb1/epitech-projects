import React from 'react';
import {ScrollView, StyleSheet} from 'react-native';
import Animated, {BounceInUp, ZoomOutDown} from 'react-native-reanimated';

function DefaultView(props) {
  return (
    <ScrollView style={styles.mainScroll}>
      <Animated.View
        style={styles.mainView}
        entering={BounceInUp.delay(100).duration(500)}
        exiting={ZoomOutDown}>
        {props.children}
      </Animated.View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  mainScroll: {
    flex: 1,
  },
  mainView: {
    flex: 1,
    margin: '5%',
    flexDirection: 'column',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
export default DefaultView;
