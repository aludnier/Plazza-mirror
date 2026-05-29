/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_
    #include "Order.hpp"
    #include <string>
    #include <sys/msg.h>
    #include <sys/ipc.h>
    #include <string.h>
    #include <vector>
    #include "KitchenStatus.hpp"
    #define BUFFER_SIZE 512

struct Buffer
{
    long type;
    char text[BUFFER_SIZE];
};

class IPC
{
    private:
        key_t _key;
        int _id;

    public:
        IPC();
        ~IPC();

        IPC &operator<<(const std::string &msg);
        IPC &operator>>(std::string &msg);
        IPC &operator<<(const Plazza::PizzaOrder &order);
        IPC &operator>>(Plazza::PizzaOrder &order);
        IPC &operator<<(const KitchenStatus &status);
        IPC &operator>>(KitchenStatus &status);

        class IPCError : public std::exception {
            private:
                std::string _msg;
            public:
                IPCError(std::string msg): _msg("[IPC Error] : " + msg) {};
                const char *what() const noexcept override {
                    return _msg.data();
                };
        };
};

#endif /* !IPC_HPP_ */
