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
    msgctl(_id, IPC_RMID, nullptr);
}

IPC &IPC::operator<<(const std::string &msg)
{
    Buffer buff;

    buff.text.reserve(msg.size());
    buff.type = 1;
    strncpy(buff.text.data(), msg.c_str(), msg.size());
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(std::string &msg)
{
    Buffer buff;

    if (msgrcv(_id, &buff, sizeof(buff.text), 1, IPC_NOWAIT) == -1)
        throw IPCError("msgrcv failed.");
    msg = buff.text.data();
    return *this;
}

IPC &IPC::operator<<(const Plazza::PizzaOrder &order)
{
    Buffer buff;

    buff.type = 1;
    buff.text << order;
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(Plazza::PizzaOrder &order)
{
    Buffer buff;

    if (msgrcv(_id, &buff, sizeof(buff.text), 1, IPC_NOWAIT) == -1)
        throw IPCError("msgrcv failed.");
    buff.text >> order;
    return *this;
}
