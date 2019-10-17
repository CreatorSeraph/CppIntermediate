#include "WaitingSystem.h"
#include <iostream>

bool WaitingSystem::Register(String customerName)
{
	if (m_waitingList.size() == m_waitingList.max_size())
	{
		std::cout << "더이상 대기열에 추가할 수 없음." << std::endl;
		return false;
	}

	m_waitingList.push(customerName);
	std::cout << "대기열에 추가됨 : " << customerName << std::endl;
	return true;
}

WaitingSystem::String WaitingSystem::Call()
{
	if (m_waitingList.empty())
	{
		std::cout << "더이상 대기자가 존재하지 않음." << std::endl;
		return "";
	}

	String temp = m_waitingList.pop();
	std::cout << "대기열에서 호출됨 : " << temp << std::endl;
	return temp;
}
