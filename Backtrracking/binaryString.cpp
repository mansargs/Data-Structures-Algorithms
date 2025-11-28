#include <iostream>
#include <string>

void binaryString(std::string &s, size_t i, size_t len) {
	if (i == len) {
		std::cout << s << std::endl;
		return ;
	}
	s[i] = '0';
	binaryString(s, i + 1, len);
	s[i] = '1';
	binaryString(s, i + 1, len);
}

int main() {
	std::string s;
	size_t n;

	std:: cout << "Enter the string lenght --->  ";
	std:: cin >> n;
	s.resize(n);
	binaryString(s, 0, n);
	return 0;
}
