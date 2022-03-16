/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Gate
*/

#ifndef GATE_HPP_
#define GATE_HPP_

#include "IComponent.hpp"

namespace nts {
    class Gate {
        public:
            Gate() = default;
            ~Gate() = delete;
            static Tristate Not(Tristate);
            static Tristate Nor(Tristate, Tristate);
            static Tristate Or(Tristate, Tristate);
            static Tristate And(Tristate, Tristate);
            static Tristate Xor(Tristate, Tristate);
            static Tristate Nand(Tristate, Tristate);
        protected:
        private:
    };
}

#endif /* !GATE_HPP_ */
