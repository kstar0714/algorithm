#include<iostream>


using namespace std;

int testcase;
int arr[50][50];
int n, m;
int worm;

int rx[4] = { 1,0,-1,0 };
int ry[4] = { 0,1,0,-1 };


void input();
void search();
void dfs(int i, int j);

int main()
{
	int i;
	int j, k;
	cin >> testcase;
	for (i = 0; i < testcase; i++)
	{
		worm = 0;
		for (j = 0; j < 50; j++)
		{
			for (k = 0; k < 50; k++)
			{
				arr[j][k] = 0;
			}
		}
		input();
		search();
		cout << worm << endl;
	}
}

void search()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				//1이 나오면 dfs 검색으로 연관된거 다 찾기
				dfs(i, j);
				worm++;
			}
		}
	}
}

void dfs(int i, int j)
{
	int k;
	//찾은거 0으로 바꿔주기
	arr[i][j] = 0;
	for (k = 0; k < 4; k++)
	{
		if (i + ry[k] >= 0 && i + ry[k] < n && j + rx[k] >= 0 && j + rx[k] < m)
		{
			if (arr[i + ry[k]][j + rx[k]] == 1)
			{
				dfs(i + ry[k], j + rx[k]);
			}
		}
	}
}

void input()
{
	int i, k;
	int x, y;
	cin >> n;
	cin >> m;
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> x;
		cin >> y;
		arr[x][y] = 1;
	}
}