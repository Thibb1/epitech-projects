import React from 'react';
import Animated from 'react-native-reanimated';
import Gradient from '../components/Gradient';

export const withAnimated = WrappedComponent => {
  const displayName =
    WrappedComponent.displayName || WrappedComponent.name || 'Component';
  class WithAnimated extends React.Component {
    displayName = `WithAnimated( ${displayName} )`;
    render() {
      return <WrappedComponent {...this.props} />;
    }
  }
  return Animated.createAnimatedComponent(WithAnimated);
};

export const AnimatedGradient = withAnimated(Gradient);
