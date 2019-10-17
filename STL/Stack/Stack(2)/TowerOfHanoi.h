#pragma once
// 프로젝트 Stack(1)의 Stack.h를 사용
#include "../Stack(1)/Stack.h"

//렌더링용 함수
#include <iostream>
#include <Windows.h>
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


template <size_t max_height>
class TowerOfHanoi
{
public:
	TowerOfHanoi()
	{
		for (size_t i = max_height; i > 0; --i)
			m_stick[0].push(i);
		_default_plate_draw();
	}
	~TowerOfHanoi() {}


	// 원판을 다른막대로 이동함
	bool MovePlate(size_t prev, size_t next)
	{
		if (2 < prev || 2 < next)
			return false;

		if (m_stick[prev].empty())
			return false;

		if (m_stick[next].size() && m_stick[prev].top() > m_stick[next].top())
			return false;

		m_stick[next].push(m_stick[prev].pop());
		_move_plate_redraw(prev, next, m_stick[next].top());
		return true;
	}

	// 2, 3번째 막대에 탑이 제대로 완성될경우 참을 반환
	bool CheckSucceeded()
	{
		return m_stick[1].size() == m_stick[1].max_size() ||
			m_stick[2].size() == m_stick[2].max_size();
	}


private:
	/*
	data_type은 원판의 크기
	container_size는 원판의 최대 크기
	3개의 스택은 3개의 막대를 의미함
	*/
	Stack<size_t, max_height> m_stick[3];



	//렌더링용 함수들
	size_t _rayer_to_y(size_t rayer)
	{
		const size_t offset = 1;
		return max_height - rayer + offset;
	}
	size_t _size_to_x(size_t size)
	{
		return max_height - size;
	}
	size_t _stick_to_x(size_t stickIndex)
	{
		return stickIndex * (max_height * 2 + 1);
	}

	void _draw_rayer(size_t stickIndex, size_t size, size_t rayer)
	{
		gotoxy(_size_to_x(size) + _stick_to_x(stickIndex), _rayer_to_y(rayer));
		for (size_t i = 0; i < size; ++i)
			std::cout << "■";
	}
	void _line_clear(size_t stickIndex, size_t rayer)
	{
		gotoxy(_stick_to_x(stickIndex), _rayer_to_y(rayer));
		for (size_t i = 0; i < max_height; ++i)
			std::cout << "  ";
	}

	void _default_plate_draw()
	{
		for (size_t i = 1; i <= max_height; ++i)
			_draw_rayer(0, i, max_height - i + 1);
	}
	void _move_plate_redraw(size_t prev, size_t next, size_t size)
	{
		_line_clear(prev, m_stick[prev].size() + 1);
		_draw_rayer(next, size, m_stick[next].size());
	}
};
