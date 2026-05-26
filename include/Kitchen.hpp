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

struct KitchenStatus
{
    size_t occupancy;
    std::unordered_map<Plazza::Ingredient, size_t> remaining_stock;
};

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
        KitchenStatus getStatus() const;
        // std::shared_ptr<std::unordered_map<Plazza::Ingredient, size_t>> stock;
        std::unordered_map<Plazza::Ingredient, size_t> stock;
};

#endif /* !KITCHEN_HPP_ */
