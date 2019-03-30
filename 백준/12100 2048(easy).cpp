#include "pch.h"
#include <iostream>
#include<queue>
#include<algorithm>

/*
많이 실수한 이유
1. 중간에 0이 껴있는걸 간과함
2. 한번 밀었을때 2 2 4 8 이게 4 4 8 이 아니라 16이 되는줄 알았음
3. 그래서 전 방향을 가지고 있어야 되는줄 앎.
4. 어차피 5번까지만 하니깐 QUEUE에 막 넣음


푸는 법:
4 방향으로 옮기는 작업을 한다.
이 모든 작업 이후엔 queue에 넣는다.
작업은 크게 2가지로 나뉜다.
일단 중간에 0이 들어가 있는거 때문에 계산이 안되서 미는 방향쪽으로 0을 다 없애고 빽빽하게 밀어준다.
그 후 민 방향에서 반대방향으로 같은 숫자가 인접하면 합치면서 또다시 밀어준다.
이건 while로 계속 밀면 안된다. 그럼 실수한다.

다 한다음 5회전이 완료된 queue는 빼서 제일 큰 수가 들어있는걸 빼서 maximum으로 출력한다.
*/

using namespace std;

class myClass {
public:
	int Class_arr[20][20];
	int count;
};

queue<myClass> myQueue;

int n;
int arr_2048[20][20];

//0 남, 1동, 2북, 3서
int r_x[4] = { 1,0,-1,0 };
int r_y[4] = { 0,1,0,-1 };

int maximum = 0;

void input();
void start();
void go(int go_arrow, myClass temp_class);
int main()
{
	input();
	start();

	cout << maximum << endl;
}

void start()
{
	myClass temp1;
	int i, max_i, max_j, temp_max;
	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();
		if (temp1.count >= 5)
		{
			temp_max = 0;
			for (max_i = 0; max_i < n; max_i++)
			{
				for (max_j = 0; max_j < n; max_j++)
				{
					if (temp_max < temp1.Class_arr[max_i][max_j])
						temp_max = temp1.Class_arr[max_i][max_j];
				}
			}
			if (maximum < temp_max)
				maximum = temp_max;
		}
		else
		{
			for (i = 0; i < 4; i++)
			{
				go(i, temp1);
			}
		}

	}
}

void go(int go_arrow, myClass temp_class)
{
	int before_arr[20][20];
	int after_arr[20][20];
	int i, j, k, break_int;
	copy(&temp_class.Class_arr[0][0], &temp_class.Class_arr[0][0] + 20 * 20, &before_arr[0][0]);
	copy(&temp_class.Class_arr[0][0], &temp_class.Class_arr[0][0] + 20 * 20, &after_arr[0][0]);
	myClass temp2;

	while (true)
	{
		if (go_arrow == 0)
		{
			//0이 있으면 미리 땡긴다.
			for (i = 0; i < n; i++)
			{
				for (j = n - 1; j > 0; j--)
				{
					if (before_arr[i][j] == 0)
					{
						for (k = j; k > 0; k--)
						{
							before_arr[i][k] = before_arr[i][k - 1];
							before_arr[i][k - 1] = 0;
						}
					}
				}
			}
		}
		else if (go_arrow == 1)
		{
			//0이 있으면 미리 땡긴다.
			for (i = n - 1; i > 0; i--)
			{
				for (j = 0; j < n; j++)
				{
					if (before_arr[i][j] == 0)
					{
						for (k = i; k > 0; k--)
						{
							before_arr[k][j] = before_arr[k - 1][j];
							before_arr[k - 1][j] = 0;
						}
					}
				}
			}
		}
		else if (go_arrow == 2)
		{
			//0이 있으면 미리 땡긴다.
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n - 1; j++)
				{
					if (before_arr[i][j] == 0)
					{
						for (k = j; k < n - 1; k++)
						{
							before_arr[i][k] = before_arr[i][k + 1];
							before_arr[i][k + 1] = 0;
						}
					}
				}
			}
		}
		else if (go_arrow == 3)
		{
			//0이 있으면 미리 땡긴다.
			for (i = 0; i < n - 1; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (before_arr[i][j] == 0)
					{
						for (k = i; k < n - 1; k++)
						{
							before_arr[k][j] = before_arr[k + 1][j];
							before_arr[k + 1][j] = 0;
						}
					}
				}
			}
		}

		//밀어넣을때 전과 같은 모양이면 똑같으니 무한루트 해제
		break_int = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (before_arr[i][j] != after_arr[i][j])
				{
					break_int = 0;
				}
			}
		}
		if (break_int == 1)
			break;
		///////////////////////////////////////////////////////////
		copy(&before_arr[0][0], &before_arr[0][0] + 20 * 20, &after_arr[0][0]);

	}

	if (go_arrow == 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = n - 1; j > 0; j--)
			{
				if (before_arr[i][j] == before_arr[i][j - 1])
				{
					before_arr[i][j] *= 2;
					before_arr[i][j - 1] = 0;
					for (k = j - 1; k > 0; k--)
					{
						before_arr[i][k] = before_arr[i][k - 1];
						before_arr[i][k - 1] = 0;
					}
				}
			}
		}
	}
	else if (go_arrow == 1)
	{
		for (i = n - 1; i > 0; i--)
		{
			for (j = 0; j < n; j++)
			{
				if (before_arr[i][j] == before_arr[i - 1][j])
				{
					before_arr[i][j] *= 2;
					before_arr[i - 1][j] = 0;
					for (k = i - 1; k > 0; k--)
					{
						before_arr[k][j] = before_arr[k - 1][j];
						before_arr[k - 1][j] = 0;
					}
				}
			}
		}
	}
	else if (go_arrow == 2)
	{

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (before_arr[i][j] == before_arr[i][j + 1])
				{
					before_arr[i][j] *= 2;
					before_arr[i][j + 1] = 0;
					for (k = j + 1; k < n - 1; k++)
					{
						before_arr[i][k] = before_arr[i][k + 1];
						before_arr[i][k + 1] = 0;
					}
				}
			}
		}
	}
	else if (go_arrow == 3)
	{
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (before_arr[i][j] == before_arr[i + 1][j])
				{
					before_arr[i][j] *= 2;
					before_arr[i + 1][j] = 0;
					for (k = i + 1; k < n - 1; k++)
					{
						before_arr[k][j] = before_arr[k + 1][j];
						before_arr[k + 1][j] = 0;
					}
				}
			}
		}
	}

	copy(&before_arr[0][0], &before_arr[0][0] + 20 * 20, &after_arr[0][0]);

	copy(&after_arr[0][0], &after_arr[0][0] + 20 * 20, &temp2.Class_arr[0][0]);
	temp2.count = temp_class.count + 1;
	myQueue.push(temp2);
}

void input()
{
	myClass temp;
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr_2048[i][j];
		}
	}
	copy(&arr_2048[0][0], &arr_2048[0][0] + 20 * 20, &temp.Class_arr[0][0]);
	temp.count = 0;

	myQueue.push(temp);
}





