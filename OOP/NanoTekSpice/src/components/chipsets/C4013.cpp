/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4013.hpp"

nts::C4013::C4013()
{
    _nbPin = 16;
}

nts::C4013::~C4013()
{
}

void nts::C4013::simulate(size_t pin)
{
    (void) pin;
    _flipFlop1.compute(
        computePin(3),
        computePin(5),
        computePin(6),
        computePin(4)
    );
    _flipFlop2.compute(
        computePin(11),
        computePin(9),
        computePin(8),
        computePin(10)
    );
    _values[1] = _flipFlop1.GetQPrime();
    _values[2] = _flipFlop1.GetQ();
    _values[12] = _flipFlop2.GetQ();
    _values[13] = _flipFlop2.GetQPrime();
}

void nts::C4013::dump() const
{
    std::cout << "\n    01: " << getTristateString(1);
    std::cout << "\n    02: " << getTristateString(2);
    std::cout << "\n    12: " << getTristateString(12);
    std::cout << "\n    13: " << getTristateString(13) << std::endl;
}