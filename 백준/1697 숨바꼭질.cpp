#include<iostream>
#include<queue>

using namespace std;

class myClass {
public:
	int result;
	int time;
};

int n;
int k;
int result;
int visit[100001];
queue<myClass> myqueue;

void input();
void search();

int main()
{
	int i;
	for (i = 0; i < 100001; i++)
	{
		visit[i] = 0;
	}

	input();
	search();

	cout << result;
}

void search()
{
	while (1)
	{
		myClass temp, temp1;
		temp = myqueue.front();
		myqueue.pop();

		if (temp.result == k)
		{
			result = temp.time;
			break;
		}

		//3가지 모두 다 큐에 넣되 조건을 만들기
		//이미 방문한 적이 있거나 수 제한을 넘을경우 큐에 안집어넣기
		if (temp.result * 2 <= 100000 && visit[temp.result * 2] == 0)
		{
			visit[temp.result * 2] = 1;
			temp1.result = temp.result * 2;
			temp1.time = temp.time + 1;
			myqueue.push(temp1);
		}
		if (temp.result + 1 <= 100000 && visit[temp.result + 1] == 0)
		{
			visit[temp.result + 1] = 1;
			temp1.result = temp.result + 1;
			temp1.time = temp.time + 1;
			myqueue.push(temp1);
		}
		if (temp.result - 1 >= 0 && visit[temp.result - 1] == 0)
		{
			visit[temp.result - 1] = 1;
			temp1.result = temp.result - 1;
			temp1.time = temp.time + 1;
			myqueue.push(temp1);
		}


	}
}

void input()
{
	myClass temp;

	cin >> n;
	cin >> k;

	visit[n] = 1;
	temp.result = n;
	temp.time = 0;
	myqueue.push(temp);
}