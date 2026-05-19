/*
** EPITECH PROJECT, 2026
** order
** File description:
** 
*/

#pragma once

namespace Plazza {
    
    enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

struct Order {
    PizzaType type;
    PizzaSize size;
};

struct stock {

};
}
