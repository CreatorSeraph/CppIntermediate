#pragma once
// 리스트에 저장되는 각각의 노드를 나타내는 객체
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


	data_type& data() { return m_data; }	// 데이터
	_list_node* next() { return m_next; }	// 다음노드
	_list_node* prev() { return m_prev; }	// 이전노드

	void _set_next(_list_node* next) { m_next = next; }
	void _set_prev(_list_node* prev) { m_prev = prev; }

private:
	data_type m_data;
	_list_node* m_next;
	_list_node* m_prev;
};

// 노드들을 소유하고 관리하는 객체
template <typename data_type>
class List
{
public:
	using node = _list_node<data_type>;

	List()
		// tail노드만 생성
		: m_head(_new_node())
		, m_tail(m_head)
		, m_size(0)
	{
	}
	~List()
	{
		// 보유한 모든 노드 delete
		node* iter = head();
		while (iter != tail())
		{
			node* next = iter->next();
			if (iter)
				delete iter;
			iter = next;
		}
	}


	node* head() { return m_head; }	// 리스트의 맨 앞에 위치한 노드
	node* tail() { return m_tail; }	// 리스트의 맨 뒤에 위치한 꼬리 노드이며 데이터가 존재하지 않음

	// 리스트의 맨 앞에 데이터(노드)를 추가함
	void push_front(data_type data)
	{
		insert(head(), data);
	}
	// 리스트의 꼬리 노드 앞에 데이터(노드)를 추가함
	// = 리스트의 맨 뒤에 노드를 추가함
	void push_back(data_type data)
	{
		insert(tail(), data);
	}
	// 리스트의 특정 위치에 노드를 추가함
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
	// 리스트의 특정 노드를 삭제함
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

	size_t size() { return m_size; }	// 리스트의 크기
	bool empty() { return !size(); }	// 리스트가 비어있는지 확인

private:
	node* m_head;
	node* m_tail;

	size_t m_size;


	node* _new_node(data_type data = data_type()) { return new node(data); }	// 새로운 노드 생성(new)
	// 두 노드 연결
	void _node_link(node* prev, node* next)
	{
		if (!prev || !next)
			return;

		prev->_set_next(next);
		next->_set_prev(prev);
	}
};
