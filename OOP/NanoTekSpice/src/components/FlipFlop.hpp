/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** FlipFlop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "Gate.hpp"

namespace nts {
    enum FlipGateType {
        DFLIP,
        TFLIP
    };

    class FlipFlop {
        public:
            FlipFlop(FlipGateType = DFLIP);
            ~FlipFlop();
            void compute(Tristate, Tristate, Tristate, Tristate = TRUE);
            Tristate GetQ();
            Tristate GetQPrime();
        protected:
        private:
            Tristate _clock = UNDEFINED;
            Tristate _Q = UNDEFINED;
            Tristate _QPrime = UNDEFINED;
            FlipGateType _type;
    };
}

#endif /* !FLIPFLOP_HPP_ */
