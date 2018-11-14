#include <iostream>
#include <queue>

using namespace std;

class myQueue
{
public:
	int x;
	int y;
	int dept;

};

queue<myQueue> Q;
int arr[100][100];
bool check[100][100];

int a, b;

void input();
void bps();
bool in(int x, int y);

int main()
{
	input();
	bps();
	cout << arr[a - 1][b - 1];
}

void input()
{
	int i, j, c;
	cin >> a;
	cin >> b;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			arr[i][j] = 0;
			scanf("%1d", &c);
			if (c == 1)
				check[i][j] = true;
		}
	}
}

void bps()
{
	int i;
	int checkX[4] = { 0,0,-1,1 };
	int checkY[4] = { -1,1,0,0 };
	myQueue temp;
	temp.x = 0;
	temp.y = 0;
	temp.dept = 1;
	Q.push(temp);
	arr[0][0] = 1;
	while (!Q.empty())
	{
		
		for (i = 0; i < 4; i++)
		{
			if (in(Q.front().x + checkX[i], Q.front().y + checkY[i]))
			{
				if (check[Q.front().x + checkX[i]][Q.front().y + checkY[i]])
				{
					if (arr[Q.front().x + checkX[i]][Q.front().y + checkY[i]] == 0)
					{
						temp.x = Q.front().x + checkX[i];
						temp.y = Q.front().y + checkY[i];
						temp.dept = Q.front().dept + 1;

						arr[temp.x][temp.y] = temp.dept;
						Q.push(temp);
					}
				}
			}
		}
		Q.pop();
	}
}

bool in(int x, int y)
{
	if (x < a && y < b && x >= 0 && y >= 0)
		return true;
	return false;
}