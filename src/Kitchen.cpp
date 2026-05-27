/*
** EPITECH PROJECT, 2026
** kitchen
** File description:
**
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t nbCooks, size_t mul) :
    _timeMult(mul),
    _nbCooks(nbCooks),
    _timeOut(std::chrono::system_clock::now() + std::chrono::seconds(5))

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

bool Kitchen::runOut()
{
    auto clockNow = std::chrono::system_clock::now();

    if (clockNow > _timeOut){
        return true;
    }
    return false;
}

void Kitchen::run()
{
    int tmp = 0;
    
    while (!runOut()) {
        Plazza::PizzaOrder order;
        bool orderSend = false;

        try {
            _ipc >> order;
        } catch(const std::exception& e) {
            continue;
        }
        while (!orderSend) {
            for (auto &cook : _cooks) {
                if (cook->isAvailable()) {
                    cook->makePizza(order);
                    orderSend = true;
                    _timeOut = std::chrono::system_clock::now() + std::chrono::seconds(5) + std::chrono::seconds(order._cookTime);
                    break;
                }
            }
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
