#include<iostream>
#include<deque>
using namespace std;

class myClass {
public:
	int x;
	int y;
};
int snake_size = 1;
deque<myClass> snake;
int arrow = 0; //0은 동 1는 남 2은 서 3는 북;
int arrow_x[4] = { 0,1, 0,-1 };
int arrow_y[4] = { 1,0, -1, 0 };
int board_size;
int board[100][100];

int apple;
int change;

int change1 = 0;
int change_count[100];

char change_move[100];
int timer = 1;
int change_timer = 0;

void input();
void start();
bool wall_check();

int main()
{
	myClass temp;
	temp.x = 0;
	temp.y = 0;
	snake.push_back(temp);
	input();
	start();

	cout << timer;
}

void input()
{
	int i, j;
	int a, b;
	cin >> board_size;
	for (i = 0; i < board_size; i++)
	{
		for (j = 0; j < board_size; j++)
		{
			board[i][j] = 0;
		}
	}
	cin >> apple;
	for (i = 0; i < apple; i++)
	{
		cin >> a;
		cin >> b;
		board[a - 1][b - 1] = 1;
	}
	cin >> change;
	for (i = 0; i < change; i++)
	{
		cin >> change_count[i];
		cin >> change_move[i];
	}
}
//벽에 부딫히는지
bool wall_check()
{
	if (arrow == 0)
	{
		if (snake.front().y + 1 < board_size)
			return true;
	}
	else if (arrow == 1)
	{
		if (snake.front().x + 1 < board_size)
		{
			return true;
		}

	}
	else if (arrow == 2)
	{
		if (snake.front().y - 1 >= 0)
			return true;
	}
	else if (arrow == 3)
	{
		if (snake.front().x - 1 >= 0)
			return true;
	}

	return false;
}
//자기 몸에 부딪혔는지
bool snake_body_check()
{
	int i;
	for (i = 1; i < snake_size; i++)
	{
		if (snake[0].x + arrow_x[arrow] == snake[i].x && snake[0].y + arrow_y[arrow] == snake[i].y)
		{
			return false;
		}
	}
	return true;
}

void start()
{
	int i;
	myClass temp;

	while (true)
	{
		if (!wall_check())
			break;
		if (!snake_body_check())
			break;

		temp.x = snake.front().x + arrow_x[arrow];
		temp.y = snake.front().y + arrow_y[arrow];
		snake.push_front(temp);
		if (board[temp.x][temp.y] == 1)
		{
			snake_size++;
			board[temp.x][temp.y] = 0;
		}
		else {
			snake.pop_back();
		}
		change_timer++;
		timer++;
		if (change_timer == change_count[change1])
		{
			char a = change_move[change1];
			if (a == 'L')
			{
				arrow -= 1;
				if (arrow < 0)
					arrow = 3;
			}
			else if (a == 'D')
			{
				arrow += 1;
				if (arrow > 3)
					arrow = 0;
			}
			change1++;

		}

	}
}