#include <iostream>
#include <vector>
//참고하면 좋은 링크
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
	if (startIdx >= endIdx) return;//startIdx가 endIdx보다 작아야만 한다.

	int pivotIdx = startIdx;//arr[pivotIdx]보다 작은값은 왼쪽, 큰값은 오른쪽으로 정렬한다.
	int i = pivotIdx + 1;
	int j = endIdx;

	while (i <= j) 
	{
		if (arr[i] > arr[pivotIdx])//i자리에 있는값이 pivot값보다 더 크면
		{
			swap(arr[i], arr[j--]);
			//i를 j위치로 옮기고 j를 --한다.
		}
		else
			++i;//아니면 다음 자리를 검사한다.
	}
	swap(arr[pivotIdx], arr[j]);//피벗을 있어야할 위치로 옮겨주고

	sort(startIdx, j - 1, arr);
	sort(j + 1, endIdx, arr);
}

int main()
{
	int arr[] = { 1,7,3,5,2,6 };

	sort(0, 5, arr);

	return 0;
}