/*
** EPITECH PROJECT, 2026
** cook
** File description:
** 
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
    Plazza::Order _currOrder;
public:
    Plazza::stock *_currStock;
    Cook();
    ~Cook();

    void makePizza(Plazza::Order pizza);
    void cookPizza();
    bool isAvailable();
};