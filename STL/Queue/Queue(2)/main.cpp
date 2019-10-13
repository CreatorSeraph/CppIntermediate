#include "WaitingSystem.h"
#include <iostream>
int main()
{
	WaitingSystem ws;

	ws.Register("홍길동");
	ws.Register("거북이");
	ws.Register("일렉스");
	// 대기자가 3명 존재함 (홍길동, 거북이, 일렉스)

	ws.Call();
	ws.Call();
	// 대기자를 2명 호출함 (홍길동, 거북이)
	// 대기자가 1명 존재함 (일렉스)

	ws.Register("한서연");
	ws.Register("박지성");
	ws.Register("김연아");
	ws.Register("강시국");
	// 대기자를 4명 추가하였으나 공간이 부족함
	// 대기자가 4명 존재함 (일렉스, 한서연, 박지성, 김연아)
	// '강시국'은 대기열에 추가되지 않음


	ws.Call();
	ws.Call();
	ws.Call();
	ws.Call();
	// 대기자를 모두 호출 (일렉스, 한서연, 박지성, 김연아)


	ws.Call();
	// 대기자를 호출 하였으나 더이상 대기자가 존재하지 않음.

	return 0;
}