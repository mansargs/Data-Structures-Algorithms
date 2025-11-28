#include <iostream>
#include <string>

void balanced(std::string s, int n, int open_count, int close_count) {
	if (s.length() == 2 * n) {
		std::cout << s << std::endl;
		return;
	}
	if (open_count < n) {
		s.push_back('(');
		balanced(s, n, open_count + 1, close_count);
		s.pop_back();
	}
	if (close_count < open_count) {
		s.push_back(')');
		balanced(s, n, open_count, close_count + 1);
		s.pop_back();
	}
}

int main() {
	int n;
	std::string s;

	std::cout << "Parenthesis count --->  ";
	std::cin >> n;
	balanced(s, n, 0, 0);
}
