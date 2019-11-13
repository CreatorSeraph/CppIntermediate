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
            throw "안녕";
        case 2:
            throw 4;
        case 3:
            throw 1.5;
        default:
            throw "으악"s;
        }
    }
    //if ~ else문과 마찬가지로 catch문도 중첩하여 사용할 수 있음.
    //던져진 throw의 타입과 맞는 catch구절에서 멈추게 됨.
    catch (const char* s)
    {
        cout << "const char*를 throw함, 내용 :" << s << endl;
    }
    catch (int val)
    {
        cout << "int를 throw함, 내용 :" << val << endl;
    }
    //catch(...)의 경우는 switch문에서 default와 같은 역할을 함.
    catch (...)
    {
        cout << "다른 타입에서 잡히지 않은 throw를 감지함" << endl;
    }

    return 0;
}