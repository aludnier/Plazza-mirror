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
    _id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
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

    if (msgrcv(_id, &buff, sizeof(buff.text), 1, IPC_NOWAIT) == -1)
        throw IPCError("msgrcv failed.");
    msg = std::string(buff.text);
    return *this;
}

IPC &IPC::operator<<(const Plazza::PizzaOrder &order)
{
    Buffer buff;
    std::vector<char> pack;
    size_t size;

    buff.type = 1;
    pack << order;
    if (pack.size() > BUFFER_SIZE)
        throw IPCError("Order too large for buffer.");
    size = pack.size();
    memcpy(buff.text, &size, sizeof(size_t));
    memcpy(buff.text + sizeof(size_t), pack.data(), size);
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(Plazza::PizzaOrder &order)
{
    Buffer buff;
    size_t size;
    ssize_t received = msgrcv(_id, &buff, sizeof(buff.text), 1, IPC_NOWAIT);

    if (received == -1)
        throw IPCError("msgrcv failed.");
    memcpy(&size, buff.text, sizeof(size_t));
    std::vector<char> pack(buff.text + sizeof(size_t), buff.text + sizeof(size_t) + size);
    pack >> order;
    return *this;
}

IPC &IPC::operator<<(const KitchenStatus &status)
{
    Buffer buff;
    size_t offset = 0;
    size_t stockSize;

    buff.type = 1;
    memcpy(buff.text + offset, &status.is_alive, sizeof(bool));
    offset += sizeof(bool);
    memcpy(buff.text + offset, &status.occupancy, sizeof(size_t));
    offset += sizeof(size_t);
    stockSize = status.remaining_stock.size();
    memcpy(buff.text + offset, &stockSize, sizeof(size_t));
    offset += sizeof(size_t);
    for (const auto &[ingredient, qty] : status.remaining_stock) {
        memcpy(buff.text + offset, &ingredient, sizeof(Plazza::Ingredient));
        offset += sizeof(Plazza::Ingredient);
        memcpy(buff.text + offset, &qty, sizeof(size_t));
        offset += sizeof(size_t);
    }
    if (msgsnd(_id, &buff, sizeof(buff.text), IPC_NOWAIT) == -1)
        throw IPCError("msgsnd failed.");
    return *this;
}

IPC &IPC::operator>>(KitchenStatus &status)
{
    Buffer buff;
    size_t offset = 0;
    size_t stockSize;

    if (msgrcv(_id, &buff, sizeof(buff.text), 1, 0) == -1)
        throw IPCError("msgrcv failed.");
    memcpy(&status.is_alive, buff.text + offset, sizeof(bool));
    offset += sizeof(bool);
    memcpy(&status.occupancy, buff.text + offset, sizeof(size_t));
    offset += sizeof(size_t);
    memcpy(&stockSize, buff.text + offset, sizeof(size_t));
    offset += sizeof(size_t);
    for (size_t i = 0; i < stockSize; i++) {
        Plazza::Ingredient ingredient;
        size_t qty;
        memcpy(&ingredient, buff.text + offset, sizeof(Plazza::Ingredient));
        offset += sizeof(Plazza::Ingredient);
        memcpy(&qty, buff.text + offset, sizeof(size_t));
        offset += sizeof(size_t);
        status.remaining_stock[ingredient] = qty;
    }
    return *this;
}
