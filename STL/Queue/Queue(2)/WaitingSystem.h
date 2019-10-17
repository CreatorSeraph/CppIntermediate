#pragma once
// 프로젝트 Queue(1)의 Queue.h를 그대로 사용
#include "../Queue(1)/Queue.h"
#include <string>

/*
	호출시 이름을 사용하며
	최대 4명까지 대기 할 수 있는
	간단한 대기열 시스템을 만듦.
*/
class WaitingSystem
{
public:
	using String = std::string;
	WaitingSystem() {}
	~WaitingSystem() {}


	// 대기열 등록
	bool Register(String customerName);

	// 대기열 내 대기자를 불러옴
	String Call();

private:
	// 문자열을 데이터로 삼는 4칸 크기의 큐를 사용
	Queue<String, 4> m_waitingList;
};

