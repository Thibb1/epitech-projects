/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4017
*/

#ifndef C4017_HPP_
#define C4017_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4017 : public AComponent {
        public:
            C4017();
            ~C4017();
            Tristate compute(size_t pin = 1);
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
            FlipFlop _flipFlop1;
            FlipFlop _flipFlop2;
            FlipFlop _flipFlop3;
            FlipFlop _flipFlop4;
            FlipFlop _flipFlop5;
    };
}

#endif /* !C4017_HPP_ */
