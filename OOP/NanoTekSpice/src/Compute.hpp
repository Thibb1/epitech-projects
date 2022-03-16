/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#ifndef COMPUTE_HPP_
#define COMPUTE_HPP_

#include <csignal>
#include "Factory.hpp"
#include "RegUtils.hpp"

namespace nts {
    class Compute {
        public:
            Compute(nts::Factory *);
            ~Compute() = default;
            void Run();
            void Display();
            void Simulate();
            void SimulateOutput();
            void Loop();
            void AddChange(std::string const &);
            static void StopSignal(int);
        protected:
        private:
            std::size_t _ticks;
            std::map<std::string, IComponent *> _inputs;
            std::map<std::string, IComponent *> _outputs;
            std::unordered_map<std::string, IComponent *> _comps;
            std::unordered_map<std::string, Tristate> _values;
            std::map<std::string, std::string> _chipsets;
    };
    #define GET_TRISTATE(nts) ((nts) == "U" ? UNDEFINED : ((nts) == "1" ? TRUE : FALSE))
}


#endif /* !COMPUTE_HPP_ */
