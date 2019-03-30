#include <iostream>
#include<algorithm>
#include<queue>


/*

벽을 부술 수 있는 기능이 한번 있다. 이때 어차피 돌아가서 다시 체크 할 필요는 없기 때문에 bool로 맵을 만들어 놓고 먼저 도착한 놈이
그곳을 선점해놓는다. 그렇게 푸는데 2개를 만들어서 벽을 부수고 이동한 것과 아직 사용 안 한 queue를 분리해서 bool을 체크 한다.
이동이니 4방향 모두 이동할 수 있게 하고, queue에 집어넣고 결과가 미리 나오면 break


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

//0 동, 1남, 2서 , 3북

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

