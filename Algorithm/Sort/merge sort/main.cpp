#include <iostream>

template<typename T>
void merge(int startIdx, int centerIdx, int endIdx, T arr[], T* tempArr)
{
    //int centerIdx = (startIdx + endIdx) / 2;
    int i = startIdx;
    int j = centerIdx + 1;
    int k = startIdx;
    //�迭�� �ѷ� ����(i�� startIdx ~ centerIdx��, j�� centerIdx ~ endIdx�� �˻�)
    int stopPos = 0;
    while (true)
    {
        //���� �迭�� ��� ����������� ���� ������ �迭�� ��ġ�� �����Ѵ�
        if (i > centerIdx)
        {
            stopPos = j;
            break;
        }
        //������ �迭�� ��� ����������� ���� ���� �迭�� ��ġ�� �����Ѵ�
        if (j > endIdx)
        {
            stopPos = i;
            break;
        }
        //���� �迭�� ���� ������ �迭�� ���߿� �� ������ �տ� �ִ´�.
        tempArr[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }

    //���� �迭�� ������ ���ݱ��� ���� ���麸�� ������ ū ���̹Ƿ� �ڿ� ������� �ִ´�.
    while (k <= endIdx)
        tempArr[k++] = arr[stopPos++];

    //�ӽ� �迭�� �����Ѵ�.
    for (int i = startIdx; i <= endIdx; ++i)
        arr[i] = tempArr[i];
}

template<typename T>
void merge_sort(int startIdx, int endIdx, T arr[], T* tempArr)
{
    if (startIdx >= endIdx) return;
    
    //�迭�� ����� �������� ���ʰ� �����ʿ� �ٽ� ���������� ��Ų��.
    int centerIdx = (startIdx + endIdx) / 2;
    merge_sort(startIdx, centerIdx, arr, tempArr);
    merge_sort(centerIdx + 1, endIdx, arr, tempArr);

    merge(startIdx, centerIdx, endIdx, arr, tempArr);
}

template<typename T>
void merge_sort(int startIdx, int endIdx, T arr[])
{
    if (startIdx >= endIdx) return;//������ ������ �߸� ������

    //�պ�����(merge sort)���� ���հ����� ó���ϱ� ���� �ӽ� �迭�� �ʿ��ϴ�.
    T* tempArr = new T[endIdx - startIdx + 1];

    merge_sort(startIdx, endIdx, arr, tempArr);
}

int main()
{
    int arr[10] = { 1,3,4,1,2,4,1,4,6,2 };
    merge_sort(0, 9, arr);
    return 0;
}