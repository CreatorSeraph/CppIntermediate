#include <iostream>

int main()
{
    using namespace std;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int b;
    //try문 내부에서는 throw문을 감지할 수 있다.
    try
    {
        cout << "원하는 인덱스를 입력해 주십시오 : ";
        cin >> b;
        //아래와 같은 방식으로 throw를 하면
        if (b < 0) throw "음수의 인덱스는 사용할 수 없습니다.";
        if (b > 9) throw "배열의 사이즈를 벗어난 인덱스는 사용할 수 없습니다";
        cout << arr[b] << endl;
    }
    catch (...)
    {
        //catch문에서 잡히게 된다.
        cout << "뭔가...뭔가 문제가 생겼슴...!" << endl;
    }

    return 0;
}