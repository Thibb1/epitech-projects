import {Button, Modal, StyleSheet, Text, TextInput, View} from 'react-native';
import Animated, {BounceInUp} from 'react-native-reanimated';
import React from 'react';

function OptionModal(props: {
  visible: boolean,
  onCancel: () => void,
  currentItem: undefined,
  options: [],
  onSetOptions: () => void,
  onSubmit: () => void,
}) {
  function handleOptionInput(name, text) {
    const nextOptions = props.options.map(v => {
      if (v.name === name) {
        return {...v, value: text};
      } else {
        return v;
      }
    });
    props.onSetOptions(nextOptions);
  }
  return (
    <Modal
      transparent={true}
      visible={props.visible}
      onRequestClose={props.onCancel}>
      <Animated.View
        style={styles.modalBox}
        entering={BounceInUp.delay(100).duration(500)}>
        <View>
          <Text style={styles.optionHeaderText}>
            Options for {props.currentItem?.name}
          </Text>
          {props.options.map(item => {
            return (
              <View key={item.name} style={styles.optionPropBox}>
                <Text style={styles.optionTextId}>{item.name}</Text>
                <TextInput
                  placeholderTextColor="#65b9fd"
                  placeholder={item?.placeholder ?? '...'}
                  style={styles.optionTextInput}
                  autoComplete="off"
                  autoCapitalize="none"
                  keyboardType={item?.keyboard ?? 'default'}
                  autoCorrect={false}
                  onChangeText={text => {
                    handleOptionInput(item.name, text);
                  }}
                  value={item.value}
                  maxLength={20}
                />
              </View>
            );
          })}
        </View>
        <View style={styles.buttonsBox}>
          <View style={styles.buttonsStyle}>
            <Button title="Cancel" color="red" onPress={props.onCancel} />
          </View>
          <View style={styles.buttonsStyle}>
            <Button
              title="Submit"
              onPress={props.onSubmit}
              disabled={!props.options.every(e => e?.value?.length > 0)}
            />
          </View>
        </View>
      </Animated.View>
    </Modal>
  );
}

const styles = StyleSheet.create({
  optionHeaderText: {
    color: 'black',
    fontSize: 30,
    textAlign: 'center',
    borderBottomColor: 'black',
    borderBottomWidth: 1,
    marginBottom: 15,
  },
  modalBox: {
    margin: '5%',
    padding: '5%',
    display: 'flex',
    justifyContent: 'space-between',
    alignSelf: 'center',
    backgroundColor: 'white',
    width: '95%',
    minHeight: 400,
    borderRadius: 20,
    overflow: 'hidden',
    shadowColor: '#000',
    shadowRadius: 20,
    shadowOffset: {width: 0, height: 3},
    shadowOpacity: 0.3,
    elevation: 7,
    borderColor: 'black',
    borderWidth: 1,
  },
  optionPropBox: {
    marginTop: 8,
    backgroundColor: '#2196f3',
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    borderRadius: 10,
    overflow: 'hidden',
    elevation: 5,
  },
  optionTextId: {
    color: 'white',
    flex: 1,
    padding: 5,
    textAlign: 'center',
  },
  optionTextInput: {
    padding: 5,
    backgroundColor: 'rgb(255,244,244)',
    color: 'black',
    flex: 3,
    fontSize: 16,
    height: '100%',
  },
  buttonsBox: {
    marginTop: '2%',
    marginHorizontal: '10%',
    flexDirection: 'row',
    justifyContent: 'space-between',
  },
  buttonsStyle: {width: '40%'},
});
export default OptionModal;
