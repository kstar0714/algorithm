#include "pch.h"
#include <iostream>

using namespace std;

/*
�湮�� ����Ŭ �ΰ����� check�� �Ѵ�.
�湮�� ó�� for���� �� �� ���İ� ģ���� �� �ʿ� ���Բ� ����� �뵵��
dfs Ž���� �� �� ���¿�, ����Ŭ�� �湮�� ��� ������ �� �� �� �湮�ߴ� 
ģ������ for���� ���ؼ� ī��Ʈ �����ֱ� ���� �뵵�̴�.

*/


int testcase;
int n;
int arr[100001];
bool visited[100001];
bool cycle[100001];
int maximum;

void clear()
{
	int i;
	for (i = 0; i < 100001; i++)
	{
		visited[i] = true;
		cycle[i] = true;
	}
}

void input();
void start();
void dfs(int cur);

int main()
{
	int count;
	cin >> testcase;
	for (count = 0; count < testcase; count++)
	{
		clear();
		maximum = 0;
		input();
		start();

		cout << n - maximum << endl;
	}
}

void dfs(int cur)
{
	visited[cur] = false;
	int next = arr[cur];

	if (visited[next] == true)
	{
		dfs(next);
	}
	else if (cycle[next] == true)
	{
		for (int i = next; i != cur; i = arr[i])
		{
			maximum++;
		}
		maximum++;
	}
	cycle[cur] = false;

}

void start()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (visited[i] == true)
		{
			dfs(i);
		}
	}
}

void input()
{
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}
