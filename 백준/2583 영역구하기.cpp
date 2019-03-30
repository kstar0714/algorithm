#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<vector>

/*//////////////////////////////////////////////////////

�Է¹��� �迭���� ��ĭ(0)�� �ϳ� ã�´�.
��ĭ�� ã�� �װ��� 1�� �ٲ۵� bfs�Լ��� ����.
bfs�Լ����� ���� �Է� ���� ���� queue�� �ְ� 4������ Ȯ���ϰ�
�ٽ� queue�� �ִ´�. �̶� �����ϴ� count�� �÷��ش�.
�� ã���� count�� return�Ѵ�.

bfs�� Ǯ�� ���Ͽ� queue�� ����ߴ�.
pair�� ó�� �Ẹ�� �Ǿ �ű��ؼ� �߰��غô�.
���������� ���Ͽ� sort�� �������� algorithm�� �߰��ߴ�
�迭��ü�� ũ�� ���� �ʰ� �޸𸮸� ���̱� ���� vector�� ����Ͽ� ������� �����ߴ�
���� vector�� �迭�� sort�� ������ �ִ�.


//////////////////////////////////////////////////////*/


using namespace std;

//m �� ���� //n�� ���� //n,m �̷��� �Ǿߴ�
int n, m;
int arr[100][100];

void input();
void search();
int bfs(int x, int y);

//bfs�� ����� queue
queue<pair<int, int>> myQueue;
//����� ������ vector
vector<int> myResult;

//0 �� 1�� 2�� 3��
int r_x[4] = { 0,1,0,-1 };
int r_y[4] = { 1,0,-1,0 };

int main()
{
	int i, j;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			arr[i][j] = 0;
		}
	}
	input();
	search();
	//�������� ����
	sort(myResult.begin(), myResult.end());
	cout << myResult.size() << endl;
	for (i = 0; i < myResult.size(); i++)
	{
		cout << myResult[i] << " ";
	}
}

void search()
{
	int i, j;
	int result;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				//��ĭ�� �ϳ� ã���� bfs�Լ� ���� �� return�� ����
				result = bfs(i, j);
				//��� �� �ϴ� vector�� �߰�
				myResult.push_back(result);
			}
		}
	}
}

int bfs(int x, int y)
{
	//�޾ƿ� x,y�� �ٲٱ�
	arr[x][y] = 1;
	pair<int, int> temp = make_pair(x, y);
	pair<int, int> temp2;
	myQueue.push(temp);
	//�޾ƿ� �� ���ʹϱ� count�� 1
	int count = 1;
	int i;
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();
		for (i = 0; i < 4; i++)
		{
			//4������ n,m�ȿ��� �����
			if (temp.first + r_x[i] >= 0 && temp.first + r_x[i] < n && temp.second + r_y[i] >= 0 && temp.second + r_y[i] < m)
			{
				//��ĭ����
				if (arr[temp.first + r_x[i]][temp.second + r_y[i]] == 0)
				{
					//��ĭ�� ���ּ� �ٸ� �ֵ��� ȥ�� ����
					arr[temp.first + r_x[i]][temp.second + r_y[i]] = 1;
					temp2 = make_pair(temp.first + r_x[i], temp.second + r_y[i]);
					myQueue.push(temp2);
					count++;
				}
			}
		}
	}
	return count;
}

void input()
{
	int i, j, l;
	int t_x1, t_x2, t_y1, t_y2;
	int k;
	cin >> m;
	cin >> n;
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> t_x1;
		cin >> t_y1;
		cin >> t_x2;
		cin >> t_y2;
		for (j = t_x1; j < t_x2; j++)
		{
			for (l = t_y1; l < t_y2; l++)
			{
				arr[j][l] = 1;
			}
		}
	}

}