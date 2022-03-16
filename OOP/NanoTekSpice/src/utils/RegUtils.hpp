/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** RegUtils
*/

#ifndef REGUTILS_HPP_
#define REGUTILS_HPP_

#include <string>
#include <regex>

class RegUtils {
    public:
        RegUtils() = default;
        ~RegUtils() = default;
        static bool isMatch(std::string const &str, std::string const &pattern);
        static std::smatch getMatch(std::string const &str, std::string const &pattern);
        static std::string removeSpaces(std::string const &str);
    protected:
    private:
};

#endif /* !REGUTILS_HPP_ */
