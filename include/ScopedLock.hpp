/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
    #define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

class ScopedLock
{
    private:
        Mutex *_mutex;

    public:
        ScopedLock(Mutex &mutex);
        ~ScopedLock();
};

#endif /* !SCOPEDLOCK_HPP_ */
