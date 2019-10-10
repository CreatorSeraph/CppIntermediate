#pragma once

template<class T>
class CVector
{
private://멤버 변수
	T* p;
	int size;
	int capacity;
public://생성자
	CVector()
		:p(nullptr), size(0), capacity(0)
	{
	}
	~CVector()
	{
		delete[] p;
	}
public://멤버함수
	//가장 뒤에 데이터 하나를 추가
	void push_back(const T& _val)
	{
		if (size == capacity)//공간이 모자라다
		{
			reserve(_Calculate_growth(size + 1));//벡터를 확장한다.
		}
		p[size++] = _val;
	}
	//가장 뒤에 데이터를 삭제
	void pop_back()
	{
		--size;
	}
	//원하는 위치에 데이터를 삭제
	void erase(int _idx)
	{
		for (int i = _idx; i < size - 1; ++i)
		{
			p[i] = p[i + 1];
		}
		--size;
	}
	//원하는 위치에 데이터를 삽입
	void insert(int _idx, const T& _val)
	{
		if (size == capacity)//공간이 모자라다
		{
			reserve(_Calculate_growth(size + 1));//벡터를 확장한다.
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
			if (_size > capacity)//공간이 모자라다
			{
				reserve(_Calculate_growth(_size));//벡터를 확장한다.
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

	//벡터의 크기를 예약해둔다(재할당이 일어나지 않게 방지한다)
	void reserve(int _capacity)
	{
		if (_capacity >= capacity) return;//이미 그거보다 더 큰 사이즈가 할당이 되어 있으면 무시한다.
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
	//배열처럼 접근할수 있게 만들기 위한 operator
	T& operator[](int _idx)
	{
		//T&가 반환형인 이유는 반환 이후의 값을 수정할수 있게 하기 위함
		return p[_idx];
	}
private:
	//내부적으로 벡터의 사이즈를 늘려야 할때
	int _Calculate_growth(int _newSize)
	{
		int newCapacity = capacity + capacity / 2;//capacity * 1.5
		if (_newSize > newCapacity)
			return _newSize;
		return newCapacity;
	}
};

