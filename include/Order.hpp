/*
** EPITECH PROJECT, 2026
** order
** File description:
** class Order
*/

#pragma once
#include <iostream>
#include <vector>
#include <list>

namespace Plazza
{

enum Ingredient
{
    DOUGH = 1,
    TOMATO = 2,
    GRUYERE = 4,
    HAM = 8,
    MUSHROOMS = 16,
    STEAK = 32,
    EGGPLANT = 64,
    GOAT_CHEESE = 128,
    CHIEF_LOVE = 256
};

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

struct PizzaOrder {
    PizzaType _type;
    PizzaSize _size;
    std::size_t _cookTime;
    std::list<Ingredient> _recipe;
};

std::vector<char> &operator<<(std::vector<char> &pack,const PizzaOrder &order);
PizzaOrder operator>>(std::vector<char> &pack, PizzaOrder &order);

std::ostream &operator<<(std::ostream &s ,const PizzaOrder &order);
std::ostream &operator<<(std::ostream &s ,const Ingredient &ingredient);

struct ReginaOrder : public PizzaOrder
{
    ReginaOrder(PizzaSize size) :
        PizzaOrder({Regina, size, 2, {DOUGH, TOMATO, GRUYERE, HAM, MUSHROOMS}}) {};
};

struct MargaritaOrder : public PizzaOrder
{
    MargaritaOrder(PizzaSize size) :
        PizzaOrder({Margarita, size, 1, {DOUGH, TOMATO, GRUYERE}}) {};
};

struct AmericanaOrder : public PizzaOrder
{
    AmericanaOrder(PizzaSize size) :
        PizzaOrder({Americana, size, 2, {DOUGH, TOMATO, GRUYERE, STEAK}}) {};
};

struct FantasiaOrder : public PizzaOrder
{
    FantasiaOrder(PizzaSize size) :
        PizzaOrder({Fantasia, size, 4, {DOUGH, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE}}) {};
};


struct stock {

};
}
