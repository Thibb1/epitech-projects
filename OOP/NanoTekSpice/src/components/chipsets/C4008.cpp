/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4008.hpp"

nts::C4008::C4008()
{
    _nbPin = 16;
}

nts::C4008::~C4008()
{
}

nts::Tristate nts::C4008::computeSum(Tristate a, Tristate b, Tristate c)
{
    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED)
        return UNDEFINED;
    return Gate::Xor(Gate::Xor(a, b), c);
}

nts::Tristate nts::C4008::computeCarry(Tristate a, Tristate b, Tristate c)
{
    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED)
        return UNDEFINED;
    return Gate::Or(Gate::And(a, b), Gate::And(Gate::Xor(a, b), c));
}

void nts::C4008::simulate(size_t pin)
{
    (void) pin;
    Tristate a = computePin(6);
    Tristate b = computePin(7);
    Tristate c = computePin(9);
    Tristate d = computePin(5);
    Tristate e = computePin(4);
    Tristate f = computePin(3);
    Tristate g = computePin(2);
    Tristate h = computePin(1);
    Tristate i = computePin(15);
    _values[10] = computeSum(a, b, c);
    Tristate c0 = computeCarry(a, b, c);
    _values[11] = computeSum(c0, d, e);
    Tristate c1 = computeCarry(c0, d, e);
    _values[12] = computeSum(c1, f, g);
    Tristate c2 = computeCarry(c1, f, g);
    _values[13] = computeSum(c2, h, i);
    _values[14] = computeCarry(c2, h, i);
}

void nts::C4008::dump() const
{
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    11: " << getTristateString(11);
    std::cout << "\n    12: " << getTristateString(12);
    std::cout << "\n    13: " << getTristateString(13);
    std::cout << "\n    14: " << getTristateString(14) << std::endl;
}