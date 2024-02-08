import React, {useEffect, useState} from 'react';
import {createNativeStackNavigator} from '@react-navigation/native-stack';
import SetServerScreen from '../screens/setserver';
import LoginScreen from '../screens/login';
import HomeScreen from '../screens/home';
import {NavigationContainer} from '@react-navigation/native';
import {createBottomTabNavigator} from '@react-navigation/bottom-tabs';
import {FontAwesomeIcon} from '@fortawesome/react-native-fontawesome';
import {faCirclePlus, faHome, faUser} from '@fortawesome/free-solid-svg-icons';
import ProfileScreen from '../screens/profile';
import AddScreen from '../screens/add';
import {checkToken, pingServer} from '../api';
import BrowserScreen from '../screens/browser';
import {Keyboard} from 'react-native';

const Stack = createNativeStackNavigator();
const Tab = createBottomTabNavigator();

const AppNavigation = () => {
  const [connected, setConnected] = useState(false);
  const handleLogin = async () => {
    await pingServer()
      .then(async () => {
        if ((await checkToken()) === true) {
          Keyboard.dismiss();
          setTimeout(() => {
            setConnected(true);
          }, 200);
        } else {
          setConnected(false);
        }
      })
      .catch(() => {
        console.log('No server connected');
        setConnected(false);
      });
  };
  function Profile() {
    return (
      <Stack.Navigator
        initialRouteName="base"
        screenOptions={{headerShown: false, unmountOnBlur: true}}>
        <Stack.Screen name="base">
          {props => <ProfileScreen handleLogin={handleLogin} {...props} />}
        </Stack.Screen>
        <Stack.Screen name="browser">
          {props => <BrowserScreen {...props} />}
        </Stack.Screen>
      </Stack.Navigator>
    );
  }
  useEffect(() => {
    setTimeout(() => {
      handleLogin().then();
    }, 200);
  }, []);

  return (
    <NavigationContainer>
      {connected ? (
        <>
          <Tab.Navigator
            initialRouteName="Server"
            screenOptions={{headerShown: false, unmountOnBlur: true}}>
            <Tab.Screen
              name="Home"
              options={{
                tabBarIcon: ({focused}) => (
                  <FontAwesomeIcon
                    icon={faHome}
                    color={focused ? 'blue' : 'black'}
                  />
                ),
              }}
              component={HomeScreen}
            />
            <Tab.Screen
              name="Add"
              options={{
                tabBarIcon: ({focused}) => (
                  <FontAwesomeIcon
                    icon={faCirclePlus}
                    color={focused ? 'blue' : 'black'}
                  />
                ),
              }}
              component={AddScreen}
            />
            <Tab.Screen
              name="Profile"
              options={{
                tabBarIcon: ({focused}) => (
                  <FontAwesomeIcon
                    icon={faUser}
                    color={focused ? 'blue' : 'black'}
                  />
                ),
              }}>
              {props => <Profile handleLogin={handleLogin} {...props} />}
            </Tab.Screen>
          </Tab.Navigator>
        </>
      ) : (
        <>
          <Stack.Navigator
            screenOptions={{headerShown: false, unmountOnBlur: true}}>
            <Stack.Screen name="Server" component={SetServerScreen} />
            <Stack.Screen name="Login">
              {props => <LoginScreen handleLogin={handleLogin} {...props} />}
            </Stack.Screen>
          </Stack.Navigator>
        </>
      )}
    </NavigationContainer>
  );
};

export default AppNavigation;
