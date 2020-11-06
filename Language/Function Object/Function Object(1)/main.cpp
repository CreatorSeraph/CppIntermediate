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
        cout << "����Լ� - ClassFunc1 �۵�" << endl;
    }

    int ClassFunc2(int _arg)
    {
        cout << "����Լ� - ClassFunc2 �۵�" << endl;

        return _arg << 4;
    }

    static void ClassStaticFunction()
    {
        cout << "Ŭ����Static�Լ� - ClassStaticFunction �۵�" << endl;
    }
};

void StaticFunc1()
{
    cout << "�����Լ� - StaticFunc1 �۵�" << endl;
}

int StaticFunc2(int _arg)
{
    cout << "�����Լ� - StaticFunc2 �۵�" << endl;

    return _arg >> 2;
}

int main()
{
    //�Լ� ��ü(�Լ��� �����ϴ� ����(?))
    function<void()> functionObj;

    //�̷��� ��ȣ�� �ٿ��� ȣ��(Call)�Ҽ� �ִ� �� ��� Callable�̶�� �Ѵ�.
    //https://modoocode.com/254 ���⿡ �� �� �����س���...
    //�ƹ��Լ��� ����Ǿ����� ���� function��ü�� ȣ���� ��� ��Ÿ�� ������ �߻� �Ѵ�.
    //functionObj(); //Error!

    //std::function�� �̷� Callable�� ������ �� �ִ�.
    functionObj = StaticFunc1;
    functionObj();

    //�Լ��� Static����Լ��� �ٷ� ������ �� �ִ�.
    functionObj = TestClass::ClassStaticFunction;
    functionObj();

    //Ŭ������ ��� �Լ����� ���� ���������� ������ �ʴ� �Լ� ���ڰ� �����Ѵ�.
    //�׵� �׷��� ����Լ��� ȣ�����ִ� Ŭ������ �־�����ݾ�...
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