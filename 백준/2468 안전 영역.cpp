#include<iostream>
#include<queue>
#include<utility>

/*//////////////////////////////////////////////////

n개의 배열을 입력을 받는다
입력을 받을 때 max_height를 설정한다.
가장 높은 지대가 어디까지인지를 설정한 후에 굳이 높이
최대치인 100까지 안돌도록 한다.

비의 높이를 0(비가 안옴)부터
max_height(최대 지대높이)까지 for문을 돌리면서 가장
안전지대 개수가 많은 것을 저장한다.

먼저 recovery함수를 이용하여 check 배열을 초기화 시켜주고
그 후 현재 for문에서의 i값이랑 비교하여 물에 잠기는 곳은
false를 해준다. 다 해준 뒤에 true가 붙어 있는곳을 다시 찾고
찾으면 bfs함수를 실행시켜서 인접한 곳을 모두 false 시킨다
이 작업이 한번 끝나면 temp_safty_zone을 ++ 시켜준다.

한번의 for문이 돌고나서 safty_zone에 크기 비교하여 넣어준다

//////////////////////////////////////////////////*/


using namespace std;

int n;
int max_height = 0;
//[][]가로세로
int arr[100][100];
bool check[100][100];

//안전지대 최대 구역
int safty_zone = 0;
//물 높이 때마다 temp에 저장한뒤 safty_zone이랑 비교용
int temp_safty_zone = 0;

void input();
void recovery();
void search();
void bfs(int x, int y);

//queue엔 x,y값을 저장
queue<pair<int, int>> myQueue;

//0 동 1남 2서 3북
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
	//비가 내리는 것을 0부터 모두 잠기는 곳까지
	for (i = 0; i < max_height; i++)
	{
		//배열을 확인해서 비에 잠기는 구역은 check함수에 false로 만들기
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

		//비에 잠기지 않은 곳을 찾으면 bfs로 인접지역 모두 false로 만들고 ++해주기
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
		//크기 비교
		if (safty_zone < temp_safty_zone)
			safty_zone = temp_safty_zone;

		//다시 초기화 하는 것
		recovery();
		temp_safty_zone = 0;
	}
}

void bfs(int x, int y)
{
	int i;
	pair<int, int> temp = make_pair(x, y);
	pair<int, int> temp2;
	//queue에 하나 넣기
	myQueue.push(temp);
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();

		//상하좌우 인접구역 확인하기
		for (i = 0; i < 4; i++)
		{
			//n배열안에서 노는지
			if (temp.first + r_x[i] >= 0 && temp.first + r_x[i] < n && temp.second + r_y[i] >= 0 && temp.second + r_y[i] < n)
			{
				//안전구역 맞는지
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

//check함수 true로 모두 만들어주는 함수
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

