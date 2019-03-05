#include <iostream>
#include <vector>
#include <string>



class Parser {
public:
	std::string mem1; std::string mem2; char oper;
	std::string a;
public:
	void Parse(std::string a) {
		int size = a.size();
		int pos = a.find("-");
		if (pos == -1) {
			pos = a.find("+");
		}
		if (pos == -1) {
			pos = a.find("*");
		}
		if (pos == -1) {
			pos = a.find("/");
		}
		if (pos == -1) {
			std::cout << "please use the operator" << std::endl;
		}
		else {
			oper = a[pos];
			for (int i = 0; i < pos; i++) {
				mem1 += a.substr(i);
			}
			for (int j = pos + 1; j < size; j++) {
				mem2 += a.substr(j);
			}
		}
	}
};



class getErrors {
public:
	std::string errorLine;
	std::vector<std::string> mem;
	void getErors(std::vector<std::string> mem) {
		for (int j = 0; j < mem.size(); j++)
		{
			for (int i = 0; i < mem[j].size(); i++) {
				if (mem[j][i] == '.' || mem[j][i] == '0' || mem[j][i] == '1' || mem[j][i] == '2' || mem[j][i] == '3' || mem[j][i] == '4' || mem[j][i] == '5' || mem[j][i] == '6' || mem[j][i] == '7' || mem[j][i] == '8' || mem[j][i] == '9' || mem[j][i] == ' ') {
					mem[j] += mem[j][i];
				}
				else {
					errorLine += mem[j][i];
				}
			}
		}
	}
};

	std::vector<std::string> tokenizer(std::string a) {
		int size = a.size();
		int token_count = 0;
		
		int j = 1;
		for (int i = 0; i < size; i++) {
			if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				token_count++;
			}
		}
		std::vector<int> pos(token_count + 2);
		for (int i = 0; i < size; i++) {
			if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
				pos[j] = i;
				j++;
			}
		}
		pos[0] = 0;
		std::vector<std::string> mem(token_count + 1);
		mem[0] = a.substr(0, pos[1]);
		for (int i = 1; i <= token_count; i++) {
			mem[i] = a.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1);
		}
		return mem;
	}

	int main() {

		std::cout << "enter your command" << std::endl;
		for (int i = 1; i < 10; i++) {
			std::cout << i << ")";
			std::string a;
			std::getline(std::cin, a);
			std::vector<std::string> mem = tokenizer(a);
			getErrors d;
			d.getErors(mem);
			mem = d.mem;
			if (d.errorLine.size() > 0) {
				std::cout << "please correct your command (" << d.errorLine << ")" << std::endl;
			}
			else
				for (int i = 0; i < mem.size(); i++)
				{
					std::cout << mem[i] << std::endl;
				}

			system("pause");
			return 0;
		}
	}

