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
        std::cout << "Order : " << order << std::endl;
        orderparser.ParseLine(order);
        for (auto s : orderparser.getWords()) {
            std::cout << " : ";
            std::cout << s << std::endl;
        }
        try {
            orderparser[2].erase(0);
            std::size_t nbPizza = std::atoi(orderparser[2].c_str());
            for (size_t i = 0; i < nbPizza; i++) {
                orderlist.push_back(
                    _pizzaFunc[orderparser[0]](_sizes[orderparser[1]]));
            }
        } catch(const std::exception& e) {
            std::cout << "wrong syntax : " << orderparser.getLine() << std::endl;
        }
        std::cout << "-------------" << std::endl;
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
