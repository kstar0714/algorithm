#include<iostream>
#include<queue>
#include<utility>

/*//////////////////////////////////////////////////

n���� �迭�� �Է��� �޴´�
�Է��� ���� �� max_height�� �����Ѵ�.
���� ���� ���밡 ������������ ������ �Ŀ� ���� ����
�ִ�ġ�� 100���� �ȵ����� �Ѵ�.

���� ���̸� 0(�� �ȿ�)����
max_height(�ִ� �������)���� for���� �����鼭 ����
�������� ������ ���� ���� �����Ѵ�.

���� recovery�Լ��� �̿��Ͽ� check �迭�� �ʱ�ȭ �����ְ�
�� �� ���� for�������� i���̶� ���Ͽ� ���� ���� ����
false�� ���ش�. �� ���� �ڿ� true�� �پ� �ִ°��� �ٽ� ã��
ã���� bfs�Լ��� ������Ѽ� ������ ���� ��� false ��Ų��
�� �۾��� �ѹ� ������ temp_safty_zone�� ++ �����ش�.

�ѹ��� for���� ������ safty_zone�� ũ�� ���Ͽ� �־��ش�

//////////////////////////////////////////////////*/


using namespace std;

int n;
int max_height = 0;
//[][]���μ���
int arr[100][100];
bool check[100][100];

//�������� �ִ� ����
int safty_zone = 0;
//�� ���� ������ temp�� �����ѵ� safty_zone�̶� �񱳿�
int temp_safty_zone = 0;

void input();
void recovery();
void search();
void bfs(int x, int y);

//queue�� x,y���� ����
queue<pair<int, int>> myQueue;

//0 �� 1�� 2�� 3��
int r_x[4] = { 1, 0, -1, 0 };
int r_y[4] = { 0,1, 0, -1 };

int main()
{
	input();
	search();
	cout << safty_zone;
}

void search()
{
	int i, j, k;
	//�� ������ ���� 0���� ��� ���� ������
	for (i = 0; i < max_height; i++)
	{
		//�迭�� Ȯ���ؼ� �� ���� ������ check�Լ��� false�� �����
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (arr[j][k] <= i)
				{
					check[j][k] = false;
				}
			}
		}

		//�� ����� ���� ���� ã���� bfs�� �������� ��� false�� ����� ++���ֱ�
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (check[j][k] == true)
				{
					bfs(j, k);
					temp_safty_zone++;
				}
			}
		}
		//ũ�� ��
		if (safty_zone < temp_safty_zone)
			safty_zone = temp_safty_zone;

		//�ٽ� �ʱ�ȭ �ϴ� ��
		recovery();
		temp_safty_zone = 0;
	}
}

void bfs(int x, int y)
{
	int i;
	pair<int, int> temp = make_pair(x, y);
	pair<int, int> temp2;
	//queue�� �ϳ� �ֱ�
	myQueue.push(temp);
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();

		//�����¿� �������� Ȯ���ϱ�
		for (i = 0; i < 4; i++)
		{
			//n�迭�ȿ��� �����
			if (temp.first + r_x[i] >= 0 && temp.first + r_x[i] < n && temp.second + r_y[i] >= 0 && temp.second + r_y[i] < n)
			{
				//�������� �´���
				if (check[temp.first + r_x[i]][temp.second + r_y[i]] == true)
				{
					check[temp.first + r_x[i]][temp.second + r_y[i]] = false;
					temp2 = make_pair(temp.first + r_x[i], temp.second + r_y[i]);
					myQueue.push(temp2);
				}
			}
		}
	}
}

//check�Լ� true�� ��� ������ִ� �Լ�
void recovery()
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
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > max_height)
			{
				max_height = arr[i][j];
			}
		}
	}
	recovery();
}

