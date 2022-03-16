/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** FlipFlop
*/

#include "FlipFlop.hpp"

nts::FlipFlop::FlipFlop(FlipGateType type) : _type(type)
{
}

nts::FlipFlop::~FlipFlop()
{
}

void nts::FlipFlop::compute(Tristate clock, Tristate data, Tristate set, Tristate reset)
{
    if (IS_UNDEFINED(reset) && set == FALSE) {
        _Q = TRUE;
        _QPrime = UNDEFINED;
        return;
    }
    if (IS_UNDEFINED(set) && reset == FALSE) {
        _Q = UNDEFINED;
        _QPrime = TRUE;
        return;
    }
    if (Gate::Xor(set, reset) == TRUE) {
        _Q = set;
        _QPrime = IS_UNDEFINED(clock) && reset == TRUE ? UNDEFINED : reset;
    } else if (Gate::Nor(set, reset) == TRUE) {
        _Q = TRUE;
        _QPrime = TRUE;
    }
    Tristate current = _clock != TRUE ? clock : FALSE;
    _clock = clock;
    if (Gate::And(set, reset) == TRUE && current == TRUE) {
        if (_type == DFLIP) {
            _Q = data;
            _QPrime = Gate::Not(data);
        } else if (_type == TFLIP) {
            _QPrime = Gate::Or(Gate::And(data, _QPrime), Gate::And(Gate::Not(data), _Q));
            _Q = Gate::Not(_QPrime);
        }
    }
}

nts::Tristate nts::FlipFlop::GetQ()
{
    return _Q;
}

nts::Tristate nts::FlipFlop::GetQPrime()
{
    return _QPrime;
}
