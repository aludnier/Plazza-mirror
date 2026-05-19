/*
** EPITECH PROJECT, 2026
** kitchne
** File description:
** 
*/

#pragma once

#include <vector>
#include "Order.hpp"
#include "Cook.hpp"
#include <list>
#include <memory>

class Kitchen
{
private:
    std::size_t _nbCooks;
    std::vector<std::unique_ptr<Cook>> _cooks;
public:
    Kitchen(std::size_t nbCooks);
    ~Kitchen();

    bool takeOrder(std::list<Plazza::PizzaOrder> &orders);
    void sendPizza(Plazza::PizzaOrder &order);
};
