#pragma once
// 템플릿 인자로 데이터 형식과 큐의 크기를 받음
template <typename data_type, size_t container_size>
class Queue
{
public:
	Queue();
	~Queue();

	void push(data_type data);
	data_type pop();
	data_type& back();

	bool empty();
	size_t size();
	size_t max_size();

private:
	data_type m_container[container_size];
	size_t m_size;
	size_t m_head;
	size_t m_tail;
};
