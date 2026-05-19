/*
** EPITECH PROJECT, 2026
** order
** File description:
** 
*/

#include "Order.hpp"

namespace Plazza {

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
