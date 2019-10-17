#pragma once
// ���ø� ���ڷ� ����� �������� Ÿ�԰� ������ ũ�⸦ ����.
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


	// ������ �� �տ� ������ �߰�
	bool push(data_type data)
	{
		if (size() == max_size())
			return false;

		++m_size;
		top() = data;
		return true;
	}
	//���ÿ� ���������� �߰��� �����͸� ����
	data_type pop()
	{
		if (empty())
			return {};

		data_type& temp = top();
		--m_size;
		return temp;
	}
	//���ÿ� ���������� �߰��� �����͸� ����
	data_type& top() { return m_container[m_size - 1]; }

	bool empty() { return !m_size; }				// ������ ����ִ��� Ȯ��
	size_t size() { return m_size; }				// ������ ���� ũ��
	size_t max_size() { return container_size; }	// ������ �ִ� ũ��

private:
	data_type m_container[container_size];
	size_t m_size;
};
