#include <iostream>

int main() {
	float x, y;
	char a;
	std::cout << "use the formula (x + y)(x - y)(x * y)(x / y)" << std::endl;
	for (int i = 1; i < 10; i++)
	{
		std::cout << i << ")";
		std::cin >> x;
		std::cin >> a;
		std::cin >> y;
		float result;
		switch (a) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		default:
			std::cout << "operator isn't correct, please use one of these + - * / operators " << std::endl;;
		}
		std::cout << x << a << y << "=" << result << std::endl;
	}
	
	system("pause");
	return 0;

}