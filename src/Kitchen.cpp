/*
** EPITECH PROJECT, 2026
** kitchen
** File description:
**
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t nbCooks, double mul, size_t time) :
    _timeMult(mul),
    _nbCooks(nbCooks),
    _isAlive(true),
    _currLoad(0),
    _timeOut(std::chrono::system_clock::now() + std::chrono::seconds(TIMEOUT))
{
    for (size_t i = 0; i < nbCooks; i++)
        _cooks.push_back(std::make_unique<Cook>(mul, stock, time, _stockMutex));
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
        _currLoad++;
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
    bool orderSend;

    while (!runOut()) {
        std::string msg;
        try {
            _statusReq >> msg;
            if (msg == "status") {
                _statusReply << buildStatus();
                _timeOut = std::chrono::system_clock::now() + std::chrono::seconds(TIMEOUT);
            } else if (msg == "quit") {
                break;
            }
        } catch (...) {}
        Plazza::PizzaOrder order;
        orderSend = false;
        try {
            _ipc >> order;
        } catch (...) {
            continue;
        }
        _timeOut = std::chrono::system_clock::now() + std::chrono::seconds(TIMEOUT);
        while (!orderSend) {
            try {
                _statusReq >> msg;
                if (msg == "status") {
                    _statusReply << buildStatus();
                    _timeOut = std::chrono::system_clock::now() + std::chrono::seconds(TIMEOUT);
                }
            } catch (...) {}
            for (auto &cook : _cooks) {
                if (cook->isAvailable()) {
                    cook->makePizza(order);
                    orderSend = true;
                    _timeOut = std::chrono::system_clock::now() + std::chrono::seconds(TIMEOUT);
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(TIMEOUT));
        }
    }
    for (auto &thrd : _cooks)
        thrd->~Cook();
    _isAlive = false;
}

KitchenStatus Kitchen::buildStatus()
{
    size_t free_cooks = 0;
    for (auto &cook : _cooks)
        if (cook->isAvailable())
            free_cooks++;
    return {_isAlive, free_cooks, stock};
}

KitchenStatus Kitchen::getStatus()
{
    KitchenStatus status;

    if (!_isAlive)
        return {false, 0, {}};
    _statusReq << std::string("status");
    _statusReply >> status;
    if (!status.is_alive)
        _isAlive = false;
    return status;
}

void Kitchen::stop()
{
    _statusReq << std::string("quit");
}
