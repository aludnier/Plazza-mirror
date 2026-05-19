/*
** EPITECH PROJECT, 2026
** reception
** File description:
** 
*/

#pragma once
#include <cstddef>
#include "Kitchen.hpp"
#include <deque>
#include <list>
#include <unistd.h>
#include "Order.hpp"
#include "LineParser.hpp"
#include <unordered_map>
#include "functional"
class Reception
{
public:
    Reception(/* args */);
    ~Reception();

    std::list<Plazza::PizzaOrder> parseOrder();
    void run(std::size_t nbCooks);
private:
    std::deque<Kitchen> _kitchens;
    LineParser _parser;

    std::unordered_map<std::string, std::function<Plazza::PizzaOrder(Plazza::PizzaSize)>> _pizzaFunc =  {
        {"Regina", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::ReginaOrder(size);}},
        {"Margarita", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::MargaritaOrder(size);}},
        {"Americana", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::AmericanaOrder(size);}},
        {"Fantasia", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::FantasiaOrder(size);}}
    };

    std::unordered_map<std::string, Plazza::PizzaSize> _sizes = {
        {"S", Plazza::S},
        {"M", Plazza::M},
        {"L", Plazza::L},
        {"XL", Plazza::XL},
        {"XXL", Plazza::XXL}
    };
};
