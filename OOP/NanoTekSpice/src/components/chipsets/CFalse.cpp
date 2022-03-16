/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CFalse
*/

#include "CFalse.hpp"

nts::CFalse::CFalse()
{
    _value = FALSE;
}

nts::CFalse::~CFalse()
{
}

nts::Tristate nts::CFalse::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
