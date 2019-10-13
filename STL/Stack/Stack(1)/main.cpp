#include "Stack.h"
#include <iostream>
int main()
{
	// int형식의 데이터를 8개 저장할 수 있는 스택 선언
	Stack<int, 8> stack;
	
	stack.push(1);
	stack.push(5);
	stack.push(3);
	stack.push(2);
	stack.push(4);
	// stack = 1, 5, 3, 2, 4


	int data1 = stack.pop();	// 4
	int data2 = stack.pop();	// 2
	// stack = 1, 5, 3

	int data3 = stack.top();	// 3
	int data4 = stack.top();	// 3
	// stack = 1, 5, 3
	// stack에 영향을 주지 않음


	stack.push(0);
	stack.push(1);
	stack.push(2);
	// stack = 1, 5, 3, 0, 1, 2


	int size = stack.size();		// 6
	int maxSize = stack.max_size();	// 8
	bool isEmpty = stack.empty();	// false

	return 0;
}