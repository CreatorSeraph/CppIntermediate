#pragma once
// 템플릿 인자로 저장될 데이터의 타입과 스택의 크기를 받음.
template <typename data_type, size_t container_size>
class Stack
{
public:
	Stack()
		: m_container{}
		, m_size(0)
	{
	}
	~Stack()
	{
	}


	// 스택의 맨 앞에 데이터 추가
	void push(data_type data)
	{
		++m_size;
		top() = data;
	}
	//스택에 마지막으로 추가된 데이터를 추출
	data_type pop()
	{
		data_type& temp = top();
		--m_size;
		return temp;
	}
	//스택에 마지막으로 추가된 데이터를 열람
	data_type& top() { return m_container[m_size]; }

	bool empty() { return !m_size; }				// 스택이 비어있는지 확인
	size_t size() { return m_size; }				// 스택의 현재 크기
	size_t max_size() { return container_size; }	// 스택의 최대 크기

private:
	data_type m_container[container_size];
	size_t m_size;
};
