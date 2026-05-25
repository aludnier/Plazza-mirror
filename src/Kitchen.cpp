/*
** EPITECH PROJECT, 2026
** kitchen
** File description:
**
*/

#include "../include/Kitchen.hpp"

Kitchen::Kitchen(std::size_t nbCooks) :
    _nbCooks(nbCooks)
{
    for (size_t i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Cook>());
    }
    _process.startProcess([this]() {run();});
};

Kitchen::~Kitchen()
{
    _process.waitForProcess();
}

bool Kitchen::takeOrder(std::list<Plazza::PizzaOrder> &orders)
{
    Plazza::PizzaOrder order;

    if (orders.size() > 2 * _nbCooks)
        return false;
    while (!orders.empty()) {
        order = orders.back();
        orders.pop_back();
        _ipc << order;
    }
    return true;
};

void Kitchen::run()
{
    Plazza::PizzaOrder order;
    int tmp = 0;

    while (true) {
        try {
            _ipc >> order;
            for (auto &cook : _cooks) {
                if (cook->isAvailable()) {
                    cook->makePizza(order);
                    break;
                }
            }
        } catch (const IPC::IPCError &) {
            // do something
        }
    }
}
