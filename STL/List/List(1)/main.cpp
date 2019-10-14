#include "List.h"
#include <iostream>
int main()
{
	// int������ �����͸� �����ϴ� ����Ʈ ����
	List<int> list;
	using ListNode = List<int>::node;

	list.push_back(11);
	list.push_back(12);
	list.push_back(13);
	// 11, 12, 13

	list.push_front(21);
	list.push_front(22);
	list.push_front(23);
	// 23, 22, 21, 11, 12, 13


	ListNode* insertNode = nullptr;
	ListNode* eraseNode = nullptr;

	// ����Ʈ�� ��� ��Ҹ� ��ȸ�ϴ� �ݺ���
	for (ListNode* node = list.head(); node != list.tail(); node = node->next())
	{
		// ��� Ž��
		if (node->data() == 12)
			insertNode = node;
		if (node->data() == 22)
			eraseNode = node;

		std::cout << node->data() << std::endl;
	}

	if (insertNode)
	{
		list.insert(insertNode, 31);
		// 23, 22, 21, 11, 31, 12, 13
	}
	if (eraseNode)
	{
		list.erase(eraseNode);
		// 23, 21, 11, 31, 12, 13
	}

	size_t size = list.size();	// 6
	bool empty = list.empty();	// false

	return 0;
}