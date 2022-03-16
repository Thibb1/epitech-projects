/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4069.hpp"

nts::C4069::C4069()
{
    _nbPin = 14;
}

nts::C4069::~C4069()
{
}

void nts::C4069::simulate(size_t pin)
{
    switch (pin) {
        case 2:
            _values[2] = Gate::Not(computePin(1));
            break;
        case 4:
            _values[4] = Gate::Not(computePin(3));
            break;
        case 6:
            _values[6] = Gate::Not(computePin(5));
            break;
        case 8:
            _values[8] = Gate::Not(computePin(9));
            break;
        case 10:
            _values[10] = Gate::Not(computePin(11));
            break;
        case 12:
            _values[12] = Gate::Not(computePin(13));
            break;
        default:
            throw std::out_of_range("PinError: pin out of range");
    }
}

void nts::C4069::dump() const
{
    std::cout << "\n    02: " << getTristateString(2);
    std::cout << "\n    04: " << getTristateString(4);
    std::cout << "\n    06: " << getTristateString(6);
    std::cout << "\n    08: " << getTristateString(8);
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    12: " << getTristateString(12) << std::endl;
}