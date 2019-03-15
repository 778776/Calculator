#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenizer(std::string a) {
	std::vector<std::string> b(a.size());
	int last_pos = 0;
	int j = 0;
	int f = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*') {
			b[j] = a.substr(last_pos, i - last_pos);
			b[j + 1] = a[i];
			last_pos = i + 1;
			j += 2;
		}
	}
	b[j + 1] = a.substr(last_pos, a.size() - last_pos);
	return b;
}

std::vector<std::string> validate(std::vector<std::string> a,std::vector<std::string> oper) {
	std::vector<std::string> mem(a.size());
	std::string errorLine;
	for (int i = 0; i < a.size(); i+=2) {
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] == '0' || a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3' || a[i][j] == '4' || a[i][j] == '5' || a[i][j] == '6' || a[i][j] == '7' || a[i][j] == '8' || a[i][j] == '9' || a[i][j] == '.' || a[i][j] == ' ')
			{
				mem[i] += a[i][j];
			}
			else
				errorLine += a[i][j];
		}

	}
	int num = 0;
	for (int i = 1; i < a.size(); i+=2)
	{
		oper[num] = a[i];
		num++;
	}
	mem[mem.size() - 1] = errorLine;
	return mem;
}
int main() {
	std::string a;
	std::getline(std::cin, a);
	std::vector<std::string> oper(10);
	std::vector<std::string> mem = validate((tokenizer(a)),oper);
	for (int i = 0; i < mem.size() - 1; i++)
	{
		std::cout << mem[i] << oper[i];
	}
	std::cout << mem[mem.size() - 2];
	std::cout << " please correct the command (" << mem[mem.size() - 1] << ")";
	system("pause");
	return 0;
}

