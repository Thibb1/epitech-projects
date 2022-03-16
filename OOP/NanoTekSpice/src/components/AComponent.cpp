/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin > _nbPin)
        throw std::invalid_argument("PinError: pin out of range");
    _links[pin] = &other;
    _linksPin[pin] = otherPin;
}

void nts::AComponent::reset(void)
{
    _cycle = 0;
}

void nts::AComponent::setValue(Tristate state)
{
    _value = state;
}

void nts::AComponent::dump() const
{
    if (IS_UNDEFINED(_value))
        std::cout << "U" << std::endl;
    else
        std::cout << _value << std::endl;
}

void nts::AComponent::simulate(size_t tick)
{
    (void) tick;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
    simulate(pin);
    return getValue(pin);
}

std::string nts::AComponent::getTristateString(size_t pin) const
{
    Tristate state = UNDEFINED;
    if (_values.find(pin) != _values.end())
        state = _values.at(pin);
    if (state == UNDEFINED)
        return "U";
    else if (state == TRUE)
        return "1";
    else
        return "0";
}

nts::Tristate nts::AComponent::getValue(size_t pin) const
{
    if (_values.find(pin) != _values.end())
        return _values.at(pin);
    return UNDEFINED;
    throw std::out_of_range("Pin out of range");
}

nts::Tristate nts::AComponent::computePin(size_t pin)
{
    if (_links.find(pin) != _links.end() &&
        _linksPin.find(pin) != _linksPin.end()) {
        return _links[pin]->compute(_linksPin[pin]);
    }
    return UNDEFINED;
}