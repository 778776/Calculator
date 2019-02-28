#include <iostream>
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
				mem1 += a.substr(i, 1);
			}
			for (int j = pos + 1; j < size; j++) {
				mem2 += a.substr(j, 1);
			}
		}

	}
};

class getErrors {
public:
	std::string mem1, mem2, errorLine;
	void getErors(std::string a, std::string b) {
		int size1 = a.size();
		int size2 = b.size();
		for (int i = 0; i < size1; i++) {
			if (a[i] == '.' || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9' || a[i] == ' ') {
				mem1 += a.substr(i, 1);
			}
			else {
				errorLine += a.substr(i, 1);
			}
		}
		for (int i = 0; i < size2; i++) {
			if (b[i] == '.' || b[i] == '0' || b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4' || b[i] == '5' || b[i] == '6' || b[i] == '7' || b[i] == '8' || b[i] == '9' || b[i] == ' ') {
				mem2 += b.substr(i, 1);
			}
			else {
				errorLine += b.substr(i, 1);
			}
		}
	}
};


int main() {

	std::cout << "enter your command" << std::endl;
	for (int i = 1; i < 10; i++) {
		std::cout << i << ")";
		std::string a;
		std::getline(std::cin, a);
		Parser b;
		b.Parse(a);
		char oper = b.oper;

		getErrors d;
		d.getErors(b.mem1, b.mem2);
		if (d.errorLine.size() > 0) {
			std::cout << "please correct your command (" << d.errorLine << ")" << std::endl;
		}
		else if (d.mem1.size() > 0 && d.mem2.size() > 0) {
			float mem1 = stof(d.mem1);
			float mem2 = stof(d.mem2);
			float result;
			switch (oper) {
			case '+':
				result = mem1 + mem2;
				break;
			case '-':
				break;
				result = mem1 - mem2;
				break;
			case '/':
				result = mem1 / mem2;
				break;
			case '*':
				result = mem1 * mem2;
				break;
			}
			std::cout << mem1 << oper << mem2 << " = " << result << std::endl;
		}
	}
	system("pause");
	return 0;
}


