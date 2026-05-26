/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "Reception.hpp"
#include "ArgParser.hpp"

int main(int ac, char **av)
{
    try {
        ArgParser parser(ac, av);
        Reception shell(parser._intArgs[1], parser._intArgs[0], parser._intArgs[2]);

        shell.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
