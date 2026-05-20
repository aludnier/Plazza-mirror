/*
** EPITECH PROJECT, 2026
** reception
** File description:
** 
*/

#include "Reception.hpp"

std::list<Plazza::PizzaOrder> Reception::parseOrder()
{
    LineParser orderparser;
    std::list<Plazza::PizzaOrder> orderlist;

    for (auto order : _parser.getWords()) {
        orderparser.ParseLine(order);
        try {
            if (orderparser[2].compare(0, 1, "x") != 0) {
                throw std::exception();
            }
            orderparser[2].erase(0, 1);
            std::size_t nbPizza = std::atoi(orderparser[2].c_str());
            for (size_t i = 0; i < nbPizza; i++) {
                orderlist.push_back(
                    _pizzaFunc[orderparser[0]](_sizes[orderparser[1]]));
            }
        } catch(const std::exception& e) {
            std::cout << "wrong syntax : " << orderparser.getLine() << std::endl;
        }
    }
    while (!orderlist.empty()) {
        std::cout << orderlist.back() << std::endl;
        orderlist.pop_back();
    }
    
    return orderlist;
}

void Reception::run(std::size_t nbCooks)
{
    Plazza::PizzaOrder order = {Plazza::Regina, Plazza::S};
    Kitchen kitchen (nbCooks);
    std::list<Plazza::PizzaOrder> orders;
    std::string commandLine;

    while (true) {
        _parser.readLineFrom(std::cin, ';');
        if (_parser.getLine() == "quit") {
            break;
        }
        parseOrder();
    }
};

Reception::Reception(/* args */)
{
}

Reception::~Reception()
{
}
