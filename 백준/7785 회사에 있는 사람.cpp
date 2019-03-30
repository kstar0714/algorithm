#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

/*////////////////////////////////////////////////
set ����� ����ؼ� Ǯ��.
���� ��ü�� ����� �ʴ�. �ڷᱸ���� �����̱� ������
�󸶳� ����� �� �����ϰ� Ǫ���İ� �����ε�
map �Լ��� ����ϰ� ����ϴµ� �������� key�� ������
�ִ� ���̴�. 

���� printf�� ���ڿ��� �Է¹ް� leave�� ������
insert�ߴ� key�� �����. �׷��� �� �ϰ� �� set��
for���� ������ vector�� ����, �� �� reverse�� �� ��
��~

auto it�� mySet.Begin()�� �ϰ� != mySet.end()�� �ϰ� ++it
�� ����. (*it)�� ���� �ִ�.


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