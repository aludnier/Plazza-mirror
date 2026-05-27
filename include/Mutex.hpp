/*
** EPITECH PROJECT, 2026
** plazza-mirror
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_

extern "C"
{
    #include <pthread.h>
}

class IMutex
{
    public:
        virtual ~IMutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual void trylock() = 0;
};

class Mutex : public IMutex
{
private:
    pthread_mutex_t _mutex;
public:
    Mutex() { pthread_mutex_init(&_mutex, NULL); };
    ~Mutex() { pthread_mutex_destroy(&_mutex); };
    void lock() override { pthread_mutex_lock(&_mutex); };
    void unlock() override { pthread_mutex_unlock(&_mutex); };
    void trylock() override { pthread_mutex_trylock(&_mutex); };
};

#endif /* !MUTEX_HPP_ */
