#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool isvalid(std::vector<int> &pos, int row, int col) {
	for (int i = 0; i < row; ++i) {
		if (pos[i] == col || abs(i - row) == abs(pos[i] - col))
			return false;
	}
	return true;
}

void nQuenns(std::vector<int> &pos, size_t n, int row) {
	if (row == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < pos[i]; ++j) {
				std::cout << "* ";
			}
			std::cout << "Q ";
			for (int j = pos[i] + 1; j < n; ++j) {
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
		return ;
	}

	for (int i = 0; i < n; ++i) {
		if (!isvalid(pos, row, i))
			continue ;
		pos[row] = i;
		nQuenns(pos, n, row + 1);
		pos[row] = -1;
	}
}

int main() {
	size_t N;

	std::cout << "Enter matrix side --->  ";
	std::cin >> N;

	std::vector<int> pos;

	pos.resize(N);
	std::fill(pos.begin(), pos.end(), -1);
	nQuenns(pos, N, 0);
}
