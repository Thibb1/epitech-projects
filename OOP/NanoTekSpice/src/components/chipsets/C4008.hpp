/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4008 : public AComponent {
        public:
            C4008();
            ~C4008();
            Tristate computeSum(Tristate, Tristate, Tristate);
            Tristate computeCarry(Tristate, Tristate, Tristate);
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
    };
}

#endif /* !C4008_HPP_ */
