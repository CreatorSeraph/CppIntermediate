#include "TowerOfHanoi.h"

#define DIFFICULT 5
int main()
{
	TowerOfHanoi<DIFFICULT> hanoi;
	size_t inputA, inputB;

	while(true)
	{
		gotoxy(0, 0);
		std::cout << "원판을 꺼낼 막대 : ";
		std::cin >> inputA;
		gotoxy(0, 0);
		std::cout << "                              ";
		gotoxy(0, 0);
		std::cout << "원판을 넣을 막대 : ";
		std::cin >> inputB;
		gotoxy(0, 0);
		std::cout << "                              ";

		if (hanoi.MovePlate(inputA, inputB))
		{
			if (hanoi.CheckSucceeded())
				break;
		}
		else
		{
			gotoxy(0, 0);
			std::cout << "잘못된 입력입니다." << std::endl;
			Sleep(1000);
		}
	}

	gotoxy(0, DIFFICULT + 1);
	std::cout << "클리어" << std::endl;
	std::cout << "난이도 : " << DIFFICULT << std::endl;
}