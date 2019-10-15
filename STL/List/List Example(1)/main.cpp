#include "DefenceGame.h"

// �ܼ�â ũ�� ����
#include <Windows.h>
void SetConsoleSize(size_t x, size_t y);

int main()
{
	SetConsoleSize(200, 500);
	DefenceGame game;


	// ���� ����
	// ESC �Է½� ����
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		// 10ms���� ���� ������Ʈ
		Sleep(10);

		// �÷��̾� ����
		if (GetAsyncKeyState(VK_LEFT))
			game.PlayerMoveL();
		if (GetAsyncKeyState(VK_RIGHT))
			game.PlayerMoveR();
		if (GetAsyncKeyState(VK_SPACE))
			game.PlayerAttack();

		// �� ��ü ����
		if (!(rand() % 8))
			game.SummonEnemy();

		// ���� ������Ʈ, ������
		game.GameUpdate();
		game.GameRender();
	}
	return 0;
}

void SetConsoleSize(size_t x, size_t y)
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}
