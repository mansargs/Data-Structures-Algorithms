#include <iostream>
#include <vector>
#include <thread>
#include "Spinlock.hpp"

SpinLock lock;

void thread_task(int id, int messages) {
	for (int i = 0; i < messages; ++i) {
		lock.lock();
		std::cout << "Thread " << id << ": message " << i << std::endl;
		lock.unlock();
	}
}

int main() {
	const int N = 4;
	const int M = 10;
	std::vector<std::thread> threads;

	for (int i = 0; i < N; ++i) {
		threads.emplace_back(thread_task, i, M);
	}
	for (auto &t : threads) {
		t.join();
	}
	std::cout << "All threads finished!" << std::endl;
	return 0;
}
