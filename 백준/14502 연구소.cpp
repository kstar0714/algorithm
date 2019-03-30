#include<iostream>
#include<queue>


using namespace std;

int n, m;
int arr[8][8];
int test[8][8];
int maximum = 0;

void input();
void mapCopy(int(*a)[8], int(*b)[8]);
void wall(int wallCount);
void fillVirus();
void fill(int(*temp)[8], int x, int y);

int d_x[4] = { 0, 1, 0, -1 };
int d_y[4] = { 1,0,-1,0 };

int main()
{
	input();
	mapCopy(test, arr);
	wall(0);

	cout << maximum;
}

void fillVirus()
{
	int i, j, count = 0;
	int temp[8][8];
	mapCopy(temp, test);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (temp[i][j] == 2)
			{
				fill(temp, i, j);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
			{
				count++;
			}
		}
	}

	if (maximum < count)
	{
		maximum = count;
	}
}

void fill(int(*temp)[8], int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (x + d_x[i] >= 0 && x + d_x[i] < n && y + d_y[i] >= 0 && y + d_y[i] < m)
		{
			if (temp[x + d_x[i]][y + d_y[i]] == 0)
			{
				temp[x + d_x[i]][y + d_y[i]] = 2;
				fill(temp, x + d_x[i], y + d_y[i]);
			}
		}	
	}
}

void wall(int wallCount)
{
	int i, j;
	if (wallCount == 3)
	{
		fillVirus();
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (test[i][j] == 0)
			{
				test[i][j] = 1;
				wall(wallCount + 1);
				test[i][j] = 0;
			}
		}
	}

}

void mapCopy(int(*a)[8], int(*b)[8]) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void input()
{
	int i, j;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
}