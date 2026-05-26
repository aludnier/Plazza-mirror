/*
** EPITECH PROJECT, 2026
** kitchen
** File description:
**
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t nbCooks, size_t mul) :
    _nbCooks(nbCooks)

{
    for (size_t i = 0; i < nbCooks; i++){
        _cooks.push_back(std::make_unique<Cook>(mul, stock));
    }
    _process.startProcess([this](){run();});
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
    int tmp = 0;
    
    while (true) {
        Plazza::PizzaOrder order;
        try {
            bool orderSend = false;
            _ipc >> order;
            while (!orderSend) {
                for (auto &cook : _cooks) {
                    if (cook->isAvailable()) {
                        cook->makePizza(order);
                        orderSend = true;
                        break;
                    }
                }
            }
            
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

KitchenStatus Kitchen::getStatus() const
{
    size_t free_cooks = 0;

    for (auto &cook : _cooks)
        if (cook.get()->isAvailable())
            free_cooks++;
    return {free_cooks, stock};
}
