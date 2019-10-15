#pragma once
// ������Ʈ List(1)�� List�� �״�� ���
#include "../List(1)/List.h"

#include <Windows.h>
#include <iostream>


class DefenceGame
{
public:
	using ListNode = List<POINT>::node;
	const int _max_x;
	const int _max_y;

	DefenceGame();
	~DefenceGame();


	// ���� ����
	void GameUpdate();
	void GameRender();


	// �÷��̾� ����
	void PlayerMoveL() { PlayerMove(-1); }
	void PlayerMoveR() { PlayerMove(+1); }
	void PlayerMove(int movement);
	void PlayerAttack();


	// �� ����
	void SummonEnemy();
	void SummonEnemy(POINT position);


private:
	List<POINT> m_enemyList;	// ���� ��ġ�� �����ϴ� ����Ʈ
	List<POINT> m_attackList;	// �÷��̾��� ������ ��ġ�� �����ϴ� ����Ʈ
	int m_playerPosition;		// �÷��̾� ��ġ
	int m_score;				// ����

	int m_gameFrame;
};

