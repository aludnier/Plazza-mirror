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
    strncpy(buff.text, msg.c_str(), msg.size());
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(std::string &msg)
{
    Buffer buff;

    if (msgrcv(_id, &buff.text, sizeof(buff.text), 1, IPC_NOWAIT) == -1)
        throw IPCError("msgrcv failed.");
    msg = buff.text;
    return *this;
}

IPC &IPC::operator<<(const Plazza::PizzaOrder &order)
{
    Buffer buff;
    std::vector<char> tmp;

    buff.type = 1;
    tmp << order;
    memcpy(buff.text, tmp.data(), tmp.size());
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(Plazza::PizzaOrder &order)
{
    Buffer buff;
    
    buff.type = 1;
    if (msgrcv(_id, &buff, sizeof(buff.text), 1, 0) == -1){
        std::cout << "[IPC] Error" << std::endl;
        throw IPCError("msgrcv failed.");
    }
    std::vector<char> tmp;
    for (size_t i = 0; i < strlen(buff.text); i++) {
        tmp.push_back(buff.text[i]);
    }
    tmp >> order;
    return *this;
}
