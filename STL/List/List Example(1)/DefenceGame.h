#pragma once
// 프로젝트 List(1)의 List를 그대로 사용
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


	// 게임 제어
	void GameUpdate();
	void GameRender();


	// 플레이어 제어
	void PlayerMoveL() { PlayerMove(-1); }
	void PlayerMoveR() { PlayerMove(+1); }
	void PlayerMove(int movement);
	void PlayerAttack();


	// 적 제어
	void SummonEnemy();
	void SummonEnemy(POINT position);


private:
	List<POINT> m_enemyList;	// 적의 위치를 저장하는 리스트
	List<POINT> m_attackList;	// 플레이어의 공격의 위치를 저장하는 리스트
	int m_playerPosition;		// 플레이어 위치
	int m_score;				// 점수

	int m_gameFrame;
};

