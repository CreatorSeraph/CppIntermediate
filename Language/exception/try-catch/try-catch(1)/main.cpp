#include <iostream>

int main()
{
    using namespace std;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int b;
    //try�� ���ο����� throw���� ������ �� �ִ�.
    try
    {
        cout << "���ϴ� �ε����� �Է��� �ֽʽÿ� : ";
        cin >> b;
        //�Ʒ��� ���� ������� throw�� �ϸ�
        if (b < 0) throw "������ �ε����� ����� �� �����ϴ�.";
        if (b > 9) throw "�迭�� ����� ��� �ε����� ����� �� �����ϴ�";
        cout << arr[b] << endl;
    }
    catch (...)
    {
        //catch������ ������ �ȴ�.
        cout << "����...���� ������ ���彿...!" << endl;
    }

    return 0;
}