/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4011 : public AComponent {
        public:
            C4011();
            ~C4011();
            void dump() const;
            void simulate(size_t = 1);
        protected:
        private:
    };
}

#endif /* !C4011_HPP_ */
