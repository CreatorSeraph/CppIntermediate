#include "WaitingSystem.h"
#include <iostream>
int main()
{
	WaitingSystem ws;

	ws.Register("ȫ�浿");
	ws.Register("�ź���");
	ws.Register("�Ϸ���");
	// ����ڰ� 3�� ������ (ȫ�浿, �ź���, �Ϸ���)

	ws.Call();
	ws.Call();
	// ����ڸ� 2�� ȣ���� (ȫ�浿, �ź���)
	// ����ڰ� 1�� ������ (�Ϸ���)

	ws.Register("�Ѽ���");
	ws.Register("������");
	ws.Register("�迬��");
	ws.Register("���ñ�");
	// ����ڸ� 4�� �߰��Ͽ����� ������ ������
	// ����ڰ� 4�� ������ (�Ϸ���, �Ѽ���, ������, �迬��)
	// '���ñ�'�� ��⿭�� �߰����� ����


	ws.Call();
	ws.Call();
	ws.Call();
	ws.Call();
	// ����ڸ� ��� ȣ�� (�Ϸ���, �Ѽ���, ������, �迬��)


	ws.Call();
	// ����ڸ� ȣ�� �Ͽ����� ���̻� ����ڰ� �������� ����.

	return 0;
}