#include<iostream>

/*/////////////////////////////////////////////////////////
dfs로 풀기
입력을 받고 dfs는 6개의 배열과  count(배열에 몇개가 채워졌는지
), last(오르차순으로 받아야 하니 마지막 이후의 배열로 채우기)
총 3개의 인자를 통해서 한다.



/////////////////////////////////////////////////////////*/


using namespace std;

int k;
int s[13];

void input();
void start();
void dfs(int count, int a[], int last);

int main()
{
	//테케를 받는데 0 입력이면 종료
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		input();
		start();
		cout << endl;
	}
}

void start()
{
	//배열 하나를 설정하고 넣기//
	int a[6];
	dfs(0, a, 0);
}

void dfs(int count, int a[], int last)
{
	//배열이 다 차면 출력//
	if (count == 6)
	{
		int temp;
		for (temp = 0; temp < 6; temp++)
		{
			cout << a[temp] << " ";
		}
		cout << endl;
	}
	//아니라면 채우기
	else {
		int i;
		//마지막 기점으로 최대 k개까지 있으니 dfs로 넣으면서 출력
		for (i = last; i < k; i++)
		{
			a[count] = s[i];
			dfs(count + 1, a, i + 1);
		}

	}
}

void input()
{
	int i;
	for (i = 0; i < k; i++)
	{
		cin >> s[i];
	}

}