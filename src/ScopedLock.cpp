/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex):
    _mutex(&mutex)
{
    _mutex->lock();
}

ScopedLock::~ScopedLock()
{
    _mutex->unlock();
}
