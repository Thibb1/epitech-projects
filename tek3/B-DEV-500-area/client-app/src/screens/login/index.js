import React, {useRef, useState} from 'react';
import {
  Button,
  Keyboard,
  Modal,
  StyleSheet,
  Text,
  TextInput,
  View,
} from 'react-native';
import PressableIcon from '../../components/PressableIcon';
import {faGoogle} from '@fortawesome/free-brands-svg-icons';
import Gradient from '../../components/Gradient';
import DefaultPressable from '../../components/DefaultPressable';
import {setToken, userExist, userLogin} from '../../api';
import {Toast} from '../../components/Toast';
import Animated, {
  BounceIn,
  BounceInUp,
  BounceOut,
} from 'react-native-reanimated';
import {AnimatedGradient} from '../../utils/animated';
import WebView from 'react-native-webview';
import {getItem, getParams} from '../../data';

const LoginScreen = ({handleLogin}) => {
  const [login, setLogin] = useState(false);
  const [username, onChangeUser] = useState('');
  const [password, onChangePassword] = useState('');
  const [modal, setModal] = useState(false);
  const [ip, setIp] = useState('');
  const [url, setUrl] = useState('');
  const ref_password = useRef();
  getItem('@ip').then(setIp);
  const handleBrowserEvent = async ({nativeEvent}) => {
    console.log('hanlde', nativeEvent.url);
    if (nativeEvent.url.startsWith(ip + ':8081/login')) {
      setModal(false);
      const {jwt} = getParams(nativeEvent.url);
      setToken(jwt).then(handleLogin);
    } else if (nativeEvent.url.startsWith('http://localhost')) {
      const newUrl = nativeEvent.url.replace('http://localhost', ip);
      setUrl(newUrl);
    }
  };
  return (
    <AnimatedGradient>
      <Modal
        transparent={true}
        visible={modal}
        onRequestClose={() => setModal(false)}>
        <Animated.View
          style={styles.modalBox}
          entering={BounceInUp.delay(100).duration(500)}>
          <WebView
            source={{uri: url}}
            userAgent={'Mozilla/5.0 Mobile Safari/605.1.15'}
            onLoad={handleBrowserEvent}
            onError={handleBrowserEvent}
          />
          <Button title="Close" onPress={() => setModal(false)} />
        </Animated.View>
      </Modal>
      <Animated.View
        style={styles.loginBox}
        entering={BounceIn}
        exiting={BounceOut}>
        <Text style={styles.loginText}>{login ? 'Login' : 'Register'}</Text>
        <View style={styles.loginBoxBtn}>
          <TextInput
            placeholderTextColor="gray"
            placeholder="Username"
            style={styles.loginInput}
            autoComplete="username"
            autoCorrect={false}
            onChangeText={onChangeUser}
            value={username}
            autoFocus={true}
            onKeyPress={() => {
              userExist(username)
                .then(res => setLogin(res.data))
                .catch(e => console.log(e));
            }}
            blurOnSubmit={false}
            onSubmitEditing={() => ref_password.current.focus()}
            maxLength={20}
            returnKeyType="go"
          />
          <TextInput
            ref={ref_password}
            placeholderTextColor="gray"
            placeholder="Password"
            style={styles.loginInput}
            autoComplete="password"
            secureTextEntry={true}
            value={password}
            onChangeText={onChangePassword}
            onSubmitEditing={() => {
              if (username.length > 0 && password.length > 0) {
                userLogin(username, password)
                  .then(() => handleLogin())
                  .catch(e => {
                    console.log(e.message);
                    Toast(`Error: Couldn't ${login ? 'login' : 'register'}`);
                  });
              }
            }}
            maxLength={20}
          />
          <View style={styles.loginSeparator}>
            <View style={styles.loginSeparatorLine} />
            <Text style={styles.loginSeparatorText}>or</Text>
            <View style={styles.loginSeparatorLine} />
          </View>
          <View style={styles.loginBoxIcons}>
            <PressableIcon
              icon={faGoogle}
              onPress={() => {
                setUrl(ip + ':8080/google');
                setModal(true);
              }}
            />
          </View>
        </View>
        <Gradient style={styles.loginBtn}>
          <DefaultPressable
            width={'100%'}
            height={'100%'}
            radius={50}
            disabled={username.length < 1 || password.length < 1}
            onPress={() => {
              Keyboard.dismiss();
              userLogin(username, password)
                .then(() => handleLogin())
                .catch(e => {
                  console.log(e.message);
                  Toast(`Error: Couldn't ${login ? 'login' : 'register'}`);
                });
            }}>
            <Text style={styles.loginBtnText}>
              {login ? 'Login' : 'Register'}
            </Text>
          </DefaultPressable>
        </Gradient>
      </Animated.View>
    </AnimatedGradient>
  );
};

const styles = StyleSheet.create({
  loginBtn: {
    flex: 0,
    height: '7%',
    backgroundColor: 'red',
    shadowColor: '#000',
    shadowRadius: 20,
    shadowOffset: {width: 0, height: 3},
    shadowOpacity: 0.3,
    elevation: 7,
    width: '50%',
    borderRadius: 50,
  },
  loginBtnText: {
    textAlignVertical: 'center',
    color: 'white',
    fontSize: 15,
  },
  loginBox: {
    display: 'flex',
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'white',
    width: '75%',
    height: 500,
    borderRadius: 20,
    shadowColor: '#000',
    shadowRadius: 20,
    shadowOffset: {width: 0, height: 3},
    shadowOpacity: 0.3,
    elevation: 7,
  },
  loginBoxBtn: {
    display: 'flex',
    justifyContent: 'space-evenly',
    alignItems: 'center',
    flexDirection: 'column',
    width: '80%',
    height: '58%',
  },
  loginText: {
    color: 'black',
    fontSize: 30,
  },
  loginInput: {
    color: 'black',
    width: '80%',
    borderRadius: 50,
    borderWidth: 1,
    paddingLeft: 20,
    fontSize: 16,
  },
  loginSeparator: {
    display: 'flex',
    justifyContent: 'space-evenly',
    alignItems: 'center',
    flexDirection: 'row',
  },
  loginSeparatorLine: {
    height: 1,
    width: '25%',
    backgroundColor: 'black',
    marginLeft: 10,
    marginRight: 10,
  },
  loginSeparatorText: {
    color: 'black',
  },
  loginBoxIcons: {
    justifyContent: 'space-evenly',
    alignItems: 'center',
    flexDirection: 'row',
    width: '100%',
  },
  modalBox: {
    display: 'flex',
    justifyContent: 'center',
    alignSelf: 'center',
    backgroundColor: 'red',
    width: '95%',
    height: '95%',
    marginTop: 20,
    borderRadius: 20,
    overflow: 'hidden',
    shadowColor: '#000',
    shadowRadius: 20,
    shadowOffset: {width: 0, height: 3},
    shadowOpacity: 0.3,
    elevation: 7,
  },
});

export default LoginScreen;
