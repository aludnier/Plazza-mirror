/*
** EPITECH PROJECT, 2026
** order
** File description:
** 
*/

#include "Order.hpp"

namespace Plazza {

std::stack<char> &operator<<(std::stack<char> &pack,const PizzaOrder &order)
{
    pack.push(order._type);
    pack.push(order._size);
    pack.push(order._cookTime);
    return pack;
}

PizzaOrder operator>>(std::stack<char> &pack, PizzaOrder &order)
{
    order._cookTime = pack.top();
    pack.pop();
    order._size = static_cast<PizzaSize>(pack.top());
    pack.pop();
    order._type = static_cast<PizzaType>(pack.top());
    pack.pop();
    return order;
}


std::ostream &operator<<(std::ostream &s ,const PizzaOrder &order)
    {
    s << "Order : ";
    switch (order._type) {
    case Regina:
        s << "Regina ";
        break;
    case Margarita:
        s << "Margarita ";
        break;
    case Americana:
        s << "Americana ";
        break;
    case Fantasia:
        s << "Fantasia ";
        break;
    }
    switch (order._size) {
    case S:
        s << "S";
        break;
    case M:
        s << "M";
        break;
    case L:
        s << "L";
        break;
    case XL:
        s << "XL";
        break;
    case XXL:
        s << "XXL";
        break;
    }
    return s;
}
}
