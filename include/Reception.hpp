/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_
    #include <cstddef>
    #include <deque>
    #include <list>
    #include <unistd.h>
    #include <unordered_map>
    #include "Order.hpp"
    #include "LineParser.hpp"
    #include "Kitchen.hpp"
    #include "functional"
    #include "IPC.hpp"

class Reception
{
public:
    Reception(std::size_t nbCooks, double mul, size_t time);
    ~Reception();

    std::list<Plazza::PizzaOrder> parseOrder();
    void run();
    void createKitchen(std::size_t nbKitchen);
    void sendOrder(std::list<Plazza::PizzaOrder> &orderList);
    void cleanKitchen();
    void printStatus();

private:
    std::size_t _nbCooks;
    std::size_t _time;
    std::vector<std::unique_ptr<Kitchen>> _kitchens;
    LineParser _parser;
    std::shared_ptr<IPC> _ipc;
    double _mul;

    std::unordered_map<std::string, std::function<Plazza::PizzaOrder(Plazza::PizzaSize)>> _pizzaFunc =  {
        {"Regina", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::ReginaOrder(size);}},
        {"Margarita", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::MargaritaOrder(size);}},
        {"Americana", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::AmericanaOrder(size);}},
        {"Fantasia", [](Plazza::PizzaSize size) -> Plazza::PizzaOrder {return Plazza::FantasiaOrder(size);}}
    };

    std::unordered_map<std::string, Plazza::PizzaSize> _sizes = {
        {"S", Plazza::S},
        {"M", Plazza::M},
        {"L", Plazza::L},
        {"XL", Plazza::XL},
        {"XXL", Plazza::XXL}
    };
};

#endif /* !RECEPTION_HPP_ */
