/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <map>
#include <vector>
#include <algorithm>
#include "Gate.hpp"
#include "FlipFlop.hpp"

namespace nts {
    class AComponent : public nts::IComponent {
        public:
            virtual ~AComponent() = default;
            virtual Tristate compute(size_t pin);
            virtual void simulate(size_t tick = 1);
            virtual void setLink(size_t pin, IComponent &other, size_t otherPin);
            virtual void dump() const;
            virtual void reset();
            virtual void setValue(Tristate);
            virtual std::string getTristateString(size_t) const;
            virtual Tristate getValue(size_t) const;
            virtual Tristate computePin(size_t);
        protected:
            Tristate _value = UNDEFINED;
            size_t _nbPin = 3;
            std::unordered_map<size_t, Tristate> _values;
            std::unordered_map<size_t, IComponent *> _links;
            std::unordered_map<size_t, size_t> _linksPin;
            size_t _cycle = 0;
    };
}

#endif /* !ACOMPONENT_HPP_ */
