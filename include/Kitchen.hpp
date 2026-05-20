/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_
    #include <queue>
    #include <vector>
    #include "Order.hpp"
    #include "Cook.hpp"
    #include "IPC.hpp"
    #include <list>
    #include <memory>

class Kitchen
{
    private:
        std::size_t _nbCooks;
        std::vector<std::unique_ptr<Cook>> _cooks;
        std::size_t _currLoad;
        std::queue<Plazza::PizzaOrder> _waitingOrders;
        IPC _ipc;
        pid_t _pid;

    public:
        Kitchen(std::size_t nbCooks);
        ~Kitchen();

        bool takeOrder(std::list<Plazza::PizzaOrder> &orders);
        void sendPizza(Plazza::PizzaOrder &order);
        void run();
};

#endif /* !KITCHEN_HPP_ */
