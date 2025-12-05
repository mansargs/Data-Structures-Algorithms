#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

void producer_handler(std::atomic<int> &counter, int increments) {
	for (int i = 0; i < increments; ++i) {
		counter.fetch_add(1, std::memory_order_relaxed);
	}
}

void consumer_handler(std::atomic<int> &counter, std::atomic<bool> &done) {
	while (!done.load(std::memory_order_acquire));
	std::cout << "Final counter value: " << counter.load() << std::endl;
}

int main() {
	int N, M;
	std::cout << "Enter number of producer threads (N): ";
	std::cin >> N;
	std::cout << "Enter increments per thread (M): ";
	std::cin >> M;

	std::atomic<int> counter{0};
	std::atomic<bool> done{false};
	std::vector<std::thread> producers;
	producers.reserve(N);
	for (int i = 0; i < N; ++i) {
		producers.emplace_back(producer_handler, std::ref(counter), M);
	}
	std::thread consumer(consumer_handler, std::ref(counter), std::ref(done));
	for (auto &t : producers) {
		t.join();
	}
	done.store(true, std::memory_order_release);
	consumer.join();
	return 0;
}
