//Vector(1)에서는 C++ STL에서 지원하는 기본 vector의 기능들을 소개합니다.
//C++ STL의 vector에 대해서는 https://github.com/CreatorSeraph/CppIntermediate/wiki/STL---Vector 이곳을 참고해보자.

#include <iostream>
#include <vector>

int main()
{
	using namespace std;
	vector<int> vec1;//비어있는 벡터를 만든다.
	vector<int> vec2 = { 1,5,3,4 };//1,5,3,4 데이터를 가진 벡터를 만든다.
	vector<int> vec3 = vec2;//vec2의 데이터를 복사해서 vec3을 만든다.

	vec1.push_back(4);//벡터의 맨 뒤에 4 데이터를 추가한다.
	vec1.push_back(1);//벡터의 맨 뒤에 1 데이터를 추가한다.
	vec1.push_back(2);//벡터의 맨 뒤에 2 데이터를 추가한다.
	//vec1에는 4,1,2가 들어있다.

	//vec2에는 1,5,3,4가 들어있다
	vec2.pop_back();//벡터의 맨 뒤에서 데이터를 삭제한다.
	//이제 vec2에는 1,5,3이 들어있다.

	for (int i = 0; i < vec1.size(); ++i)//배열에서 반복문 돌리듯이 번호를 통해 접근하기
	{
		cout << vec1[i] << "\t";
	}
	cout << endl;

	for (auto iter = vec2.begin(); iter != vec2.end(); ++iter)//iterator를 통해 접근하기
	{
		cout << (*iter) << "\t";
	}
	cout << endl;

	//vec3에는 1,5,3,4가 들어있다.
	for (auto& iter : vec3)//범위 기반 반복문
	{
		cout << iter << "\t";
	}
	cout << endl;

	//vec3에는 1,5,3,4가 들어있다.
	vec3.erase(vec3.begin() + 2);//vec3[2]를 제거하고, vec3[3]이후의 값들을 한칸씩 앞으로 당긴다.
	//vec3에 1,5,4가 들어있다.
	vec3.insert(vec3.begin() + 1, 2);//vec3[1]자리에 새로운 값을 추가하고 vec3[1]이후의 값들을 한칸씩 뒤로 밀어낸다.
	//vec3에 1,2,5,4가 들어있다.

	for (auto& iter : vec3)
	{
		cout << iter << "\t";
	}
	cout << endl;
		
	return 0;
}