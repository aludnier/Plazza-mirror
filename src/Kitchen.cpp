/*
** EPITECH PROJECT, 2026
** kitchne
** File description:
** 
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t nbCooks) :
    _nbCooks(nbCooks)
{
    for (size_t i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Cook>());
    }
};
Kitchen::~Kitchen()
{
}

bool Kitchen::takeOrder(std::list<Plazza::Order> &orders) 
{
    if (orders.size() > 2 * _nbCooks) {
        return false;
    }
    while (!orders.empty()) {
        Plazza::Order order = orders.back();
        orders.pop_back();
        sendPizza(order);
    }
    return true;
};

void Kitchen::sendPizza(Plazza::Order &order) 
{
    for (size_t i = 0; i < _nbCooks; i++) {
        if (_cooks[i]->isAvailable()) {
            _cooks[i]->makePizza(order);
        }
    }
    
};

