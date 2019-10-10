#pragma once

template<class T>
class CVector
{
private://��� ����
	T* p;
	int size;
	int capacity;
public://������
	CVector()
		:p(nullptr), size(0), capacity(0)
	{
	}
	~CVector()
	{
		delete[] p;
	}
public://����Լ�
	//���� �ڿ� ������ �ϳ��� �߰�
	void push_back(const T& _val)
	{
		if (size == capacity)//������ ���ڶ��
		{
			reserve(_Calculate_growth(size + 1));//���͸� Ȯ���Ѵ�.
		}
		p[size++] = _val;
	}
	//���� �ڿ� �����͸� ����
	void pop_back()
	{
		--size;
	}
	//���ϴ� ��ġ�� �����͸� ����
	void erase(int _idx)
	{
		for (int i = _idx; i < size - 1; ++i)
		{
			p[i] = p[i + 1];
		}
		--size;
	}
	//���ϴ� ��ġ�� �����͸� ����
	void insert(int _idx, const T& _val)
	{
		if (size == capacity)//������ ���ڶ��
		{
			reserve(_Calculate_growth(size + 1));//���͸� Ȯ���Ѵ�.
		}

		for (int i = size; i > _idx; --i)
		{
			p[i] = p[i - 1];
		}
		p[_idx] = _val;
		++size;
	}
	void resize(int _size)
	{
		if (_size > size)
		{
			if (_size > capacity)//������ ���ڶ��
			{
				reserve(_Calculate_growth(_size));//���͸� Ȯ���Ѵ�.
			}
			else
			{
				for (int i = size; i < _size - 1; ++i)
				{
					p[i] = T();
				}
			}
		}

		size = _size;
	}

	//������ ũ�⸦ �����صд�(���Ҵ��� �Ͼ�� �ʰ� �����Ѵ�)
	void reserve(int _capacity)
	{
		if (_capacity >= capacity) return;//�̹� �װź��� �� ū ����� �Ҵ��� �Ǿ� ������ �����Ѵ�.
		T* temp = p;
		p = new T[_capacity];
		if (temp)
		{
			for (int i = 0; i < size; ++i)
			{
				temp[i] = p[i];
			}
		}
		capacity = _capacity;
	}
public://operator
	//�迭ó�� �����Ҽ� �ְ� ����� ���� operator
	T& operator[](int _idx)
	{
		//T&�� ��ȯ���� ������ ��ȯ ������ ���� �����Ҽ� �ְ� �ϱ� ����
		return p[_idx];
	}
private:
	//���������� ������ ����� �÷��� �Ҷ�
	int _Calculate_growth(int _newSize)
	{
		int newCapacity = capacity + capacity / 2;//capacity * 1.5
		if (_newSize > newCapacity)
			return _newSize;
		return newCapacity;
	}
};

