#include "pch.h"
#include<iostream>
#include<queue>

/*
ù ��ŸƮ�� ��� queue�� �ֱ�
4���� ��ĭ�� �̵��ϴ� ���� queue�� �ֱ�
��� �ٽ� ���ư��ų� �̸� �ű⿡ ������ �ְ� ������ ��
�Ȱ��� ��Ʈ�� ���� ���� ���ϱ� ���� visited �迭�� ����
�׷��� 3�� ������ ���� break;
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