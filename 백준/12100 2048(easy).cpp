#include "pch.h"
#include <iostream>
#include<queue>
#include<algorithm>

/*
���� �Ǽ��� ����
1. �߰��� 0�� ���ִ°� ������
2. �ѹ� �о����� 2 2 4 8 �̰� 4 4 8 �� �ƴ϶� 16�� �Ǵ��� �˾���
3. �׷��� �� ������ ������ �־�� �Ǵ��� ��.
4. ������ 5�������� �ϴϱ� QUEUE�� �� ����


Ǫ�� ��:
4 �������� �ű�� �۾��� �Ѵ�.
�� ��� �۾� ���Ŀ� queue�� �ִ´�.
�۾��� ũ�� 2������ ������.
�ϴ� �߰��� 0�� �� �ִ°� ������ ����� �ȵǼ� �̴� ���������� 0�� �� ���ְ� �����ϰ� �о��ش�.
�� �� �� ���⿡�� �ݴ�������� ���� ���ڰ� �����ϸ� ��ġ�鼭 �Ǵٽ� �о��ش�.
�̰� while�� ��� �и� �ȵȴ�. �׷� �Ǽ��Ѵ�.

�� �Ѵ��� 5ȸ���� �Ϸ�� queue�� ���� ���� ū ���� ����ִ°� ���� maximum���� ����Ѵ�.
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

//0 ��, 1��, 2��, 3��
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
			//0�� ������ �̸� �����.
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
			//0�� ������ �̸� �����.
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
			//0�� ������ �̸� �����.
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
			//0�� ������ �̸� �����.
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

		//�о������ ���� ���� ����̸� �Ȱ����� ���ѷ�Ʈ ����
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





