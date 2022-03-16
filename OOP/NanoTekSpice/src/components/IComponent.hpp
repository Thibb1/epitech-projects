/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(size_t tick = 1) = 0;
            virtual Tristate compute(size_t pin) = 0;
            virtual void setLink(size_t pin, IComponent &other, size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual void setValue(Tristate) = 0;
            virtual void reset() = 0;
    };
    #define IS_UNDEFINED(nts) ((nts) == UNDEFINED)
}

#endif /* !ICOMPONENT_HPP_ */
