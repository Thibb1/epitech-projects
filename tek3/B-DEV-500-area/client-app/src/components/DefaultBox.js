import React from 'react';
import {StyleSheet, View} from 'react-native';

interface DefaultBoxProps {
  padding?: number;
}

function DefaultBox(props: React.HTMLProps<DefaultBoxProps>) {
  const {padding} = props;
  return (
    <View style={[styles.defaultBox, {padding: padding ?? 20}, props.style]}>
      {props.children}
    </View>
  );
}

const styles = StyleSheet.create({
  defaultBox: {
    justifyContent: 'space-evenly',
    flexDirection: 'row',
    borderRadius: 40,
    margin: 10,
    width: '100%',
    height: 170,
    flexGrow: 1,
    backgroundColor: 'lightgray',
    shadowRadius: 20,
    shadowOffset: {width: 0, height: 3},
    shadowOpacity: 0.3,
    elevation: 7,
  },
});
export default DefaultBox;
