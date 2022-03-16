/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** RegUtil.cpp
*/

#include "RegUtils.hpp"

bool RegUtils::isMatch(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    return std::regex_match(str, reg);
}

std::smatch RegUtils::getMatch(std::string const &str, std::string const &pattern)
{
    std::regex reg(pattern);
    std::smatch match;
    std::regex_search(str, match, reg);
    return match;
}

std::string RegUtils::removeSpaces(std::string const &str)
{
    std::regex reg("\\s*");
    return std::regex_replace(str, reg, "");
}
