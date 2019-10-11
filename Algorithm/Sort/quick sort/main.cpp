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
	int i = pivotIdx + 1;
	int j = endIdx;

	while (i <= j) 
	{
		if (arr[i] > arr[pivotIdx])//i�ڸ��� �ִ°��� pivot������ �� ũ��
		{
			swap(arr[i], arr[j--]);
			//i�� j��ġ�� �ű�� j�� --�Ѵ�.
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
	int arr[] = { 1,7,3,5,2,6 };

	sort(0, 5, arr);

	return 0;
}