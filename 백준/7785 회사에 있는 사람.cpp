#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

/*////////////////////////////////////////////////
set 헤더를 사용해서 풀기.
문제 자체는 어렵지 않다. 자료구조의 문제이기 때문에
얼마나 헤더를 잘 이해하고 푸느냐가 관건인듯
map 함수와 비슷하게 사용하는데 차이점은 key만 가지고
있는 것이다. 

먼저 printf로 문자열을 입력받고 leave가 나오면
insert했던 key를 지운다. 그렇게 다 하고 난 set을
for문을 돌려서 vector에 저장, 그 후 reverse를 한 후
끝~

auto it를 mySet.Begin()을 하고 != mySet.end()를 하고 ++it
를 쓴다. (*it)에 값이 있다.


////////////////////////////////////////////////*/

using namespace std;

void input();
int n;

set<string> mySet;
vector<string> myVector;

int main()
{
	int i;
	input();
	for (auto it = mySet.begin(); it != mySet.end(); ++it)
	{
		myVector.push_back((*it));
	}

	reverse(myVector.begin(), myVector.end());
	for (i = 0; i < myVector.size(); i++)
	{
		printf("%s\n", myVector[i].c_str());
	}
}

void input() {
	int i, j;
	char temp_name[10];
	char temp_EorL[10];
	string C;
	string B;
	string A = "leave";
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp_name);
		scanf("%s", temp_EorL);
		C = temp_name;
		B = temp_EorL;
		if (A.compare(B) == 0)
		{
			mySet.erase(C);
		}
		else {
			mySet.insert(C);
		}
	}
}