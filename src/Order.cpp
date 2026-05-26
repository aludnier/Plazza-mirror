/*
** EPITECH PROJECT, 2026
** order
** File description:
**
*/

#include "Order.hpp"

namespace Plazza
{

std::vector<char> &operator<<(std::vector<char> &pack,const PizzaOrder &order)
{
    std::list<Ingredient> recipe = order._recipe;
    pack.push_back(order._type);
    pack.push_back(order._size);
    pack.push_back(order._cookTime);
    while (!recipe.empty()) {
        pack.push_back(recipe.back());
        recipe.pop_back();
    }
    return pack;
}

PizzaOrder operator>>(std::vector<char> &pack, PizzaOrder &order)
{
    order._cookTime = pack[2];
    order._size = static_cast<PizzaSize>(pack[1]);
    order._type = static_cast<PizzaType>(pack[0]);
    for (size_t i = 3; i < pack.size(); i++) {
        order._recipe.push_back(static_cast<Ingredient>(pack[i]));
    }
    return order;
}


std::ostream &operator<<(std::ostream &s ,const Ingredient &ingredient)
{
    switch (ingredient) {
    case DOUGH :
        s << "DOUGH";
        break;
    case TOMATO :
        s << "TOMATO";
        break;
    case GRUYERE :
        s << "GRUYERE";
        break;
    case HAM :
        s << "HAM";
        break;
    case MUSHROOMS :
        s << "MUSHROOMS";
        break;
    case STEAK :
        s << "STEAK";
        break;
    case EGGPLANT :
        s << "EGGPLANT";
        break;
    case GOAT_CHEESE :
        s << "GOAT_CHEESE";
        break;
    case CHIEF_LOVE :
        s << "CHIEF_LOVE";
        break;
    }
    return s;
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
    s << std::endl << "Recipe : ";
    std::list<Ingredient> recipe = order._recipe;
    while (!recipe.empty())
    {
        s << recipe.back() << ", ";
        recipe.pop_back();
    }
    return s;
}
}
