/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CFalse
*/

#ifndef CFALSE_HPP_
#define CFALSE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CFalse : public AComponent {
        public:
            CFalse();
            ~CFalse();
            Tristate compute(size_t pin = 1);
        protected:
        private:
    };
}

#endif /* !CFALSE_HPP_ */
