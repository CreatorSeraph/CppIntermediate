#include "Queue.h"
int main()
{
	// int형식의 데이터를 8개 저장할 수 있는 큐 선언
	Queue<int, 8> queue;

	queue.push(1);
	queue.push(5);
	queue.push(3);
	queue.push(2);
	queue.push(4);
	// queue = 1, 5, 3, 2, 4


	int data1 = queue.pop();	// 1
	int data2 = queue.pop();	// 5
	// queue = 3, 2, 4

	int data3 = queue.back();	// 3
	int data4 = queue.back();	// 3
	// queue = 3, 2, 4
	// queue에 영향을 주지 않음


	queue.push(0);
	queue.push(1);
	queue.push(2);
	// queue = 3, 2, 4, 0, 1, 2

	int size = queue.size();		// 6
	int maxSize = queue.max_size();	// 8
	bool isEmpty = queue.empty();	// false


	queue.pop();	// 3
	queue.pop();	// 2
	queue.pop();	// 4
	queue.pop();	// 0
	queue.pop();	// 1
	queue.pop();	// 2
	isEmpty = queue.empty();	// true

	return 0;
}