#pragma once
// ����Ʈ�� ����Ǵ� ������ ��带 ��Ÿ���� ��ü
template <typename data_type>
class _list_node
{
public:
	_list_node(data_type data)
		: m_data(data)
		, m_next(nullptr)
		, m_prev(nullptr)
	{
	}
	~_list_node() {}


	data_type& data() { return m_data; }	// ������
	_list_node* next() { return m_next; }	// �������
	_list_node* prev() { return m_prev; }	// �������

	void _set_next(_list_node* next) { m_next = next; }
	void _set_prev(_list_node* prev) { m_prev = prev; }

private:
	data_type m_data;
	_list_node* m_next;
	_list_node* m_prev;
};

// ������ �����ϰ� �����ϴ� ��ü
template <typename data_type>
class List
{
public:
	using node = _list_node<data_type>;

	List()
		// tail��常 ����
		: m_head(_new_node())
		, m_tail(m_head)
		, m_size(0)
	{
	}
	~List()
	{
		// ������ ��� ��� delete
		node* iter = head();
		while (iter != tail())
		{
			node* next = iter->next();
			if (iter)
				delete iter;
			iter = next;
		}
	}


	node* head() { return m_head; }	// ����Ʈ�� �� �տ� ��ġ�� ���
	node* tail() { return m_tail; }	// ����Ʈ�� �� �ڿ� ��ġ�� ���� ����̸� �����Ͱ� �������� ����

	// ����Ʈ�� �� �տ� ������(���)�� �߰���
	void push_front(data_type data)
	{
		insert(head(), data);
	}
	// ����Ʈ�� ���� ��� �տ� ������(���)�� �߰���
	// = ����Ʈ�� �� �ڿ� ��带 �߰���
	void push_back(data_type data)
	{
		insert(tail(), data);
	}
	// ����Ʈ�� Ư�� ��ġ�� ��带 �߰���
	node* insert(node* place, data_type data)
	{
		if (!place) return nullptr;

		node* temp = _new_node(data);
		if (place->prev())
		{
			_node_link(place->prev(), temp);
			_node_link(temp, place);
		}
		else
		{
			_node_link(temp, place);
			m_head = temp;
		}

		++m_size;
		return temp;
	}
	// ����Ʈ�� Ư�� ��带 ������
	node* erase(node* target)
	{
		if (!target || target == tail()) return nullptr;

		node* tPrev = target->prev();
		node* tNext = target->next();

		if (tPrev)
			tPrev->_set_next(tNext);
		else
			m_head = tNext;
		tNext->_set_prev(tPrev);
		delete target;

		--m_size;
		return tNext;
	}

	size_t size() { return m_size; }	// ����Ʈ�� ũ��
	bool empty() { return !size(); }	// ����Ʈ�� ����ִ��� Ȯ��

private:
	node* m_head;
	node* m_tail;

	size_t m_size;


	node* _new_node(data_type data = data_type()) { return new node(data); }	// ���ο� ��� ����(new)
	// �� ��� ����
	void _node_link(node* prev, node* next)
	{
		if (!prev || !next)
			return;

		prev->_set_next(next);
		next->_set_prev(prev);
	}
};
