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
    for (size_t i = 0; i < nbCooks; i++)
        _cooks.push_back(std::make_unique<Cook>(mul));
    stock = {
        {Plazza::Ingredient::DOUGH, 10},
        {Plazza::Ingredient::TOMATO, 10},
        {Plazza::Ingredient::GRUYERE, 10},
        {Plazza::Ingredient::HAM, 10},
        {Plazza::Ingredient::MUSHROOMS, 10},
        {Plazza::Ingredient::STEAK, 10},
        {Plazza::Ingredient::EGGPLANT, 10},
        {Plazza::Ingredient::GOAT_CHEESE, 10},
        {Plazza::Ingredient::CHIEF_LOVE, 10}
    };
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
        } catch (const IPC::IPCError &e) {
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
