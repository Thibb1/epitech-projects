/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CTrue
*/

#ifndef CTRUE_HPP_
#define CTRUE_HPP_

#include "AComponent.hpp"

namespace nts {
    class CTrue : public AComponent {
        public:
            CTrue();
            ~CTrue();
            Tristate compute(size_t pin = 1);
        protected:
        private:
    };
}

#endif /* !CTRUE_HPP_ */
