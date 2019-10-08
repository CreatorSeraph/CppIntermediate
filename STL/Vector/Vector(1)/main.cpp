//Vector(1)������ C++ STL���� �����ϴ� �⺻ vector�� ��ɵ��� �Ұ��մϴ�.
//C++ STL�� vector�� ���ؼ��� https://github.com/CreatorSeraph/CppIntermediate/wiki/STL---Vector �̰��� �����غ���.

#include <iostream>
#include <vector>

int main()
{
	using namespace std;
	vector<int> vec1;//����ִ� ���͸� �����.
	vector<int> vec2 = { 1,5,3,4 };//1,5,3,4 �����͸� ���� ���͸� �����.
	vector<int> vec3 = vec2;//vec2�� �����͸� �����ؼ� vec3�� �����.

	vec1.push_back(4);//������ �� �ڿ� 4 �����͸� �߰��Ѵ�.
	vec1.push_back(1);//������ �� �ڿ� 1 �����͸� �߰��Ѵ�.
	vec1.push_back(2);//������ �� �ڿ� 2 �����͸� �߰��Ѵ�.
	//vec1���� 4,1,2�� ����ִ�.

	//vec2���� 1,5,3,4�� ����ִ�
	vec2.pop_back();//������ �� �ڿ��� �����͸� �����Ѵ�.
	//���� vec2���� 1,5,3�� ����ִ�.

	for (int i = 0; i < vec1.size(); ++i)//�迭���� �ݺ��� �������� ��ȣ�� ���� �����ϱ�
	{
		cout << vec1[i] << "\t";
	}
	cout << endl;

	for (auto iter = vec2.begin(); iter != vec2.end(); ++iter)//iterator�� ���� �����ϱ�
	{
		cout << (*iter) << "\t";
	}
	cout << endl;

	//vec3���� 1,5,3,4�� ����ִ�.
	for (auto& iter : vec3)//���� ��� �ݺ���
	{
		cout << iter << "\t";
	}
	cout << endl;

	//vec3���� 1,5,3,4�� ����ִ�.
	vec3.erase(vec3.begin() + 2);//vec3[2]�� �����ϰ�, vec3[3]������ ������ ��ĭ�� ������ ����.
	//vec3�� 1,5,4�� ����ִ�.
	vec3.insert(vec3.begin() + 1, 2);//vec3[1]�ڸ��� ���ο� ���� �߰��ϰ� vec3[1]������ ������ ��ĭ�� �ڷ� �о��.
	//vec3�� 1,2,5,4�� ����ִ�.

	for (auto& iter : vec3)
	{
		cout << iter << "\t";
	}
	cout << endl;
		
	return 0;
}