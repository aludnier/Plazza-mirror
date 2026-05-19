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

class Reception
{
private:
    std::deque<Kitchen> _kitchens;
public:
    Reception(/* args */);
    ~Reception();

    void run(std::size_t nbCooks);

};
