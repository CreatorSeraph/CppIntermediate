#include "DefenceGame.h"

// 콘솔창 크기 설정
#include <Windows.h>
void SetConsoleSize(size_t x, size_t y);

int main()
{
	SetConsoleSize(200, 500);
	DefenceGame game;


	// 게임 루프
	// ESC 입력시 종료
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		// 10ms마다 게임 업데이트
		Sleep(10);

		// 플레이어 제어
		if (GetAsyncKeyState(VK_LEFT))
			game.PlayerMoveL();
		if (GetAsyncKeyState(VK_RIGHT))
			game.PlayerMoveR();
		if (GetAsyncKeyState(VK_SPACE))
			game.PlayerAttack();

		// 적 기체 생성
		if (!(rand() % 8))
			game.SummonEnemy();

		// 게임 업데이트, 렌더링
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
