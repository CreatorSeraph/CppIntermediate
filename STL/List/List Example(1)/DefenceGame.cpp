#include "DefenceGame.h"


DefenceGame::DefenceGame()
	: _max_x(7)
	, _max_y(25)
	, m_playerPosition(_max_x / 2)
	, m_score(0)

	, m_gameFrame(0)
{
}
DefenceGame::~DefenceGame()
{
}



void DefenceGame::GameUpdate()
{
	if ((++m_gameFrame) == 8)
		m_gameFrame = 0;

	// 매 0, 2, 4, 6 프레임마다 플레이어 총알 업데이트
	if (m_gameFrame % 2 == 0)
	{
		for (ListNode* node = m_attackList.head(); node != m_attackList.tail();)
		{
			POINT& attackPos = node->data();
			--attackPos.y;

			// 탄환이 맵 끝에 닿으면 탄환 제거
			if (attackPos.y == 0)
			{
				node = m_attackList.erase(node);
				continue;
			}

			// 적 기체와의 충돌 체크 
			// 충돌시 탄환과 적 기체 모두 제거
			bool isCrashed = false;
			for (ListNode* enemyNode = m_enemyList.head(); enemyNode != m_enemyList.tail(); enemyNode = enemyNode->next())
			{
				if (attackPos.x == enemyNode->data().x &&
					attackPos.y == enemyNode->data().y)
				{
					m_enemyList.erase(enemyNode);
					isCrashed = true;
					
					++m_score;
					break;
				}
			}
			if (isCrashed)
			{
				node = m_attackList.erase(node);
				continue;
			}

			node = node->next();
		}
	}
	// 매 1프레임마다 적 기체 업데이트
	else if (m_gameFrame == 1)
	{
		for (ListNode* node = m_enemyList.head(); node != m_enemyList.tail();)
		{
			POINT& enemyPos = node->data();
			++enemyPos.y;

			// 맵 끝에 도달하면 기체를 삭제
			if (enemyPos.y == _max_y - 1)
				node = m_enemyList.erase(node);
			else
				node = node->next();
		}
	}
}


void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DefenceGame::GameRender()
{
	const int _gameOffsetY = 1;
	system("cls");
	std::cout << "SCORE : " << m_score;

	gotoxy(m_playerPosition * 2, _max_y + _gameOffsetY);
	std::cout << "▲";

	for (ListNode* node = m_enemyList.head(); node != m_enemyList.tail(); node = node->next())
	{
		gotoxy(node->data().x * 2, node->data().y + _gameOffsetY);
		std::cout << "■";
	}

	for (ListNode* node = m_attackList.head(); node != m_attackList.tail(); node = node->next())
	{
		gotoxy(node->data().x * 2, node->data().y + _gameOffsetY);
		std::cout << "※";
	}
}



void DefenceGame::PlayerMove(int movement)
{
	m_playerPosition += movement;
	while (m_playerPosition < 0)
		m_playerPosition += _max_x;
	while (m_playerPosition >= _max_x)
		m_playerPosition -= _max_x;
}

void DefenceGame::PlayerAttack()
{
	POINT pos;
	pos.x = m_playerPosition;
	pos.y = _max_y - 1;
	m_attackList.push_back(pos);
}



void DefenceGame::SummonEnemy()
{
	POINT pos;
	pos.x = rand() % _max_x;
	pos.y = 0;
	SummonEnemy(pos);
}

void DefenceGame::SummonEnemy(POINT position)
{
	m_enemyList.push_back(position);
}
