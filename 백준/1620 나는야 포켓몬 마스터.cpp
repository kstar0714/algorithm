#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

/*/////////////////////////////////////////////////////////

어려운 문제는 절대 아니다.
map 함수를 써서 풀어야 찾는 시간이 단축된다.
주의를 해야될점은 cin cout 보단 printf, scanf가 더 빠르다.

그래서 다른건 주의할것 없이 시간 초과가 많이 나니깐
scanf printf를 이용하자.

문자열을 입력 받아서 map과 vector에 넣는다.
map에다 넣는 이유는 string으로 받았을 때 번호를 찾기 쉽게 하기
위해서이고, vector에다 넣는 이유는 숫자를 입력 받았을 때 
바로 출력하기 위해서다.

/////////////////////////////////////////////////////////*/

int n;
int m;

map<string, int> myMap;
vector<string> myVector;
void input();
void search();

int main()
{
	input();
	search();
}

void search()
{
	char temp[20];
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%s", temp);
		if (isdigit(temp[0]))
		{
			string a = temp;
			printf("%s\n", myVector[stoi(temp) - 1].c_str());
		}
		else
		{
			printf("%d\n", myMap.find(temp)->second + 1);
		}
	}
}

void input()
{
	int i;
	char temp[20];

	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		myMap.insert(make_pair(temp, i));
		myVector.push_back(temp);
	}
}