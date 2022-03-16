/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CClock
*/

#include "CClock.hpp"

nts::CClock::CClock()
{
}

nts::CClock::~CClock()
{
}

void nts::CClock::simulate(size_t tick)
{
    (void) tick;
    if IS_UNDEFINED(_value)
        return;
    else
        setValue(_value == TRUE ? FALSE : TRUE);
}

nts::Tristate nts::CClock::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
