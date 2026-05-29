/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** KitchenStatus
*/

#ifndef KITCHENSTATUS_HPP_
    #define KITCHENSTATUS_HPP_
    #include <unordered_map>
    #include "Order.hpp"

struct KitchenStatus
{
    bool is_alive;
    size_t occupancy;
    std::unordered_map<Plazza::Ingredient, size_t> remaining_stock;
};

#endif /* !KITCHENSTATUS_HPP_ */
