#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int input;

    try
    {
        cin >> input;
        switch (input)
        {
        case 1:
            throw "�ȳ�";
        case 2:
            throw 4;
        case 3:
            throw 1.5;
        default:
            throw "����"s;
        }
    }
    //if ~ else���� ���������� catch���� ��ø�Ͽ� ����� �� ����.
    //������ throw�� Ÿ�԰� �´� catch�������� ���߰� ��.
    catch (const char* s)
    {
        cout << "const char*�� throw��, ���� :" << s << endl;
    }
    catch (int val)
    {
        cout << "int�� throw��, ���� :" << val << endl;
    }
    //catch(...)�� ���� switch������ default�� ���� ������ ��.
    catch (...)
    {
        cout << "�ٸ� Ÿ�Կ��� ������ ���� throw�� ������" << endl;
    }

    return 0;
}