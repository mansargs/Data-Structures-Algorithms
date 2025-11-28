#include <iostream>
#include <vector>

void allSubset(size_t index, std::vector<int> &nums, std::vector<int> &subset) {
	if (index == nums.size()) {
		std:: cout << "[";
		for (int i = 0; i < subset.size(); ++i) {
			std::cout << subset[i];
			if (i + 1 != subset.size()) {
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
		return;
	}
	allSubset(index + 1, nums, subset);

	subset.push_back(nums[index]);
	allSubset(index + 1, nums, subset);
	subset.pop_back();
}

int main()
{
	std::vector<int> nums;
	std::vector<int> subset;

	size_t n;

	std::cout << "Enter number of vector --->  ";
	std::cin >> n;

	int item;
	for (size_t i = 0; i < n; ++i) {
		std::cin >> item;
		nums.push_back(item);
	}
	allSubset(0, nums, subset);
}
