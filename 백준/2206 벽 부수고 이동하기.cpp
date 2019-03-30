#include <iostream>
#include<algorithm>
#include<queue>


/*

���� �μ� �� �ִ� ����� �ѹ� �ִ�. �̶� ������ ���ư��� �ٽ� üũ �� �ʿ�� ���� ������ bool�� ���� ����� ���� ���� ������ ����
�װ��� �����س��´�. �׷��� Ǫ�µ� 2���� ���� ���� �μ��� �̵��� �Ͱ� ���� ��� �� �� queue�� �и��ؼ� bool�� üũ �Ѵ�.
�̵��̴� 4���� ��� �̵��� �� �ְ� �ϰ�, queue�� ����ְ� ����� �̸� ������ break


*/


using namespace std;

class myClass {
public:
	int x;
	int y;
	int count;
	int breakWall;
};


queue<myClass> myQueue;



int n, m;
//(n,m) (x,y)
int arr[1000][1000];
bool trueArrCheck[2][1000][1000];
int result = 0;

//0 ��, 1��, 2�� , 3��

int r_x[4] = { 1,0,-1,0 };
int r_y[4] = { 0,1,0,-1 };


void input();
void start();

int main()
{
	int i, j, k;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 1000; i++)
		{
			for (j = 0; j < 1000; j++)
			{
				trueArrCheck[k][i][j] = true;
			}
		}
	}


	input();

	start();

	if (result == 0)
		result = -1;

	cout << result;

}



void start()
{
	myClass temp1, temp2;
	int i;
	int temp_r_x, temp_r_y;
	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();

		if (temp1.x == n - 1 && temp1.y == m - 1)
		{
			result = temp1.count;
			break;
		}
		for (i = 0; i < 4; i++)
		{
			temp_r_x = temp1.x + r_x[i];
			temp_r_y = temp1.y + r_y[i];

			if (temp_r_x >= 0 && temp_r_x < n && temp_r_y >= 0 && temp_r_y < m)
			{
				if (arr[temp_r_x][temp_r_y] == 0 && trueArrCheck[temp1.breakWall][temp_r_x][temp_r_y] == true)
				{
					//no wall so can move
					temp2.x = temp_r_x;
					temp2.y = temp_r_y;
					trueArrCheck[temp1.breakWall][temp_r_x][temp_r_y] = false;
					temp2.breakWall = temp1.breakWall;
					temp2.count = temp1.count + 1;
					myQueue.push(temp2);

				}
				else if (arr[temp_r_x][temp_r_y] == 1 && temp1.breakWall == 1)
				{
					// have wall but can break;
					temp2.breakWall = 0;
					temp2.x = temp_r_x;
					temp2.y = temp_r_y;
					trueArrCheck[temp2.breakWall][temp_r_x][temp_r_y] = false;
					temp2.count = temp1.count + 1;
					myQueue.push(temp2);
				}
			}
		}
	}
}

void input()
{
	scanf("%d", &n);
	scanf("%d", &m);
	int i, j;

	myClass temp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	temp.breakWall = 1;
	temp.count = 1;
	temp.x = 0;
	temp.y = 0;
	myQueue.push(temp);
}

