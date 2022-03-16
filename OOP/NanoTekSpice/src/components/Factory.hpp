/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

// #pragma once

#include <string>
#include <map>
#include <memory>
#include <functional>

#include "AComponent.hpp"
#include "CInput.hpp"
#include "COutput.hpp"
#include "CClock.hpp"
#include "CFalse.hpp"
#include "CTrue.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4011.hpp"
#include "C4013.hpp"
#include "C4017.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
// #include "C4094.hpp"
// #include "C4514.hpp"
// #include "C4801.hpp"
// #include "C4811.hpp"
// #include "C4816.hpp"
// #include "C4876.hpp"
// #include "C2716.hpp"
// #include "logger.hpp"

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory() = default;
            std::unique_ptr<IComponent> createComponent(const std::string &type);
            void AddChipset(const std::string &name, std::string const &key);
            nts::IComponent *GetChipset(const std::string &name);
            std::map<std::string, std::string> GetChipsetsTypes();
        protected:
        private:
            std::map<std::string, std::function<std::unique_ptr<IComponent>()>> _chipsetFactory;
            std::map<std::string, std::unique_ptr<IComponent>> _chipsets;
            std::map<std::string, std::string> _chipsetsTypes;
    };
}

#endif /* !FACTORY_HPP_ */
