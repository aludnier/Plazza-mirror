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
    #define BUFFER_SIZE 512

struct Buffer
{
    long type;
    // char text[BUFFER_SIZE];
    std::vector<char> text;
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
