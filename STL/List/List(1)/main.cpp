#include "List.h"
#include <iostream>
int main()
{
	// int형식의 데이터를 저장하는 리스트 생성
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

	// 리스트의 모든 요소를 순회하는 반복문
	for (ListNode* node = list.head(); node != list.tail(); node = node->next())
	{
		// 노드 탐색
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