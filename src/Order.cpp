/*
** EPITECH PROJECT, 2026
** order
** File description:
** 
*/

#include "Order.hpp"

namespace Plazza {

std::vector<char> &operator<<(std::vector<char> &pack,const PizzaOrder &order)
{
    pack.push_back(order._type);
    pack.push_back(order._size);
    pack.push_back(order._cookTime);
    return pack;
}

PizzaOrder operator>>(std::vector<char> &pack, PizzaOrder &order)
{
    order._cookTime = pack[2];
    order._size = static_cast<PizzaSize>(pack[1]);
    order._type = static_cast<PizzaType>(pack[0]);
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
