#pragma once
// ������Ʈ Queue(1)�� Queue.h�� �״�� ���
#include "../Queue(1)/Queue.h"
#include <string>

/*
	ȣ��� �̸��� ����ϸ�
	�ִ� 4����� ��� �� �� �ִ�
	������ ��⿭ �ý����� ����.
*/
class WaitingSystem
{
public:
	using String = std::string;
	WaitingSystem() {}
	~WaitingSystem() {}


	// ��⿭ ���
	bool Register(String customerName);

	// ��⿭ �� ����ڸ� �ҷ���
	String Call();

private:
	// ���ڿ��� �����ͷ� ��� 4ĭ ũ���� ť�� ���
	Queue<String, 4> m_waitingList;
};

