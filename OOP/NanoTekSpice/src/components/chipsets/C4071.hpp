/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4071 : public AComponent {
        public:
            C4071();
            ~C4071();
            void simulate(size_t pin = 1);
            void dump() const;
        protected:
        private:
    };
}

#endif /* !C4071_HPP_ */
