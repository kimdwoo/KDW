﻿﻿#include <iostream>

// namespace std;

int main()
{
	int num = 0;
	std::string name;
	std::cout << "김동우:힘들다..." << std::endl;

	while (num != 18)
	{
		std::cout << "나쁜놈의 이름과 나이를 입력하세요: ";
		std::cin >> name >> num;
	}

	std::cout << "나보다 " << num << "살이나 어린주제에..." << name << "나쁜련..." << std::endl;


	return 0;
}