/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4081 : public AComponent {
        public:
            C4081();
            ~C4081();
            void simulate(size_t pin = 1);
            void dump() const;
        protected:
        private:
    };
}

#endif /* !C4081_HPP_ */
