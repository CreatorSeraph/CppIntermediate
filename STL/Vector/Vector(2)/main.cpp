#include <iostream>
#include "CVector.h"

int main()
{
	using namespace std;
	CVector<int> vec;

	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(5);
	//4,1,2,5

	vec.pop_back();
	//4,1,2

	vec.insert(1, 3);
	//4,3,1,2
	vec.erase(2);
	//4,3,2

	for (int i = 0; i < vec.size(); ++i)//배열에서 반복문 돌리듯이 번호를 통해 접근하기
	{
		cout << vec[i] << "\t";
	}
	cout << endl;

	return 0;
}