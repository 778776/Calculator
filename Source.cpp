#include <iostream>
#include <string>
#include <vector>

void tokenizer(std::string a) {
	std::vector<std::string> b(10);
	int last_pos = 0;
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
			b[j] = a.substr(last_pos, i - last_pos);
			b[j + 1] = a[i];
			last_pos = i + 1;
			j += 2;
		}
	}
	b[j + 1] = a.substr(last_pos, a.size() - last_pos);
	for (int i = 0; i < b.size(); i++) {
		std::cout << b[i] << std::endl;
	}
}


int main() {
	std::string a;
	std::getline(std::cin, a);
	tokenizer(a);
	system("pause");
	return 0;
}

