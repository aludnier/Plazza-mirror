/*
** EPITECH PROJECT, 2026
** reception
** File description:
** 
*/

#include "Reception.hpp"


void Reception::run(std::size_t nbCooks)
{
    Plazza::Order order = {Plazza::Regina, Plazza::S};
    Kitchen kitchen (nbCooks);
    std::list<Plazza::Order> orders;
    std::string commandLine;

    for (size_t i = 0; i < 3; i++) {
        orders.push_back(order);
        order.type << 1;
        order.size << 1;
    }

    while (true) {
        _parser.readLineFrom(std::cin);
        if (_parser.getLine() == "quit") {
            break;
        }
    }
    
};

Reception::Reception(/* args */)
{
}

Reception::~Reception()
{
}
