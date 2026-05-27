/*
** EPITECH PROJECT, 2026
** reception
** File description:
** Reception class
*/

#include "Reception.hpp"

Reception::Reception(std::size_t nbCooks, double mul, size_t time) :
    _nbCooks(nbCooks),
    _time(time),
    _mul(mul),
    _ipc(std::make_shared<IPC>())
{}

Reception::~Reception()
{
    for (size_t i = 0; i < _kitchens.size(); i++)
        _kitchens.erase(_kitchens.begin());
}


std::list<Plazza::PizzaOrder> Reception::parseOrder()
{
    LineParser orderparser;
    std::list<Plazza::PizzaOrder> orderlist;

    for (auto order : _parser.getWords()) {
        orderparser.ParseLine(order);
        try {
            if (orderparser[2].compare(0, 1, "x") != 0)
                throw std::exception();
            orderparser[2].erase(0, 1);
            std::size_t nbPizza = std::atoi(orderparser[2].c_str());
            if (_sizes[orderparser[1]] == 0)
                throw std::exception();
            for (size_t i = 0; i < nbPizza; i++) {
                orderlist.push_back(
                    _pizzaFunc[orderparser[0]](_sizes[orderparser[1]]));
            }
        } catch(const std::exception& e) {
            std::cout << "wrong syntax : " << orderparser.getLine() << std::endl;
        }
    }
    return orderlist;
}


void Reception::cleanKitchen()
{
    for (auto it = _kitchens.begin(); it != _kitchens.end();) {
        if (!(*it)->getStatus().is_alive)
            it = _kitchens.erase(it);
        else
            ++it;
    }
}

void Reception::sendOrder(std::list<Plazza::PizzaOrder> &orderList)
{
    if (_kitchens.empty()) {
        createKitchen(orderList.size());
    }
    while (!orderList.empty()) {
        auto bestKitchen = _kitchens.end();
        size_t maxCook = 0;

        for (auto it = _kitchens.begin(); it != _kitchens.end(); ++it) {
            KitchenStatus status = (*it)->getStatus();
            if (status.occupancy > maxCook) {
                maxCook = status.occupancy;
                bestKitchen = it;
            }
        }
        if (bestKitchen == _kitchens.end() || maxCook == 0) {
            createKitchen(1);
        }
        std::list<Plazza::PizzaOrder> order;
        order.push_back(orderList.front());
        orderList.pop_front();
        (*bestKitchen)->takeOrder(order);
    }
}

void Reception::run()
{
    Plazza::PizzaOrder order = {Plazza::Regina, Plazza::S};
    std::list<Plazza::PizzaOrder> orders;
    std::string commandLine;

    while (true) {
        _parser.readLineFrom(std::cin, ';');
        if (_parser.getLine() == "quit")
            break;
        std::list<Plazza::PizzaOrder> tmp = parseOrder();
        sendOrder(tmp);
    }
};

void Reception::createKitchen(std::size_t nbKitchen)
{
    for (std::size_t i = 0; i < nbKitchen; i++) {
        _kitchens.push_back(std::make_unique<Kitchen>(_nbCooks, _mul, _time));
    }
}
