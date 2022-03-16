/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4040.hpp"

nts::C4040::C4040()
{
    _nbPin = 16;
}

nts::C4040::~C4040()
{
}

void nts::C4040::simulate(size_t pin)
{
    (void) pin;
    _values[9] = _flipFlop_01->GetQ();
    _values[7] = _flipFlop_02->GetQ();
    _values[6] = _flipFlop_03->GetQ();
    _values[5] = _flipFlop_04->GetQ();
    _values[3] = _flipFlop_05->GetQ();
    _values[2] = _flipFlop_06->GetQ();
    _values[4] = _flipFlop_07->GetQ();
    _values[13] = _flipFlop_08->GetQ();
    _values[12] = _flipFlop_09->GetQ();
    _values[14] = _flipFlop_10->GetQ();
    _values[15] = _flipFlop_11->GetQ();
    _values[1] = _flipFlop_12->GetQ();
}

nts::Tristate nts::C4040::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 1000) {
        reset();
        simulate();
        return getValue(pin);
    }
    Tristate cl_clock = computePin(10);
    Tristate in_reset = computePin(11);
    if (IS_UNDEFINED(cl_clock) || IS_UNDEFINED(in_reset))
        return UNDEFINED;
    Tristate clock = Gate::Nor(cl_clock, in_reset);
    Tristate data = Gate::Not(clock);
    Tristate set = Gate::Not(in_reset);
    _flipFlop_01->compute(clock, data, set);
    _flipFlop_02->compute(_flipFlop_01->GetQPrime(), _flipFlop_01->GetQ(), set);
    _flipFlop_03->compute(_flipFlop_02->GetQPrime(), _flipFlop_02->GetQ(), set);
    _flipFlop_04->compute(_flipFlop_03->GetQPrime(), _flipFlop_03->GetQ(), set);
    _flipFlop_05->compute(_flipFlop_04->GetQPrime(), _flipFlop_04->GetQ(), set);
    _flipFlop_06->compute(_flipFlop_05->GetQPrime(), _flipFlop_05->GetQ(), set);
    _flipFlop_07->compute(_flipFlop_06->GetQPrime(), _flipFlop_06->GetQ(), set);
    _flipFlop_08->compute(_flipFlop_07->GetQPrime(), _flipFlop_07->GetQ(), set);
    _flipFlop_09->compute(_flipFlop_08->GetQPrime(), _flipFlop_08->GetQ(), set);
    _flipFlop_10->compute(_flipFlop_09->GetQPrime(), _flipFlop_09->GetQ(), set);
    _flipFlop_11->compute(_flipFlop_10->GetQPrime(), _flipFlop_10->GetQ(), set);
    _flipFlop_12->compute(_flipFlop_11->GetQPrime(), _flipFlop_11->GetQ(), set);
    simulate();
    return getValue(pin);
}

void nts::C4040::dump() const
{
    std::cout << "\n    01: " << getTristateString(9);
    std::cout << "\n    02: " << getTristateString(7);
    std::cout << "\n    03: " << getTristateString(6);
    std::cout << "\n    04: " << getTristateString(5);
    std::cout << "\n    05: " << getTristateString(3);
    std::cout << "\n    06: " << getTristateString(2);
    std::cout << "\n    07: " << getTristateString(4);
    std::cout << "\n    08: " << getTristateString(13);
    std::cout << "\n    09: " << getTristateString(12);
    std::cout << "\n    10: " << getTristateString(14);
    std::cout << "\n    11: " << getTristateString(15);
    std::cout << "\n    12: " << getTristateString(1) << std::endl;
}