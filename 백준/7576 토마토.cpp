#include<iostream>
#include<queue>

using namespace std;

class myClass {
public:
	int x;
	int y;
	int day;
};

//n이 x
int n;
//m이 y
int m;
int arr[1000][1000];
int result = 0;
queue<myClass> myQueue;

//0 동 1 남 2 서 3 북 x가 가로랑 상반
int r_x[4] = {1, 0, -1, 0};
int r_y[4] = {0, 1, 0, -1};



void input();
void fill();


int main()
{
	int i, j;
	input();
	fill();
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				result = -1;
		}
	}
	cout << result;
	
}

void fill()
{
	while (!myQueue.empty())
	{
		int i;
		int j, k;
		myClass temp;
		myClass tt;
		temp = myQueue.front();
		
		//큐에서 꺼낸 뒤 4가지 방향을 다찾고 찾은 지역을 다시 큐에 넣는다.
		//큐에 날짜 정보도 넣기
		myQueue.pop();
		if (result < temp.day)
		{
			result = temp.day;
		}

		for (i = 0; i < 4; i++)
		{
			int t_x = temp.x + r_x[i];
			int t_y = temp.y + r_y[i];
			if (t_x >= 0 && t_x <n && t_y >= 0 && t_y < m)
			{
				if (arr[t_y][t_x] == 0)
				{
					arr[t_y][t_x] = 1;
					tt.x = t_x;
					tt.y = t_y;
					tt.day = temp.day + 1;
					myQueue.push(tt);
				}
				
			}
		}
	}
}

void input()
{
	int i, j;
	myClass temp;
	cin >> n;
	cin >> m;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				temp.x = j;
				temp.y = i;
				temp.day = 0;
				myQueue.push(temp);
			}
		}
	}
}