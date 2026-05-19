/*
** EPITECH PROJECT, 2026
** cook
** File description:
** 
*/

#include "Cook.hpp"

void Cook::makePizza(Plazza::PizzaOrder pizza) 
{
    _currOrder = pizza;
    _thrd = std::thread(&Cook::cookPizza, this);
};

void Cook::cookPizza() 
{
    std::cout << _thrd.get_id() <<"Making " << _currOrder._type << " size : " << _currOrder._type << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << _thrd.get_id() << "finish Making " << _currOrder._type << " size : " << _currOrder._type << std::endl;
};

bool Cook::isAvailable()
{
    return !_thrd.joinable();
};

Cook::Cook(/* args */):
    _thrd(std::thread())
{
}

Cook::~Cook()
{
}
