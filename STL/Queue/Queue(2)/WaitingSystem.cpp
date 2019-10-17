#include "WaitingSystem.h"
#include <iostream>

bool WaitingSystem::Register(String customerName)
{
	if (m_waitingList.size() == m_waitingList.max_size())
	{
		std::cout << "���̻� ��⿭�� �߰��� �� ����." << std::endl;
		return false;
	}

	m_waitingList.push(customerName);
	std::cout << "��⿭�� �߰��� : " << customerName << std::endl;
	return true;
}

WaitingSystem::String WaitingSystem::Call()
{
	if (m_waitingList.empty())
	{
		std::cout << "���̻� ����ڰ� �������� ����." << std::endl;
		return "";
	}

	String temp = m_waitingList.pop();
	std::cout << "��⿭���� ȣ��� : " << temp << std::endl;
	return temp;
}
