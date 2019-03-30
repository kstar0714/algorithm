#include<iostream>
#include<vector>

/*/////////////////////////////////////////////

���ĺ��� ���ִ� visit�� ����� dfs�� Ž����
�ϸ鼭 count�� ����. dfs���� �ϴ���
1. count�� result���� ũ�� ����
2. 4������ Ȯ��
3. 4���� �ȿ� �ִ� ���ĺ��� ó�� �ִ� ���ĺ�����
4. �׷��ٸ� dfs�� �ֵ� visit�� �ְ� dfs �ϰ� �ٽ�
end�� ����

/////////////////////////////////////////////*/



//[r][c]
int r, c;
char arr[20][20];

using namespace std;

void input();
vector<char> visit;
void dfs(int x, int y, int count);


int result = 0;
//[y][x] 0�� ��
int r_x[4] = { 1,0,-1,0 };
int r_y[4] = { 0,1,0,-1 };

int main()
{
	input();
	visit.push_back(arr[0][0]);
	dfs(0, 0, 1);
	cout << result;
}

void dfs(int x, int y, int count)
{
	int i, t_x, t_y, j;
	int o = 0;
	if (count > result)
		result = count;
	for (i = 0; i < 4; i++)
	{
		t_x = r_x[i] + x;
		t_y = r_y[i] + y;
		if (t_x >= 0 && t_x < c && t_y >= 0 && t_y < r)
		{
			for (j = 0; j < visit.size(); j++)
			{
				if (arr[t_y][t_x] == visit[j])
				{
					o = 1;
					break;
				}
			}
			if (o == 1)
			{
				o = 0;
				continue;
			}
			visit.push_back(arr[t_y][t_x]);
			dfs(t_x, t_y, count + 1);
			visit.erase(visit.end() - 1);
		}
	}

}

void input()
{
	int i, j;

	cin >> r;
	cin >> c;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}
}