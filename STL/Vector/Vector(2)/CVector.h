#pragma once

template<class T>
class CVector
{
private:
	T* p;
	int size;
	int capacity;
public:
	CVector()
		:p(nullptr), size(0), capacity(0)
	{
	}
	~CVector()
	{
		delete[] p;
	}
public:
	void push_back(const T& _val)
	{
		if (size == capacity)//공간이 모자라다
		{
			//공간을 새로 만들어줘야한다
		}
		p[size++] = _val;
	}
	void pop_back()
	{
		size--;
	}
	void erase(int _idx)
	{
		for (int i = _idx; i < size - 1; ++i)
		{
			p[i] = p[i + 1];
		}
		size--;
	}
	void insert(int _idx, const T& _val)
	{
		if (size == capacity)//공간이 모자라다
		{
			//공간을 새로 만들어줘야한다
		}
		for (int i = _idx; i < size; ++i)
		{
			p[i] = p[i + 1];
		}
		p[_idx] = _val;
		size++;
	}
	void reserve(int _capacity)
	{
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
public:
	T& operator[](int _idx)
	{
		return p[_idx];
	}
};

