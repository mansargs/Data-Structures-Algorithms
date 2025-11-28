#include <iostream>
#include <vector>
#include <numeric>

void permut(std::vector<int> &num, size_t index) {
	if (index == num.size()) {
		std::cout << "[";
		for (int i = 0; i < num.size(); ++i) {
			std::cout << num[i];
			if (i + 1 != num.size()) std::cout << ", ";
		}
		std::cout << "]\n";
		return;
	}
	for (int i = index; i < num.size(); ++i) {
		std::swap(num[i], num[index]);
		permut(num, index + 1);
		std::swap(num[i], num[index]);
	}
}

int main () {
	size_t n;
	std::vector <int> num;

	std::cout << "n = ";
	std::cin >> n;
	num.resize(n);
	std::iota(num.begin(), num.end(), 1);
	permut(num, 0);
}
