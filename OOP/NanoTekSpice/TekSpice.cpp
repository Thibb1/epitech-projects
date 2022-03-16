/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** main
*/

#include "Tekspice.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        nts::Factory factory;
        Parser::parse(
            av[1],
            &factory
        );
        nts::Compute computer(&factory);
        computer.Run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}