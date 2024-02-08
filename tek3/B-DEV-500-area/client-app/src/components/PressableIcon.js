import React from 'react';
import {FontAwesomeIcon} from '@fortawesome/react-native-fontawesome';
import {IconDefinition} from '@fortawesome/fontawesome-common-types';
import DefaultPressable from './DefaultPressable';

interface PressableIconProps {
  icon: IconDefinition;
  onPress?: null;
  size?: number;
}

function PressableIcon(props: React.HTMLProps<PressableIconProps>) {
  const {icon, onPress, size} = props;

  return (
    <DefaultPressable onPress={onPress} style={props.style}>
      <FontAwesomeIcon icon={icon} size={size || 45} />
      {props.children}
    </DefaultPressable>
  );
}

export default PressableIcon;
