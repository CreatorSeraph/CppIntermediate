#include <iostream>
#include <functional>

using namespace std;

class TestClass
{
private:
    int val;
public:
    TestClass() = default;
    ~TestClass() = default;

    void ClassFunc1()
    {
        cout << "멤버함수 - ClassFunc1 작동" << endl;
    }

    int ClassFunc2(int _arg)
    {
        cout << "멤버함수 - ClassFunc2 작동" << endl;

        return _arg << 4;
    }

    static void ClassStaticFunction()
    {
        cout << "클래스Static함수 - ClassStaticFunction 작동" << endl;
    }
};

void StaticFunc1()
{
    cout << "전역함수 - StaticFunc1 작동" << endl;
}

int StaticFunc2(int _arg)
{
    cout << "전역함수 - StaticFunc2 작동" << endl;

    return _arg >> 2;
}

int main()
{
    //함수 객체(함수를 저장하는 변수(?))
    function<void()> functionObj;

    //이렇게 괄호를 붙여서 호출(Call)할수 있는 건 모두 Callable이라고 한다.
    //https://modoocode.com/254 여기에 더 잘 정리해놨네...
    //아무함수도 저장되어있지 않은 function객체를 호출할 경우 런타임 에러가 발생 한다.
    //functionObj(); //Error!

    //std::function은 이런 Callable을 저장할 수 있다.
    functionObj = StaticFunc1;
    functionObj();

    //함수의 Static멤버함수도 바로 저장할 수 있다.
    functionObj = TestClass::ClassStaticFunction;
    functionObj();

    //클래스의 멤버 함수같은 경우는 내부적으로 보이지 않는 함수 인자가 존재한다.
    //그도 그럴게 멤버함수면 호출해주는 클래스가 있어야하잖아...
    //functionObj = TestClass::ClassFunc1; //Error!
    functionObj = []() {
        TestClass temp1;
        temp1.ClassFunc1();
    };
    functionObj();

    //or
    TestClass temp2;
    function<void(TestClass)> memberFunctionObj = TestClass::ClassFunc1;
    memberFunctionObj(temp2);

    return 0;
}