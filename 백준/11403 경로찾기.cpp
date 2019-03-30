#include<iostream>

int n;
int arr[100][100];
int output[100][100];
bool check[100][100];

using namespace std;

void input();
void search();
void dfs(int i, int j, int start);
void a();

int main()
{
	int i, j;
	input();
	search();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
}

void a()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			check[i][j] = true;
		}
	}
}

void search()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && check[i][j] == true)
			{
				// 인접한 행렬을 찾으면 dfs로 어디까지 가나 찾고
				// 무한루프를 빼기 위해 dfs에선 false로 바꾼다
				//그렇기에 a()로 recovery 시켜준다.
				dfs(i, j, i);
				a();
			}
		}
	}
}

void dfs(int x, int y, int start)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[y][i] == 1 && check[y][i] == true)
		{
			check[y][i] = false;
			output[start][i] = 1;
			output[x][i] = 1;
			dfs(y, i, start);
		}
	}
}

void input()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			output[i][j] = arr[i][j];
			check[i][j] = true;
		}
	}
}