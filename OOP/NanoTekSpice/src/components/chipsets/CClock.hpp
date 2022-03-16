/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CClock
*/

#ifndef CCLOCK_HPP_
#define CCLOCK_HPP_

#include "AComponent.hpp"

namespace nts {
    class CClock : public AComponent {
        public:
            CClock();
            ~CClock();
            Tristate compute(size_t pin = 1);
            void simulate(size_t tick);
        protected:
        private:
    };
}

#endif /* !CCLOCK_HPP_ */
