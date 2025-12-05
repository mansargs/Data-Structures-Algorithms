#pragma once

#include <atomic>

class SpinLock {
public:
    void lock();
    void unlock();
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

