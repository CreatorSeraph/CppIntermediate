#include "TowerOfHanoi.h"

#define DIFFICULT 5
int main()
{
	TowerOfHanoi<DIFFICULT> hanoi;
	size_t inputA, inputB;

	while(true)
	{
		gotoxy(0, 0);
		std::cout << "������ ���� ���� : ";
		std::cin >> inputA;
		gotoxy(0, 0);
		std::cout << "                              ";
		gotoxy(0, 0);
		std::cout << "������ ���� ���� : ";
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
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			Sleep(1000);
		}
	}

	gotoxy(0, DIFFICULT + 1);
	std::cout << "Ŭ����" << std::endl;
	std::cout << "���̵� : " << DIFFICULT << std::endl;
}