#include <thread>
#include "Semaphore.hpp"

Semaphore::Semaphore(int count) : _count(count) {}

void Semaphore::wait() {
	int old_count;
	while (true) {
		old_count =_count.load(std::memory_order_acquire);
		if (old_count > 0) {
			if (_count.compare_exchange_weak(old_count, old_count -1,
								std::memory_order_acquire, std::memory_order_relaxed)) {
				return;
			}
		}
		else {
			std::this_thread::yield();
		}
	}
}

void Semaphore::signal() {
	_count.fetch_add(1, std::memory_order_release);
}
