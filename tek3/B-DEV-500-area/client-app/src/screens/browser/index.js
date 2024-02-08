import React from 'react';
import WebView from 'react-native-webview';
import {Toast} from '../../components/Toast';
import {postApi} from '../../api';
import {getItem, getParams} from '../../data';
import {NativeEvent} from 'react-native-reanimated/lib/types';
import CookieManager from '@react-native-cookies/cookies';

class BrowserScreen extends React.Component {
  render() {
    const {route, navigation} = this.props;
    return (
      <WebView
        source={{uri: route.params.url}}
        onError={e => this.handleEvent(e.nativeEvent, navigation, route)}
        onLoad={e => this.handleEvent(e.nativeEvent, navigation, route)}
      />
    );
  }
  postParams = (api, params, navigation) => {
    postApi(api, params)
      .then(() => console.log(`${api} added`))
      .catch(e => {
        console.log(e);
        Toast('Error connecting to API');
      });
    navigation.goBack();
  };
  handleEvent = async (event: NativeEvent, navigation, route) => {
    const {url} = event;
    console.log(event);
    if (
      url.startsWith('http://localhost:8081/connect-api/') ||
      url.startsWith(`${await getItem('@ip')}:8081/connect-api/`)
    ) {
      const params = getParams(url);
      this.postParams(route.params.api, params, navigation);
    } else if (url.startsWith('https://intra.epitech.eu/')) {
      CookieManager.get('https://intra.epitech.eu/')
        .then(cookie => {
          console.log(cookie.user);
          const params = {user_cookie: cookie.user.value};
          this.postParams(route.params.api, params, navigation);
        })
        .catch(e => console.log(e));
    }
  };
}
export default BrowserScreen;
