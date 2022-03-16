/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

#include "RegUtils.hpp"
#include "Factory.hpp"

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;
        static void parse(std::string, nts::Factory *);
        static void parseLink(std::string, nts::Factory *);
        static void parseChipset(std::string, nts::Factory *);
        static std::ifstream checkFile(std::string);
        static bool isInVector(std::string, std::vector<std::string>);
    protected:
    private:
};

#endif /* !PARSER_HPP_ */
