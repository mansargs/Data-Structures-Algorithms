#include <iostream>
#include <string>

void generate(std::string &current, int n, const std::string &chars) {
    if (current.length() == n) {
        std::cout << current << std::endl;
        return;
    }

    for (char c : chars) {
        current.push_back(c);
        generate(current, n, chars);
        current.pop_back();
    }
}

int main() {
    int n = 3;
    std::string current;
    std::string chars = "AB"; 

    generate(current, n, chars);
}
