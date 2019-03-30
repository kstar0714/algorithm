#include<iostream>
#include<queue>



//많이 어려운건 없어서 주석이 없음

using namespace std;

class MyClass
{
public:
	int x;
	int y;
	char ch;
};



int n;
char arr[100][100];
bool check[100][100];

//x,y  0 동 1남 2서 3북
int r_x[4] = { 0,1,0,-1 };
int r_y[4] = { 1,0,-1,0 };

queue<MyClass> myQueue;

int result = 0;
int result2 = 0;

void input();
void clear();
void start();
void bfs1(char ch, int i, int j);
void bfs2(char ch, int i, int j);

int main()
{
	input();
	start();
	cout << result << " " << result2;
}

void start()
{
	int i, j;
	clear();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (check[i][j] == true)
			{
				bfs1(arr[i][j], i, j);
				result++;
			}
		}
	}
	clear();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (check[i][j] == true)
			{
				bfs2(arr[i][j], i, j);
				result2++;
			}
		}
	}
}

void bfs1(char ch, int i, int j)
{
	MyClass temp, temp1;
	int temp_i;
	temp.ch = ch;
	temp.x = i;
	temp.y = j;

	myQueue.push(temp);
	check[i][j] = false;

	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();
		for (temp_i = 0; temp_i < 4; temp_i++)
		{
			if (r_x[temp_i] + temp1.x >= 0 && r_x[temp_i] + temp1.x < n && r_y[temp_i] + temp1.y >= 0 && r_y[temp_i] + temp1.y < n)
			{
				if (check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == true)
				{
					if (arr[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == temp.ch)
					{
						temp.ch = temp1.ch;
						temp.x = r_x[temp_i] + temp1.x;
						temp.y = r_y[temp_i] + temp1.y;
						myQueue.push(temp);
						check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] = false;
					}
				}
			}
		}
	}

}

void bfs2(char ch, int i, int j)
{
	MyClass temp, temp1;
	int temp_i;
	temp.ch = ch;
	temp.x = i;
	temp.y = j;

	myQueue.push(temp);
	check[i][j] = false;

	while (!myQueue.empty())
	{
		temp1 = myQueue.front();
		myQueue.pop();
		for (temp_i = 0; temp_i < 4; temp_i++)
		{
			if (r_x[temp_i] + temp1.x >= 0 && r_x[temp_i] + temp1.x < n && r_y[temp_i] + temp1.y >= 0 && r_y[temp_i] + temp1.y < n)
			{
				if (check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == true)
				{
					if (arr[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == temp.ch)
					{
						temp.ch = temp1.ch;
						temp.x = r_x[temp_i] + temp1.x;
						temp.y = r_y[temp_i] + temp1.y;
						myQueue.push(temp);
						check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] = false;
					}
					else if (temp.ch == 'R' && arr[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == 'G')
					{
						temp.ch = temp1.ch;
						temp.x = r_x[temp_i] + temp1.x;
						temp.y = r_y[temp_i] + temp1.y;
						myQueue.push(temp);
						check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] = false;
					}
					else if (temp.ch == 'G' && arr[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] == 'R')
					{
						temp.ch = temp1.ch;
						temp.x = r_x[temp_i] + temp1.x;
						temp.y = r_y[temp_i] + temp1.y;
						myQueue.push(temp);
						check[r_x[temp_i] + temp1.x][r_y[temp_i] + temp1.y] = false;
					}
				}
			}
		}
	}

}

void clear()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			check[i][j] = true;
		}
	}
}

void input()
{
	int i, j;
	char temp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> temp;
			arr[i][j] = temp;
		}
	}

}
