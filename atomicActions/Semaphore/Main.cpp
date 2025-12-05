	#include <iostream>
	#include <thread>
	#include <vector>
	#include <atomic>
	#include "Semaphore.hpp"
	#include "../Spinlock/Spinlock.hpp"

	SpinLock m;

	void worker(int id, Semaphore &sem, std::atomic<int> &inside_count) {
		sem.wait();
		int current_inside = ++inside_count;
		m.lock();
		std::cout << "Thread " << id << " entered. Inside count: " << current_inside << std::endl;
		m.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		current_inside = --inside_count;
		m.lock();
		std::cout << "Thread " << id << " leaving. Inside count: " << current_inside << std::endl;
		m.unlock();
		sem.signal();
	}

	int main() {
		const int NUM_THREADS = 10;
		const int MAX_INSIDE = 3;
		Semaphore sem(MAX_INSIDE);
		std::atomic<int> inside_count{0};

		std::vector<std::thread> threads;
		for (int i = 0; i < NUM_THREADS; ++i) {
			threads.emplace_back(worker, i, std::ref(sem), std::ref(inside_count));
		}
		for (auto &t : threads) {
			t.join();
		}
		std::cout << "All threads finished." << std::endl;
		return 0;
	}
