/*
** EPITECH PROJECT, 2026
** cook
** File description:
**
*/

#include "Cook.hpp"

Cook::Cook(double mul, std::unordered_map<Plazza::Ingredient, size_t> &stock,
    size_t time, Mutex &stockMutex)
    : _isAvailable(true), _mul(mul), _stock(stock), _mutex(stockMutex), _time(time)
{
}

Cook::~Cook()
{
    if (_thrd.joinable())
        _thrd.join();
}

void Cook::makePizza(Plazza::PizzaOrder pizza)
{
    if (_thrd.joinable()){
        _thrd.join();
    }
    _isAvailable = false;
    _currOrder = pizza;
    _thrd = std::thread(&Cook::cookPizza, this);
};

void Cook::cookPizza()
{
    std::cout << "[Cook " << _thrd.get_id() << "] Making pizza type " << _currOrder << std::endl;
    {
        ScopedLock mut(_mutex);
        useStock(_currOrder);
    }
    std::this_thread::sleep_for(
        std::chrono::milliseconds(_currOrder._cookTime * _time * _mul));
    std::cout << "[Cook " << _thrd.get_id() << "] Done!\n";
    _isAvailable = true;
};

bool Cook::isAvailable() const
{
    return _isAvailable;
};

bool Cook::useStock(const Plazza::PizzaOrder &order)
{
    for (const auto &i : order._recipe)
        if (_stock[i] == 0)
            return false;
    for (const auto &i : order._recipe)
        _stock[i]--;
    return true;
}
