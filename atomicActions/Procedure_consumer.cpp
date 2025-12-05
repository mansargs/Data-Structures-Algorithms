#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> data{0};
std::atomic<bool> ready{false};

void thread1() {
	data = 100;
	ready.store(true, std::memory_order_release);
}

void thread2() {
	while (!ready.load(std::memory_order_acquire));
	std::cout << "Data: " << data.load() << std::endl;
}

int main() {
	std::thread t1(thread1);
	std::thread t2(thread2);

	t1.join();
	t2.join();
	return 0;
}
