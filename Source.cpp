#include <iostream>
#include <string>
#include <vector>

class Calculator
{
public:
	void evaluate(const std::string & a)
	{
		// TODO: clean whitespaces from tokenize
		// TODO: fix/remove empty tokens
		tokenize(a);
		for (auto& a : m_tokens)
		{
			std::cout << a << "  ";
		}
		// TODO: implement validate()
		validate();
		// evaluate();
	}

	void validate() {
		// 3a + 5 + c -> !ERROR< 3a >! + 5 + !ERROR< c >!
	}
	void tokenize(const std::string & a)
	{
		int last_pos = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*')
			{
				m_tokens.push_back(a.substr(last_pos, i - last_pos));
				m_tokens.push_back(a.substr(i, 1));
				last_pos = i + 1;
			}
		}
		m_tokens.push_back(a.substr(last_pos, a.size() - last_pos));
	}

private:
	std::vector < std::string > m_tokens{};

};


int main()
{
	std::string a;
	std::getline(std::cin, a);

	Calculator c;
	c.evaluate(a);
	system("pause");
	return 0;
}
