#include<iostream>
#include<queue>

/*
3���� �����迭�� �����ؾ� �ؼ� ����� ���ϼ� ������
������ �������ϸ� �񱳸� �ϴ� ���� �ƴ� �� �ϱ��� �־
6������ �����ϸ鼭 queue�� �ִ´�.

�� ���� �Ŀ� �丶�䰡 �� ���� �κ�(0)�� �ִ��� Ȯ���ؼ�
����� �����Ѵ�.k

*/



using namespace std;

int m, n, h;

// x,y,z 0�� �� 1�� �� 2�� �� 3�� �� 4�� �� 5�� �Ʒ�
int r_x[6] = { 1,0,-1,0,0,0 };
int r_y[6] = { 0,1,0,-1,0,0 };
int r_z[6] = { 0,0,0,0,1,-1 };

class myClass
{
public:
	int x;
	int y;
	int z;
	int day;
};

queue<myClass> myQueue;
int arr[100][100][100];

int result = 0;

void input();
void start();
void check();

int main()
{
	input();
	start();
	check();
	cout << result;
}

void start()
{
	int i;
	myClass temp, temp2;
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();

		//		cout << "temp��" << endl;
		//		cout << "x:" << temp.x << ", y:" << temp.y << ", z:" << temp.z << endl;

		if (temp.day > result)
			result = temp.day;

		for (i = 0; i < 6; i++)
		{
			int mid_x = temp.x + r_x[i];
			int mid_y = temp.y + r_y[i];
			int mid_z = temp.z + r_z[i];

			if (mid_x >= 0 && mid_x < m && mid_y >= 0 && mid_y < n && mid_z >= 0 && mid_z < h)
			{
				if (arr[mid_x][mid_y][mid_z] == 0)
				{
					arr[mid_x][mid_y][mid_z] = 1;
					temp2.day = temp.day + 1;
					temp2.x = mid_x;
					temp2.y = mid_y;
					temp2.z = mid_z;

					myQueue.push(temp2);
				}
			}

		}

	}
}
void check()
{
	int i, j, k;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				if (arr[k][j][i] == 0)
					result = -1;
			}
		}
	}

}

void input()
{
	int i, j, k;
	myClass temp;
	cin >> m;
	cin >> n;
	cin >> h;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				cin >> arr[k][j][i];
				if (arr[k][j][i] == 1)
				{
					temp.x = k;
					temp.y = j;
					temp.z = i;
					temp.day = 0;
					myQueue.push(temp);

				}
			}
		}
	}

}