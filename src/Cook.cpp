/*
** EPITECH PROJECT, 2026
** cook
** File description:
**
*/

#include "../include/Cook.hpp"

Cook::Cook() : _isAvailable(true)
{
}

Cook::~Cook()
{
    if (_thrd.joinable())
        _thrd.join();
}

void Cook::makePizza(Plazza::PizzaOrder pizza)
{
if (_thrd.joinable())
        _thrd.join();

    _isAvailable = false;
    _currOrder = pizza;
    _thrd = std::thread(&Cook::cookPizza, this);
};

void Cook::cookPizza()
{
    std::cout << "Cook " << _thrd.get_id() << " Making pizza type "
        << _currOrder._type << " size " << _currOrder._size << "\n";
    std::this_thread::sleep_for(
        std::chrono::milliseconds(_currOrder._cookTime * 1000));
    std::cout << "[Cook " << _thrd.get_id() << "] Done!\n";
    _isAvailable = true;
};

bool Cook::isAvailable() const
{
    return _isAvailable;
};
