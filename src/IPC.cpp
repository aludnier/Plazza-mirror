/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** IPC
*/

#include "IPC.hpp"

IPC::IPC()
{
    _key = std::rand();
    _id = msgget(_key, 0666 | IPC_CREAT);
    if (_id == -1)
        throw IPCError("msgget failed.");
}

IPC::~IPC()
{
    std::cout << "[IPC] destroy queue" << std::endl;
    msgctl(_id, IPC_RMID, nullptr);
}

IPC &IPC::operator<<(const std::string &msg)
{
    Buffer buff;

    buff.type = 1;
    strncpy(buff.text, msg.c_str(), BUFFER_SIZE - 1);
    buff.text[BUFFER_SIZE - 1] = '\0';
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(std::string &msg)
{
    Buffer buff;

    if (msgrcv(_id, &buff.text, sizeof(buff.text), 1, IPC_NOWAIT) == -1)
        throw IPCError("msgrcv failed.");
    msg = std::string(buff.text);
    return *this;
}

IPC &IPC::operator<<(const Plazza::PizzaOrder &order)
{
    Buffer buff;
    std::vector<char> pack;

    buff.type = 1;
    pack << order;
    if (pack.size() > BUFFER_SIZE)
        throw IPCError("Order too large for buffer.");
    memcpy(buff.text, pack.data(), pack.size());
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1) {
        throw IPCError("msgsnd failed.");
    }
    return *this;
}

IPC &IPC::operator>>(Plazza::PizzaOrder &order)
{
    Buffer buff;
    ssize_t size = msgrcv(_id, &buff, sizeof(buff.text), 1, 0);

    if (size == -1)
        throw IPCError("msgrcv failed.");
    std::vector<char> pack(buff.text, buff.text + strlen(buff.text));
    pack >> order;
    return *this;
}
