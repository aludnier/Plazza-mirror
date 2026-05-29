/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

#include <thread>
#include "Order.hpp"
#include <iostream>
#include <chrono>
#include <unordered_map>
#include <memory>
#include <mutex>
#include "ScopedLock.hpp"

class Cook
{
    private:
        std::thread _thrd;
        Plazza::PizzaOrder _currOrder;
        bool _isAvailable;
        size_t _mul;
        std::unordered_map<Plazza::Ingredient, size_t> &_stock;
        Mutex &_mutex;
        size_t _time;

    public:
        Cook(double mul, std::unordered_map<Plazza::Ingredient, size_t> &stock,
            size_t time, Mutex &stockMutex);
        ~Cook();

        void makePizza(Plazza::PizzaOrder pizza);
        void cookPizza();
        bool isAvailable() const;
        bool useStock(const Plazza::PizzaOrder &order);
};

#endif /* !COOK_HPP_ */
