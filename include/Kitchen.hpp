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
    #include "KitchenStatus.hpp"

class Kitchen
{
    private:
        double _timeMult;
        Process<std::function<void()>> _process;
        std::size_t _nbCooks;
        std::vector<std::unique_ptr<Cook>> _cooks;
        std::size_t _currLoad;
        std::queue<Plazza::PizzaOrder> _waitingOrders;
        IPC _ipc;
        IPC _statusReq;
        IPC _statusReply;
        std::chrono::time_point<std::chrono::system_clock> _timeOut;
        bool _isAlive;
        Mutex _stockMutex;

    public:
        Kitchen(size_t nbCooks, double mul, size_t time);
        ~Kitchen();

        bool takeOrder(std::list<Plazza::PizzaOrder> &orders);
        void sendPizza(Plazza::PizzaOrder &order);
        void run();
        bool runOut();
        std::size_t getPID() { return _process.getPid();};
        KitchenStatus getStatus();
        KitchenStatus buildStatus();
        bool hasCapacity() const { return _currLoad < 2 * _nbCooks; }
        void stop();
        std::unordered_map<Plazza::Ingredient, size_t> stock = {
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

#endif /* !KITCHEN_HPP_ */
