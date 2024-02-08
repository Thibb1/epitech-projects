import React, {useEffect, useState} from 'react';
import {Image, StyleSheet, Text, View} from 'react-native';
import DefaultBox from '../../components/DefaultBox';
import DefaultView from '../../components/DefaultView';
import {
  faReddit,
  faSpotify,
  faTwitch,
  faTwitter,
} from '@fortawesome/free-brands-svg-icons';
import DefaultPressable from '../../components/DefaultPressable';
import {FontAwesomeIcon} from '@fortawesome/react-native-fontawesome';
import {getServer, postServer} from '../../api';
import PressableIcon from '../../components/PressableIcon';
import {faLink} from '@fortawesome/free-solid-svg-icons';
import OptionModal from './OptionModal';

const AddScreen = ({navigation}) => {
  const [actionId, setActionId] = useState('');
  const [actionParams, setActionParams] = useState([]);
  const [actionList, setActionList] = useState([]);
  const [reactionList, setReactionList] = useState([]);
  const [currentList, setCurrentList] = useState([]);
  const [modal, setModal] = useState(false);
  const [options, setOptions] = useState([]);
  const [currentItem, setCurrentItem] = useState(undefined);

  useEffect(() => {
    const unsubscribe = navigation.addListener('focus', () => {
      setCurrentList(actionList);
      setActionId('');
      setActionParams('');
      getServer('user/getActions')
        .then(r => {
          setActionList(r.data);
          setCurrentList(r.data);
        })
        .catch(e => console.log(e));
      getServer('user/getReactions')
        .then(r => {
          setReactionList(r.data);
        })
        .catch(e => console.log(e));
    });
    return unsubscribe;
  }, [navigation]);

  function handleItemClick(item) {
    if (item.options.length > 0) {
      setCurrentItem(item);
      setOptions(
        item.options.map(option => {
          return {
            ...option,
            value: '',
          };
        }),
      );
      setModal(true);
    } else {
      addItem(item, '');
    }
  }
  function addItem(item, params) {
    if (actionId.length > 0) {
      postServer('user/addActionReaction', {
        action_id: actionId,
        reaction_id: item._id,
        action_params: actionParams,
        reaction_params: params,
      })
        .then(() => navigation.navigate('Home'))
        .catch(e => console.log(e));
    } else {
      setActionId(item._id);
      setActionParams(params);
      setCurrentList(reactionList);
    }
  }
  function submitModal() {
    const params = options
      .map(e => {
        return `${e.name}:${e.value}`;
      })
      .join();
    addItem(currentItem, params);
    setModal(false);
  }

  return (
    <>
      <DefaultView>
        <OptionModal
          visible={modal}
          onCancel={() => setModal(false)}
          currentItem={currentItem}
          options={options}
          onSetOptions={setOptions}
          onSubmit={submitModal}
        />
        <Text style={styles.mainText}>
          {actionId.length > 0 ? 'Do___' : 'When___'}
        </Text>
        <View style={styles.boxesView}>
          {currentList.map(item => {
            return (
              <DefaultBox padding={0} key={item._id}>
                <DefaultPressable
                  width={'100%'}
                  height={'100%'}
                  radius={40}
                  onPress={() => {
                    handleItemClick(item);
                  }}>
                  <View style={styles.arIconDiv}>
                    {icons[item.service.name]}
                  </View>
                  <Text style={styles.arText}>{item.name}</Text>
                </DefaultPressable>
              </DefaultBox>
            );
          })}
          <DefaultBox padding={0} style={styles.greenBg}>
            <PressableIcon
              icon={faLink}
              size={80}
              style={styles.connectApiBox}
              onPress={() => navigation.navigate('Profile')}
            />
          </DefaultBox>
        </View>
      </DefaultView>
    </>
  );
};

const styles = StyleSheet.create({
  boxesView: {
    justifyContent: 'space-evenly',
    flexDirection: 'row',
    flexWrap: 'wrap',
  },
  mainText: {
    textAlignVertical: 'center',
    height: 70,
    color: 'black',
    fontSize: 30,
  },
  arIconDiv: {
    flex: 1,
    overflow: 'hidden',
  },
  arIcon: {
    flex: 1,
    margin: 10,
    height: 60,
    width: 60,
    resizeMode: 'center',
  },
  arText: {flex: 3, color: 'black', fontSize: 30},
  greenBg: {backgroundColor: 'lightgreen'},
  connectApiBox: {width: '100%', height: '100%', borderRadius: 40},
});

const icons = {
  twitter: <FontAwesomeIcon icon={faTwitter} size={50} style={styles.arIcon} />,
  reddit: <FontAwesomeIcon icon={faReddit} size={50} style={styles.arIcon} />,
  twitch: <FontAwesomeIcon icon={faTwitch} size={50} style={styles.arIcon} />,
  spotify: <FontAwesomeIcon icon={faSpotify} size={50} style={styles.arIcon} />,
  epitech: (
    <Image source={require('./epitechlogo.png')} style={styles.arIcon} />
  ),
};

export default AddScreen;
