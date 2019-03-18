#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string a) {
	std::vector<std::string> b;
	int last_pos = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
			b.push_back(a.substr(last_pos, i - last_pos));
			b.push_back(a[i];
			last_pos = i + 1;
		}
	}
	b.push_back(a.substr(last_pos, a.size() - last_pos));
	return b;
}

int main() {
	std::string a;
	std::getline(std::cin, a);
	std::vector<std::string> mem = tokenize(a);
	for (int i = 0; i < mem.size() - 1; i++)
	{
		std::cout << mem[i] << oper[i];
	}
	system("pause");
	return 0;
}

