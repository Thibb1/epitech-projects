/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CInput
*/

#ifndef CINPUT_HPP_
#define CINPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class CInput : public AComponent {
        public:
            CInput();
            ~CInput();
            Tristate compute(size_t pin = 1);
        protected:
        private:
    };
}

#endif /* !CINPUT_HPP_ */
