/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4013
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4013 : public AComponent {
        public:
            C4013();
            ~C4013();
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
            FlipFlop _flipFlop1;
            FlipFlop _flipFlop2;
    };
}

#endif /* !C4013_HPP_ */
