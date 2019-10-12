#include <iostream>
#include <vector>
//�����ϸ� ���� ��ũ
//https://coderkoo.tistory.com/7
//https://dpdpwl.tistory.com/46

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename ArrType>
void sort(int startIdx, int endIdx, ArrType& arr)
{
	if (startIdx >= endIdx) return;//startIdx�� endIdx���� �۾ƾ߸� �Ѵ�.

	int pivotIdx = startIdx;//arr[pivotIdx]���� �������� ����, ū���� ���������� �����Ѵ�.
	int i = pivotIdx + 1;//i = �ǹ����� ���������� �˻��ϴ� ������ ��.
	int j = endIdx;//j = �ǹ����� ū ���� �ڷ� �ű�� ����

	while (i <= j)
	{
		if (arr[i] > arr[pivotIdx])//i�ڸ��� �ִ°��� pivot������ �� ũ��
		{
			swap(arr[i], arr[j--]);
			//i�� j�� ���� swap�ϰ� j�� �����ڸ��� �ű��.
		}
		else
			++i;//�ƴϸ� ���� �ڸ��� �˻��Ѵ�.
	}
	swap(arr[pivotIdx], arr[j]);//�ǹ��� �־���� ��ġ�� �Ű��ְ�

	sort(startIdx, j - 1, arr);
	sort(j + 1, endIdx, arr);
}

int main()
{
	int arr[] = { 3,2,4,6,1,5 };

	//3,2,4,6,1,5 i�� p���� �����Ƿ� ++i
	//p i       j
	//3,2,4,6,1,5 i�� p���� ũ�Ƿ� j--�� swap(j�� ��ġ�� swap�ϰ� --j)
	//p   i     j
	//3,2,5,6,1,4 i�� p���� ũ�Ƿ� j--�� swap(j�� ��ġ�� swap�ϰ� --j)
	//p   i   j
	//3,2,1,6,5,4 i�� p���� �����Ƿ� ++i
	//p   i j
	//3,2,1,6,5,4 i�� p���� ũ�Ƿ� j--�� swap(j�� ��ġ�� swap�ϰ� --j)
	//p     ij
	//3,2,1,6,5,4 �ǹ��� �̵�
	//p   j i
	//1,2,3,6,5,4
	//p   j i
	//(1,2),3,(6,5,4) ��ȣģ �κ��� ����Լ��� ���� �������� �ݺ�
	// p    j  i

	//(1,2),3,(4,5,6) ���� �Ϸ�
	// p    j  i

	sort(0, 5, arr);

	return 0;
}