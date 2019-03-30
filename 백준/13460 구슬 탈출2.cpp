#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

class myClass {
public:
	char map[10][10];
	//전에 했던 행동을 확인
	//확인 후 그 전과 돌아가는 방법은 안하기 위해서
	int before_arrow;
	//10이 되면 자동적으로 폐기
	int count;
	//빨간공 위치
	int red_ball_x;
	int red_ball_y;
	//파란공 위치
	int blue_ball_x;
	int blue_ball_y;
};


//(x,y)
int x;
int y;

char first_map[10][10];

queue<myClass> myQueue;

//(동,남,서,북)
int r_x[4] = { 1,0,-1,0 };
int r_y[4] = { 0,1,0,-1 };

void input();
void start();

int result = 11;

int main()
{
	input();
	start();

	if (result >= 11)
		result = -1;
	cout << result;
}

void start()
{
	myClass temp1, temp2;
	int i, temp_blue_x, temp_blue_y, temp_red_x, temp_red_y;
	int blue_goal = 0, red_goal = 0, temp_count;
	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();
		for (i = 0; i < 4; i++)
		{
			if (temp1.before_arrow == i)
			{
				//cout << "방향때문에 걸렸당" << endl;
				continue;
			}
			if (temp1.red_ball_x < 0)
				continue;
			if (temp1.count > 10)
				continue;
			temp_blue_x = temp1.blue_ball_x + r_x[i];
			temp_blue_y = temp1.blue_ball_y + r_y[i];
			temp_red_x = temp1.red_ball_x + r_x[i];
			temp_red_y = temp1.red_ball_y + r_y[i];
			if (temp1.map[temp_blue_x][temp_blue_y] != '.' && temp1.map[temp_blue_x][temp_blue_y] != 'O')
			{
				if (temp1.map[temp_red_x][temp_red_y] != '.' && temp1.map[temp_red_x][temp_red_y] != 'O')
				{
					//	cout << temp_blue_x << "," << temp_blue_y << "블루" << endl;
					//	cout << temp_red_x << "," << temp_red_y << "레드" << endl;
					//	cout << "갈곳이 없어서 걸렸당" << endl;
					continue;
				}
			}
			memcpy(first_map, temp1.map, sizeof(char) * 10 * 10);
			while (true)
			{
				/*
				int z1, z2;
				for (z1 = 0; z1 < 10; z1++)
				{
					for (z2 = 0; z2 < 10; z2++)
					{
						cout << temp1.map[z1][z2];
					}
					cout << endl;
				}
				cout << endl;
				*/

				if (temp1.map[temp_blue_x][temp_blue_y] != '.' && temp1.map[temp_blue_x][temp_blue_y] != 'O')
				{
					if (temp1.map[temp_red_x][temp_red_y] != '.' && temp1.map[temp_red_x][temp_red_y] != 'O' || temp_red_x < 0)
					{
						//cout << "끝났당" << endl;
						break;
					}
				}

				if (temp1.map[temp_blue_x][temp_blue_y] == '.')
				{
					temp1.map[temp_blue_x][temp_blue_y] = 'B';
					temp1.map[temp_blue_x - r_x[i]][temp_blue_y - r_y[i]] = '.';
					temp_blue_x += r_x[i];
					temp_blue_y += r_y[i];
				}
				else if (temp1.map[temp_blue_x][temp_blue_y] == 'O')
				{
					blue_goal = 1;
					break;
				}

				if (temp1.map[temp_red_x][temp_red_y] == '.' && temp_red_x >= 0)
				{
					temp1.map[temp_red_x][temp_red_y] = 'R';
					temp1.map[temp_red_x - r_x[i]][temp_red_y - r_y[i]] = '.';
					temp_red_x += r_x[i];
					temp_red_y += r_y[i];
				}
				else if (temp1.map[temp_red_x][temp_red_y] == 'O' && temp_red_x >= 0)
				{
					red_goal = 1;
					temp1.map[temp_red_x - r_x[i]][temp_red_y - r_y[i]] = '.';
					temp_red_x = -10;
					temp_red_y = -10;
				}

			}

			if (red_goal == 1 && blue_goal != 1)
			{
				temp1.count += 1;
				if (result > temp1.count)
					result = temp1.count;
				red_goal = 0;
				break;
			}
			if (red_goal == 0 && blue_goal == 0)
			{
				if (i == 0)
					temp2.before_arrow = 2;
				else if (i == 1)
					temp2.before_arrow = 3;
				else if (i == 2)
					temp2.before_arrow = 0;
				else if (i == 3)
					temp2.before_arrow = 1;
				temp2.count = temp1.count + 1;
				temp2.blue_ball_x = temp_blue_x - r_x[i];
				temp2.blue_ball_y = temp_blue_y - r_y[i];
				temp2.red_ball_x = temp_red_x - r_x[i];
				temp2.red_ball_y = temp_red_y - r_y[i];
				memcpy(temp2.map, temp1.map, sizeof(char) * 10 * 10);
				myQueue.push(temp2);
			}
			red_goal = 0;
			blue_goal = 0;
			memcpy(temp1.map, first_map, sizeof(char) * 10 * 10);
		}
	}
}


void input()
{
	int i, j;
	myClass temp;

	cin >> x;
	cin >> y;

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			cin >> first_map[i][j];
			if (first_map[i][j] == 'B')
			{
				temp.blue_ball_x = i;
				temp.blue_ball_y = j;
			}
			else if (first_map[i][j] == 'R')
			{
				temp.red_ball_x = i;
				temp.red_ball_y = j;
			}
		}
	}

	memcpy(temp.map, first_map, sizeof(char) * 10 * 10);
	temp.before_arrow = 5;
	temp.count = 0;
	myQueue.push(temp);

}