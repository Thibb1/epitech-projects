import React, {useEffect, useState} from 'react';
import {StyleSheet, Text, View} from 'react-native';
import PressableIcon from '../../components/PressableIcon';
import {
  faCirclePlus,
  faPencil,
  faTrash,
} from '@fortawesome/free-solid-svg-icons';
import DefaultBox from '../../components/DefaultBox';
import DefaultView from '../../components/DefaultView';
import {deleteServer, getServer} from '../../api';

const HomeScreen = ({navigation}) => {
  const [list, setList] = useState([]);

  useEffect(() => {
    const unsubscribe = navigation.addListener('focus', () => {
      getServer('user/getActionReaction')
        .then(r => {
          console.log(r.data);
          setList(r.data);
        })
        .catch(e => console.log(e));
    });
    return unsubscribe;
  }, [navigation]);

  function deleteId(id: string) {
    deleteServer(`user/deleteActionReaction/${id}`)
      .then(() => setList(list.filter(({_id}) => _id !== id)))
      .catch(e => console.log(e));
  }

  return (
    <>
      <DefaultView>
        <Text style={styles.mainText}>Select or edit your action</Text>
        <View style={styles.boxesView}>
          {list.map(item => {
            return (
              <DefaultBox key={item._id}>
                <View style={styles.boxTextView}>
                  <Text style={styles.boxBoldText}>Do </Text>
                  <Text style={styles.boxText} numberOfLines={1}>
                    {item.reaction.name}
                  </Text>
                  <Text style={styles.boxBoldText}>When </Text>
                  <Text style={styles.boxText} numberOfLines={1}>
                    {item.action.name}
                  </Text>
                </View>
                <View style={styles.boxIconView}>
                  <PressableIcon
                    icon={faPencil}
                    size={30}
                    onPress={() => {
                      deleteId(item._id);
                      navigation.navigate('Add');
                    }}
                  />
                  <PressableIcon
                    icon={faTrash}
                    size={30}
                    onPress={() => deleteId(item._id)}
                  />
                </View>
              </DefaultBox>
            );
          })}
          <DefaultBox padding={0} style={{backgroundColor: 'lightgreen'}}>
            <PressableIcon
              icon={faCirclePlus}
              size={80}
              style={{width: '100%', height: '100%', borderRadius: 40}}
              onPress={() => navigation.navigate('Add')}
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
  boxTextView: {
    width: '70%',
    justifyContent: 'space-around',
  },
  boxIconView: {
    maxWidth: '30%',
    justifyContent: 'space-evenly',
  },
  mainText: {
    textAlignVertical: 'center',
    height: 70,
    color: 'black',
    fontSize: 30,
  },
  boxText: {
    color: 'black',
    fontSize: 20,
  },
  boxBoldText: {
    color: 'black',
    fontSize: 20,
    fontWeight: 'bold',
  },
});

export default HomeScreen;
