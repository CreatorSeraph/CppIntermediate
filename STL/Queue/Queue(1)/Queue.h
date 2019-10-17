#pragma once
// ���ø� ���ڷ� ������ ���İ� ť�� ũ�⸦ ����
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

	// ť�� �� �տ� ������ �߰�
	void push(data_type data)
	{
		if (++m_head >= container_size)
			m_head = 0;

		m_container[m_head] = data;
		++m_size;
	}
	// ť���� ���� ������ �����͸� �������
	data_type pop()
	{
		data_type& temp = back();
		if (++m_tail >= container_size)
			m_tail = 0;
		--m_size;
		return temp;
	}
	// ť���� ���� ������ �����͸� ������
	data_type& back()
	{
		return m_container[m_tail];
	}

	bool empty() { return !m_size; }				// ť�� ����ִ��� Ȯ��
	size_t size() { return m_size; }				// ť�� ���� ũ��
	size_t max_size() { return container_size; }	// ť�� �ִ� ũ��

private:
	data_type m_container[container_size];
	size_t m_size;
	size_t m_head;
	size_t m_tail;
};
