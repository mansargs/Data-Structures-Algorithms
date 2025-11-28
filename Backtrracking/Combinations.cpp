#include <iostream>
#include <vector>

void combination(std::vector<int> &num, int start, int n, int k) {
    if (num.size() == k) {
        std::cout << "[";
        for (int i = 0; i < num.size(); ++i) {
            std::cout << num[i];
            if (i + 1 != num.size()) std::cout << ", ";
        }
        std::cout << "]\n";
        return;
    }

    for (int i = start; i < n; ++i) {
        num.push_back(i);
        combination(num, i + 1, n, k);
        num.pop_back();
    }
}

int main() {
    int n = 8, k = 4;
    std::vector<int> num;
    combination(num, 0, n, k);
}
