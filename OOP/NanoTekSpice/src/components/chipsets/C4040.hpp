/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4040
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4040 : public AComponent {
        public:
            C4040();
            ~C4040();
            Tristate compute(size_t pin = 1);
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
            FlipFlop *_flipFlop_01 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_02 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_03 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_04 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_05 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_06 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_07 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_08 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_09 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_10 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_11 = new FlipFlop(TFLIP);
            FlipFlop *_flipFlop_12 = new FlipFlop(TFLIP);
    };
}

#endif /* !C4040_HPP_ */
