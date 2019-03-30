#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

/*/////////////////////////////////////////////////////////

����� ������ ���� �ƴϴ�.
map �Լ��� �Ἥ Ǯ��� ã�� �ð��� ����ȴ�.
���Ǹ� �ؾߵ����� cin cout ���� printf, scanf�� �� ������.

�׷��� �ٸ��� �����Ұ� ���� �ð� �ʰ��� ���� ���ϱ�
scanf printf�� �̿�����.

���ڿ��� �Է� �޾Ƽ� map�� vector�� �ִ´�.
map���� �ִ� ������ string���� �޾��� �� ��ȣ�� ã�� ���� �ϱ�
���ؼ��̰�, vector���� �ִ� ������ ���ڸ� �Է� �޾��� �� 
�ٷ� ����ϱ� ���ؼ���.

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