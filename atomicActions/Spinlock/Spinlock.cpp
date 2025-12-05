#include <thread>
#include "Spinlock.hpp"

void SpinLock::lock() {
	while (flag.test_and_set(std::memory_order_acquire)) {
		std::this_thread::yield();
	}
}

void SpinLock::unlock() {
	flag.clear(std::memory_order_release);
}


