#pragma once

#include <atomic>

class Semaphore {
	public:
		explicit Semaphore(int count = 1);
		void wait();
		void signal();
	private:
		std::atomic<int> _count;
};
