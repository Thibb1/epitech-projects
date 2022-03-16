/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    _chipsetFactory["input"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CInput>(); };
    _chipsetFactory["output"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<COutput>(); };
    _chipsetFactory["clock"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CClock>(); };
    _chipsetFactory["false"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CFalse>(); };
    _chipsetFactory["true"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CTrue>(); };
    _chipsetFactory["4001"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4001>(); };
    _chipsetFactory["4008"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4008>(); };
    _chipsetFactory["4011"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4011>(); };
    _chipsetFactory["4013"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4013>(); };
    _chipsetFactory["4017"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4017>(); };
    _chipsetFactory["4030"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4030>(); };
    _chipsetFactory["4040"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4040>(); };
    _chipsetFactory["4069"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4069>(); };
    _chipsetFactory["4071"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4071>(); };
    _chipsetFactory["4081"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4081>(); };
    // _chipsetFactory["4094"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4094>(); };
    // _chipsetFactory["4512"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4512>(); };
    // _chipsetFactory["4514"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4514>(); };
    // _chipsetFactory["4801"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C4801>(); };
    // _chipsetFactory["2716"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<C2716>(); };
    // _chipsetFactory["logger"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<Clogger>(); };
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (_chipsetFactory.find(type) == _chipsetFactory.end())
        throw std::runtime_error("Unknown chipset");
    return std::move(_chipsetFactory[type]());
}

void nts::Factory::AddChipset(const std::string &name, std::string const &key)
{
    _chipsets[name] = createComponent(key);
    _chipsetsTypes[name] = key;
}

nts::IComponent *nts::Factory::GetChipset(const std::string &name)
{
    if (_chipsets.find(name) == _chipsets.end())
        throw std::runtime_error("Chipset not found");
    return _chipsets[name].get();
}

std::map<std::string, std::string> nts::Factory::GetChipsetsTypes()
{
    return _chipsetsTypes;
}