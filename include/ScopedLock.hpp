

#include "Mutex.hpp"

class ScopedLock
{
private:
    Mutex *_mutex;
public:
    ScopedLock(Mutex &mutex);
    ~ScopedLock();
};

ScopedLock::ScopedLock(Mutex &mutex):
    _mutex(&mutex)
{
    _mutex->lock();
}

ScopedLock::~ScopedLock()
{
    _mutex->unlock();
}
