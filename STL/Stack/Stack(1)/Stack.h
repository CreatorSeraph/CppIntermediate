#pragma once
template <typename data_type, size_t container_size>
class Stack
{
public:
	Stack();
	~Stack();

	void push(data_type data);
	data_type pop();
	data_type& top();

	size_t size();
	size_t max_size();

private:
	data_type m_container[container_size];
	size_t m_size;
};
