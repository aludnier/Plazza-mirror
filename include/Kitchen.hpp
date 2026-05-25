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
    #include "Process.hpp"
    #include <functional>

class Kitchen
{
    private:
        Process<std::function<void()>> _process;
        std::size_t _nbCooks;
        std::vector<std::unique_ptr<Cook>> _cooks;
        std::size_t _currLoad;
        std::queue<Plazza::PizzaOrder> _waitingOrders;
        IPC _ipc;

    public:
        Kitchen(size_t nbCooks, size_t mul);
        ~Kitchen();

        bool takeOrder(std::list<Plazza::PizzaOrder> &orders);
        void sendPizza(Plazza::PizzaOrder &order);
        void run();
        std::size_t getPID() { return _process.getPid();};
};

#endif /* !KITCHEN_HPP_ */
