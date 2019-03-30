#include<iostream>
#include<queue>

/*
3차원 공간배열을 생각해야 해서 어려워 보일순 있으나
기존에 동서남북만 비교를 하는 것이 아닌 상 하까지 넣어서
6방향을 조사하면서 queue에 넣는다.

다 넣은 후엔 토마토가 안 익은 부분(0)이 있는지 확인해서
결과를 도출한다.k

*/



using namespace std;

int m, n, h;

// x,y,z 0은 동 1은 남 2는 서 3은 북 4는 위 5는 아래
int r_x[6] = { 1,0,-1,0,0,0 };
int r_y[6] = { 0,1,0,-1,0,0 };
int r_z[6] = { 0,0,0,0,1,-1 };

class myClass
{
public:
	int x;
	int y;
	int z;
	int day;
};

queue<myClass> myQueue;
int arr[100][100][100];

int result = 0;

void input();
void start();
void check();

int main()
{
	input();
	start();
	check();
	cout << result;
}

void start()
{
	int i;
	myClass temp, temp2;
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();

		//		cout << "temp값" << endl;
		//		cout << "x:" << temp.x << ", y:" << temp.y << ", z:" << temp.z << endl;

		if (temp.day > result)
			result = temp.day;

		for (i = 0; i < 6; i++)
		{
			int mid_x = temp.x + r_x[i];
			int mid_y = temp.y + r_y[i];
			int mid_z = temp.z + r_z[i];

			if (mid_x >= 0 && mid_x < m && mid_y >= 0 && mid_y < n && mid_z >= 0 && mid_z < h)
			{
				if (arr[mid_x][mid_y][mid_z] == 0)
				{
					arr[mid_x][mid_y][mid_z] = 1;
					temp2.day = temp.day + 1;
					temp2.x = mid_x;
					temp2.y = mid_y;
					temp2.z = mid_z;

					myQueue.push(temp2);
				}
			}

		}

	}
}
void check()
{
	int i, j, k;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				if (arr[k][j][i] == 0)
					result = -1;
			}
		}
	}

}

void input()
{
	int i, j, k;
	myClass temp;
	cin >> m;
	cin >> n;
	cin >> h;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				cin >> arr[k][j][i];
				if (arr[k][j][i] == 1)
				{
					temp.x = k;
					temp.y = j;
					temp.z = i;
					temp.day = 0;
					myQueue.push(temp);

				}
			}
		}
	}

}