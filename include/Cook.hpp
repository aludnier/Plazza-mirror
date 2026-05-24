/*
** EPITECH PROJECT, 2026
** cook
** File description:
** Cook class
*/

#pragma once
#include <thread>
#include "Order.hpp"
#include <iostream>
#include <chrono>

class Cook
{
private:
    std::thread _thrd;
    Plazza::PizzaOrder _currOrder;
    bool _isAvailable;
public:
    Plazza::stock *_currStock;
    Cook();
    ~Cook();

    void makePizza(Plazza::PizzaOrder pizza);
    void cookPizza();
    bool isAvailable() const;
};