#pragma once

template<class T>
class CVector
{
private://멤버 변수
	T* m_p;
	int m_size;
	int m_capacity;
public://생성자
	CVector()
		:m_p(nullptr), m_size(0), m_capacity(0)
	{
	}
	~CVector()
	{
		delete[] m_p;
	}
public://멤버함수
	//가장 뒤에 데이터 하나를 추가
	void push_back(const T& _val)
	{
		if (m_size == m_capacity)//공간이 모자라다
		{
			reserve(_Calculate_growth(m_size + 1));//벡터를 확장한다.
		}
		m_p[m_size++] = _val;
	}
	//가장 뒤에 데이터를 삭제
	void pop_back()
	{
		--m_size;
	}
	//원하는 위치에 데이터를 삭제
	void erase(int _idx)
	{
		for (int i = _idx; i < m_size - 1; ++i)
		{
			m_p[i] = m_p[i + 1];
		}
		--m_size;
	}
	//원하는 위치에 데이터를 삽입
	void insert(int _idx, const T& _val)
	{
		if (m_size == m_capacity)//공간이 모자라다
		{
			reserve(_Calculate_growth(m_size + 1));//벡터를 확장한다.
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
			if (_size > m_capacity)//공간이 모자라다
			{
				reserve(_Calculate_growth(_size));//벡터를 확장한다.
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

	//벡터의 크기를 예약해둔다(재할당이 일어나지 않게 방지한다)
	void reserve(int _capacity)
	{
		if (_capacity <= m_capacity) return;//이미 그거보다 더 큰 사이즈가 할당이 되어 있으면 무시한다.
		T* temp = m_p;//기존의 배열을 임시 저장하고
		m_p = new T[_capacity];//새로운 크기의 배열을 할당한다
		if (temp)
		{
			for (int i = 0; i < m_size; ++i)//기존의 데이터가 있었을경우, 그 데이터들을 복사해주고
			{
				m_p[i] = temp[i];
			}
			delete[] temp;//기존의 데이터를 삭제한다.
		}
		m_capacity = _capacity;
	}
public://Getter
	int size() { return m_size; }
	int capacity() { return m_capacity; }
public://operator
	//배열처럼 접근할수 있게 만들기 위한 operator
	T& operator[](int _idx)
	{
		//T&가 반환형인 이유는 반환 이후의 값을 수정할수 있게 하기 위함
		return m_p[_idx];
	}
private:
	//내부적으로 벡터의 사이즈를 늘려야 할때
	int _Calculate_growth(int _newSize)
	{
		int newCapacity = m_capacity + m_capacity / 2;//capacity * 1.5
		if (_newSize > newCapacity)
			return _newSize;
		return newCapacity;
	}
};

