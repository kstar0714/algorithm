#include <iostream>
#include<algorithm>


using namespace std;

int a;
int house[25][25];
int house_count[313];
int count1=1;
int f_count= 0;

int c_x[4] = { 0,0,1,-1 };
int c_y[4] = { 1,-1,0,0 };

void input();
void dfs(int x, int y);
bool isInside(int x, int y);

int main()
{
	int i, j;
	input();
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (house[i][j] == 1)
			{
				house[i][j] = 0;
				cout << i << " " << j << " " << count1 << endl;
				dfs(i, j);
				house_count[f_count] = count1;
				count1 = 1;
				f_count++;
			}
		}
	}
	sort(house_count, house_count + f_count);

	
	cout << f_count << endl;
	for (i = 0; i < f_count; i++)
	{
		cout << house_count[i] << endl;
	}
	/*
	for (k = 0; k < a; k++)
	{
		for (l = 0; l < a; l++)
		{
			cout << house[k][l];
		}
		cout << endl;
	}
	*/
}

void input()
{
	int i, j;
	cin >> a;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			scanf("%1d", &house[i][j]);
		}
	}
}

void dfs(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (isInside(x + c_x[i], y + c_y[i]))
		{
			if (house[x + c_x[i]][y + c_y[i]] == 1)
			{
				cout << x + c_x[i] << " " << y + c_y[i] << " " << count1 +1 << endl;
				house[x + c_x[i]][y + c_y[i]] = 0;
				count1++;
				dfs(x + c_x[i], y + c_y[i]);
			}
		}
	}
}

bool isInside(int x, int y)
{
	if (x < a && y < a && x >= 0 && y >= 0)
		return true;
	return false;
}