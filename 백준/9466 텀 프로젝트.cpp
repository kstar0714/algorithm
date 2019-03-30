#include "pch.h"
#include <iostream>

using namespace std;

/*
방문과 싸이클 두가지의 check를 한다.
방문은 처음 for문을 돌 때 거쳐간 친구면 할 필요 없게끔 만드는 용도와
dfs 탐색을 할 때 막는용, 싸이클은 방문이 모두 끝나고 난 후 이 방문했던 
친구들을 for문을 통해서 카운트 시켜주기 위한 용도이다.

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
