#pragma once

template<class T>
class CVector
{
private://��� ����
	T* m_p;
	int m_size;
	int m_capacity;
public://������
	CVector()
		:m_p(nullptr), m_size(0), m_capacity(0)
	{
	}
	~CVector()
	{
		delete[] m_p;
	}
public://����Լ�
	//���� �ڿ� ������ �ϳ��� �߰�
	void push_back(const T& _val)
	{
		if (m_size == m_capacity)//������ ���ڶ��
		{
			reserve(_Calculate_growth(m_size + 1));//���͸� Ȯ���Ѵ�.
		}
		m_p[m_size++] = _val;
	}
	//���� �ڿ� �����͸� ����
	void pop_back()
	{
		--m_size;
	}
	//���ϴ� ��ġ�� �����͸� ����
	void erase(int _idx)
	{
		for (int i = _idx; i < m_size - 1; ++i)
		{
			m_p[i] = m_p[i + 1];
		}
		--m_size;
	}
	//���ϴ� ��ġ�� �����͸� ����
	void insert(int _idx, const T& _val)
	{
		if (m_size == m_capacity)//������ ���ڶ��
		{
			reserve(_Calculate_growth(m_size + 1));//���͸� Ȯ���Ѵ�.
		}

		for (int i = m_size; i > _idx; --i)
		{
			m_p[i] = m_p[i - 1];
		}
		m_p[_idx] = _val;
		++m_size;
	}
	void resize(int _size)
	{
		if (_size > m_size)
		{
			if (_size > m_capacity)//������ ���ڶ��
			{
				reserve(_Calculate_growth(_size));//���͸� Ȯ���Ѵ�.
			}
			else
			{
				for (int i = m_size; i < _size - 1; ++i)
				{
					m_p[i] = T();
				}
			}
		}

		m_size = _size;
	}

	//������ ũ�⸦ �����صд�(���Ҵ��� �Ͼ�� �ʰ� �����Ѵ�)
	void reserve(int _capacity)
	{
		if (_capacity <= m_capacity) return;//�̹� �װź��� �� ū ����� �Ҵ��� �Ǿ� ������ �����Ѵ�.
		T* temp = m_p;//������ �迭�� �ӽ� �����ϰ�
		m_p = new T[_capacity];//���ο� ũ���� �迭�� �Ҵ��Ѵ�
		if (temp)
		{
			for (int i = 0; i < m_size; ++i)//������ �����Ͱ� �־������, �� �����͵��� �������ְ�
			{
				m_p[i] = temp[i];
			}
			delete[] temp;//������ �����͸� �����Ѵ�.
		}
		m_capacity = _capacity;
	}
public://Getter
	int size() { return m_size; }
	int capacity() { return m_capacity; }
public://operator
	//�迭ó�� �����Ҽ� �ְ� ����� ���� operator
	T& operator[](int _idx)
	{
		//T&�� ��ȯ���� ������ ��ȯ ������ ���� �����Ҽ� �ְ� �ϱ� ����
		return m_p[_idx];
	}
private:
	//���������� ������ ����� �÷��� �Ҷ�
	int _Calculate_growth(int _newSize)
	{
		int newCapacity = m_capacity + m_capacity / 2;//capacity * 1.5
		if (_newSize > newCapacity)
			return _newSize;
		return newCapacity;
	}
};

