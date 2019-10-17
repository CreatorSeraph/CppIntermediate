#include <iostream>

template<typename T>
void merge(int startIdx, int centerIdx, int endIdx, T arr[], T* tempArr)
{
    //int centerIdx = (startIdx + endIdx) / 2;
    int i = startIdx;
    int j = centerIdx + 1;
    int k = startIdx;
    //배열을 둘로 나눔(i는 startIdx ~ centerIdx를, j는 centerIdx ~ endIdx를 검사)
    int stopPos = 0;
    while (true)
    {
        //왼쪽 배열을 모두 비워버렸으면 남은 오른쪽 배열의 위치를 저장한다
        if (i > centerIdx)
        {
            stopPos = j;
            break;
        }
        //오른쪽 배열을 모두 비워버렸으면 남은 왼쪽 배열의 위치를 저장한다
        if (j > endIdx)
        {
            stopPos = i;
            break;
        }
        //왼쪽 배열의 값과 오른쪽 배열의 값중에 더 작은걸 앞에 넣는다.
        tempArr[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }

    //남은 배열의 값들은 지금까지 넣은 값들보다 무조건 큰 값이므로 뒤에 순서대로 넣는다.
    while (k <= endIdx)
        tempArr[k++] = arr[stopPos++];

    //임시 배열을 복사한다.
    for (int i = startIdx; i <= endIdx; ++i)
        arr[i] = tempArr[i];
}

template<typename T>
void merge_sort(int startIdx, int endIdx, T arr[], T* tempArr)
{
    if (startIdx >= endIdx) return;
    
    //배열의 가운데를 기준으로 왼쪽과 오른쪽에 다시 병합정렬을 시킨다.
    int centerIdx = (startIdx + endIdx) / 2;
    merge_sort(startIdx, centerIdx, arr, tempArr);
    merge_sort(centerIdx + 1, endIdx, arr, tempArr);

    merge(startIdx, centerIdx, endIdx, arr, tempArr);
}

template<typename T>
void merge_sort(int startIdx, int endIdx, T arr[])
{
    if (startIdx >= endIdx) return;//정렬할 범위가 잘못 지정됨

    //합병정렬(merge sort)에는 병합과정을 처리하기 위한 임시 배열이 필요하다.
    T* tempArr = new T[endIdx - startIdx + 1];

    merge_sort(startIdx, endIdx, arr, tempArr);
}

int main()
{
    int arr[10] = { 1,3,4,1,2,4,1,4,6,2 };
    merge_sort(0, 9, arr);
    return 0;
}