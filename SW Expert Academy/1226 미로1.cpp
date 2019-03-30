#include "pch.h"
#include<iostream>
#include<queue>

/*
첫 스타트를 잡고 queue에 넣기
4방향 한칸씩 이동하는 것을 queue에 넣기
대신 다시 돌아가거나 미리 거기에 도착한 애가 있으면 또
똑같은 루트로 도는 것을 피하기 위해 visited 배열을 만듬
그런뒤 3을 만나는 순간 break;
*/


class MyClass
{
public:
	int x;
	int y;
};

using namespace std;

int arr[16][16];
bool visited[16][16];
queue<MyClass> myQueue;

int r_x[4] = { 0,1,0,-1 };
int r_y[4] = { 1,0,-1,0 };

int result;

void erase();
void input();
void start();

int main()
{
	int i;
	for (i = 1; i < 11; i++)
	{
		result = 0;
		erase();
		input();
		start();
		printf("#%d %d\n", i, result);
	}

}


void erase()
{
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			visited[i][j] = true;
		}
	}
}

void start()
{
	MyClass temp1, temp2;
	int i;
	int start_r_x, start_r_y;
	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();
		visited[temp1.x][temp1.y] = false;
		for (i = 0; i < 4; i++)
		{
			start_r_x = temp1.x + r_x[i];
			start_r_y = temp1.y + r_y[i];
			if (start_r_x >= 0 && start_r_x < 16 && start_r_y >= 0 && start_r_y < 16)
			{
				if (visited[start_r_x][start_r_y] == true && arr[start_r_x][start_r_y] == 0)
				{
					temp2.x = start_r_x;
					temp2.y = start_r_y;
					myQueue.push(temp2);
				}
				else if (arr[start_r_x][start_r_y] == 3)
				{
					result = 1;
					break;
				}

			}
		}

	}
}

void input()
{
	int i, j;
	scanf("%d", &i);
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 2)
			{
				MyClass temp;
				temp.x = i;
				temp.y = j;
				myQueue.push(temp);
			}
		}
	}
}