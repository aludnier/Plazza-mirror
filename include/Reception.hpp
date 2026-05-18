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

    void run(std::size_t nbCooks)
    {
        Plazza::Order order = {Plazza::Regina, Plazza::S};
        Kitchen kitchen (nbCooks);
        std::list<Plazza::Order> orders;

        for (size_t i = 0; i < 3; i++) {
            orders.push_back(order);
            order.type << 1;
            order.size << 1;
        }
        
        while (true) {
            kitchen.takeOrder(orders);
            sleep(40);
        }
        

    };

};

Reception::Reception(/* args */)
{
}

Reception::~Reception()
{
}
