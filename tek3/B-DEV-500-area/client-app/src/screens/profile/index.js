import React, {useEffect, useState} from 'react';
import DefaultBox from '../../components/DefaultBox';
import DefaultView from '../../components/DefaultView';
import PressableIcon from '../../components/PressableIcon';
import {faRightFromBracket} from '@fortawesome/free-solid-svg-icons/faRightFromBracket';
import {
  faReddit,
  faSpotify,
  faTwitch,
  faTwitter,
} from '@fortawesome/free-brands-svg-icons';
import {StyleSheet, Text} from 'react-native';
import {removeItem} from '../../data';
import {connectApi, deleteApi, hasApi} from '../../api';
import DefaultPressable from '../../components/DefaultPressable';
import {SvgXml} from 'react-native-svg';

const ProfileScreen = ({handleLogin, navigation}) => {
  const [twitter, setTwitter] = useState(false);
  const [reddit, setReddit] = useState(false);
  const [twitch, setTwitch] = useState(false);
  const [epitech, setEpitech] = useState(false);
  const [spotify, setSpotify] = useState(false);
  const xml = `
  <svg viewBox="0 0 290.000000 800.000000">
  <g transform="translate(0.000000,512.000000) scale(0.0600000,-0.0600000)"
  fill="#000000" stroke="none">
    <path d="M623 5105 c-130 -28 -213 -86 -254 -178 l-24 -52 -5 -1021 -5 -1021 -40 -79 c-46 -90 -118 -157 -191 -176 -24 -7 -44 -15 -44 -18 0 -3 22 -13 48 -22 66 -24 133 -77 170 -135 64 -99 62 -68 62 -1143 0 -1054 -1 -1031 53 -1110 34 -51 100 -97 175 -121 58 -19 95 -23 280 -27 l212 -4 0 86 0 86 -93 0 c-165 0 -239 39 -274 143 -16 47 -18 138 -23 1002 l-5 950 -27 57 c-47 101 -144 187 -243 217 -22 7 -47 15 -55 18 -8 3 9 11 38 19 109 29 210 115 260 222 l27 57 5 945 c7 1047 5 1018 71 1086 44 46 109 64 226 64 l93 0 0 85 0 85 -187 -1 c-117 0 -211 -6 -250 -14z" />
    <path d="M4740 5035 l0 -85 95 0 c147 0 212 -29 258 -115 22 -40 22 -42 27 -995 4 -644 9 -965 17 -985 16 -47 53 -116 81 -152 34 -46 132 -109 192 -124 27 -7 50 -15 50 -18 0 -3 -26 -14 -58 -23 -114 -33 -212 -130 -258 -253 -18 -47 -19 -104 -24 -1005 -5 -865 -7 -958 -22 -990 -40 -85 -116 -120 -263 -120 l-95 0 0 -85 0 -85 174 0 c178 0 287 13 360 44 78 33 140 98 169 178 8 24 13 309 17 1048 l5 1015 24 59 c15 38 42 77 71 107 48 47 134 99 167 99 26 0 5 14 -52 35 -70 26 -155 112 -186 190 l-24 60 -5 1020 -5 1020 -28 57 c-70 143 -190 188 -504 188 l-183 0 0 -85z" />
    <path d="M2245 4083 c-392 -83 -655 -453 -655 -922 0 -193 71 -445 162 -573 19 -28 19 -28 0 -55 -32 -46 -89 -164 -111 -233 -31 -93 -51 -230 -51 -345 0 -470 261 -835 655 -916 84 -17 153 -19 1028 -19 l937 0 0 330 0 330 -843 0 c-914 0 -900 -1 -972 54 -18 14 -46 52 -62 83 -24 50 -28 70 -28 143 1 94 23 161 73 213 57 60 4 57 957 57 l875 0 0 330 0 330 -840 0 c-546 0 -856 4 -888 10 -64 14 -114 57 -149 128 -24 49 -28 69 -28 142 1 127 48 216 138 259 43 21 53 21 905 21 l862 0 0 325 0 325 -947 -1 c-800 -1 -959 -3 -1018 -16z" />
  </g>
</svg>
`;
  const updateApi = (api: string, setter) => {
    hasApi(api).then(r => setter(r));
  };
  useEffect(() => {
    updateApi('twitter', setTwitter);
    updateApi('reddit', setReddit);
    updateApi('twitch', setTwitch);
    updateApi('epitech', setEpitech);
    updateApi('spotify', setSpotify);
    return navigation.addListener('state', () => {
      setTimeout(() => {
        updateApi('twitter', setTwitter);
        updateApi('spotify', setSpotify);
        updateApi('reddit', setReddit);
        updateApi('twitch', setTwitch);
        updateApi('epitech', setEpitech);
      }, 1000);
    });
  }, [navigation]);
  return (
    <>
      <DefaultView>
        <Text style={styles.header1}>Connect to your API's</Text>
        <Text style={styles.header2}>
          By doing this, you consent the usage of your data
        </Text>
        <DefaultBox
          padding={0}
          style={{backgroundColor: twitter ? 'lightgreen' : 'lightgray'}}>
          <PressableIcon
            icon={faTwitter}
            size={80}
            style={styles.apiBtn}
            onPress={() => {
              if (twitter) {
                deleteApi('twitter').then(() =>
                  updateApi('twitter', setTwitter),
                );
              } else {
                connectApi('twitter', navigation).then();
              }
            }}
          />
        </DefaultBox>
        <DefaultBox
          padding={0}
          style={{backgroundColor: reddit ? 'lightgreen' : 'lightgray'}}>
          <PressableIcon
            icon={faReddit}
            size={80}
            style={styles.apiBtn}
            onPress={() => {
              if (reddit) {
                deleteApi('reddit').then(() => updateApi('reddit', setReddit));
              } else {
                connectApi('reddit', navigation).then();
              }
            }}
          />
        </DefaultBox>
        <DefaultBox
          padding={0}
          style={{backgroundColor: twitch ? 'lightgreen' : 'lightgray'}}>
          <PressableIcon
            icon={faTwitch}
            size={80}
            style={styles.apiBtn}
            onPress={() => {
              if (twitch) {
                deleteApi('twitch').then(() => updateApi('twitch', setTwitch));
              } else {
                connectApi('twitch', navigation).then();
              }
            }}
          />
        </DefaultBox>
        <DefaultBox
          padding={0}
          style={{backgroundColor: epitech ? 'lightgreen' : 'lightgray'}}>
          <DefaultPressable
            style={styles.apiBtn}
            onPress={() => {
              if (epitech) {
                deleteApi('epitech').then(() =>
                  updateApi('epitech', setEpitech),
                );
              } else {
                connectApi('epitech', navigation).then();
              }
            }}>
            <SvgXml xml={xml} width="100%" height="100%" />
          </DefaultPressable>
        </DefaultBox>
        <DefaultBox
          padding={0}
          style={{backgroundColor: spotify ? 'lightgreen' : 'lightgray'}}>
          <PressableIcon
            icon={faSpotify}
            size={80}
            style={styles.apiBtn}
            onPress={() => {
              if (spotify) {
                deleteApi('spotify').then(() =>
                  updateApi('spotify', setSpotify),
                );
              } else {
                connectApi('spotify', navigation).then();
              }
            }}
          />
        </DefaultBox>
        <DefaultBox padding={0}>
          <PressableIcon
            icon={faRightFromBracket}
            size={80}
            style={styles.logoutBtn}
            onPress={() => {
              removeItem('@token').then();
              handleLogin();
            }}
          />
        </DefaultBox>
      </DefaultView>
    </>
  );
};

const styles = StyleSheet.create({
  apiBtn: {width: '100%', height: '100%', borderRadius: 40},
  logoutBtn: {width: '100%', height: '100%', borderRadius: 40},
  header1: {color: 'black', fontSize: 16},
  header2: {color: 'black', fontSize: 16, fontWeight: 'bold'},
});

export default ProfileScreen;
