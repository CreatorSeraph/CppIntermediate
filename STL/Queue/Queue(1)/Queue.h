#pragma once
// 템플릿 인자로 데이터 형식과 큐의 크기를 받음
template <typename data_type, size_t container_size>
class Queue
{
public:
	Queue()
		: m_container{}
		, m_size(0)
		, m_head(container_size)
		, m_tail(0)
	{

	}
	~Queue() {}

	// 큐의 맨 앞에 데이터 추가
	void push(data_type data)
	{
		if (++m_head >= container_size)
			m_head = 0;

		m_container[m_head] = data;
		++m_size;
	}
	// 큐에서 가장 오래된 데이터를 추출받음
	data_type pop()
	{
		data_type& temp = back();
		if (++m_tail >= container_size)
			m_tail = 0;
		--m_size;
		return temp;
	}
	// 큐에서 가장 오래된 데이터를 열람함
	data_type& back()
	{
		return m_container[m_tail];
	}

	bool empty() { return !m_size; }				// 큐가 비어있는지 확인
	size_t size() { return m_size; }				// 큐의 현재 크기
	size_t max_size() { return container_size; }	// 큐의 최대 크기

private:
	data_type m_container[container_size];
	size_t m_size;
	size_t m_head;
	size_t m_tail;
};
