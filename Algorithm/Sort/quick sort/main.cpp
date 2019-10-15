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
	int i = pivotIdx + 1;//i = 피벗보다 작은값인지 검사하는 역할을 함.
	int j = endIdx;//j = 피벗보다 큰 값을 뒤로 옮기기 위함

	while (i <= j)
	{
		if (arr[i] > arr[pivotIdx])//i자리에 있는값이 pivot값보다 더 크면
		{
			swap(arr[i], arr[j--]);
			//i와 j의 값을 swap하고 j를 다음자리로 옮긴다.
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
	int arr[] = { 3,2,4,6,1,5 };

	//3,2,4,6,1,5 i가 p보다 작으므로 ++i
	//p i       j
	//3,2,4,6,1,5 i가 p보다 크므로 j--과 swap(j의 위치와 swap하고 --j)
	//p   i     j
	//3,2,5,6,1,4 i가 p보다 크므로 j--과 swap(j의 위치와 swap하고 --j)
	//p   i   j
	//3,2,1,6,5,4 i가 p보다 작으므로 ++i
	//p   i j
	//3,2,1,6,5,4 i가 p보다 크므로 j--과 swap(j의 위치와 swap하고 --j)
	//p     ij
	//3,2,1,6,5,4 피벗을 이동
	//p   j i
	//1,2,3,6,5,4
	//p   j i
	//(1,2),3,(6,5,4) 괄호친 부분을 재귀함수를 통해 위과정을 반복
	// p    j  i

	//(1,2),3,(4,5,6) 정렬 완료
	// p    j  i

	sort(0, 5, arr);

	return 0;
}