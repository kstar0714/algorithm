#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<vector>

/*//////////////////////////////////////////////////////

입력받은 배열에서 빈칸(0)을 하나 찾는다.
빈칸을 찾고 그곳을 1로 바꾼뒤 bfs함수로 들어간다.
bfs함수에선 먼저 입력 받은 것을 queue에 넣고 4방향을 확인하고
다시 queue에 넣는다. 이때 공유하는 count를 올려준다.
다 찾고나면 count를 return한다.

bfs로 풀기 위하여 queue를 사용했다.
pair를 처음 써보게 되어서 신기해서 추가해봤다.
오름차순을 위하여 sort를 쓰기위해 algorithm을 추가했다
배열자체를 크게 주지 않고 메모리를 줄이기 위해 vector를 사용하여 결과값을 저장했다
또한 vector와 배열만 sort에 넣을수 있다.


//////////////////////////////////////////////////////*/


using namespace std;

//m 은 세로 //n은 가로 //n,m 이렇게 되야댐
int n, m;
int arr[100][100];

void input();
void search();
int bfs(int x, int y);

//bfs때 사용할 queue
queue<pair<int, int>> myQueue;
//결과를 저장할 vector
vector<int> myResult;

//0 동 1남 2서 3북
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
	//오름차순 정렬
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
				//빈칸을 하나 찾으면 bfs함수 실행 및 return값 저장
				result = bfs(i, j);
				//결과 값 일단 vector에 추가
				myResult.push_back(result);
			}
		}
	}
}

int bfs(int x, int y)
{
	//받아온 x,y값 바꾸기
	arr[x][y] = 1;
	pair<int, int> temp = make_pair(x, y);
	pair<int, int> temp2;
	myQueue.push(temp);
	//받아온 것 부터니까 count는 1
	int count = 1;
	int i;
	while (!myQueue.empty())
	{
		temp = myQueue.front();
		myQueue.pop();
		for (i = 0; i < 4; i++)
		{
			//4방향이 n,m안에서 노는지
			if (temp.first + r_x[i] >= 0 && temp.first + r_x[i] < n && temp.second + r_y[i] >= 0 && temp.second + r_y[i] < m)
			{
				//빈칸인지
				if (arr[temp.first + r_x[i]][temp.second + r_y[i]] == 0)
				{
					//빈칸을 없애서 다른 애들이 혼돈 없게
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