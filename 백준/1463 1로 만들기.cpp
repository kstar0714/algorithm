#include<iostream>
#include<algorithm>
using namespace std;

/*
bottom up 방법을 이용해서 푼다.
3가지 방법을 비교한다.
그중 가장 개수가 많이 나오는 1을 뺀다 부터 시작한다.
그다음 2로 나누는 방법,
그 후에 3으로 나누는 방법을 이용한다.

2는 -1 방법이 있다. 방법 1가지
3은 -1 방법을 이용해 2의 방법과 더한다. 2가지,
그런데 밑에 if문 중 3으로 나누어 떨어지는 방법으로 한번에 갈 수 있다. 그래서 비교한뒤 1가지로 바뀐다.

4는 -1방법을 통해 3에서 1가지와 더해 정답이 2가 된다.
그 뒤에 2로 나누는 방법으로 2에 도달하고 2에 있던 1가지와 더해서 2가 되는데 전과 값이 같으니 패스...


이런식으로 구한다.

*/



int n;
int result[1000001];

int main()
{
	cin >> n;
	int i;
	result[1] = 0;
	for (i = 2; i <= n; i++)
	{
		result[i] = result[i - 1] + 1;
		if (i % 2 == 0)
		{
			result[i] = min(result[i], result[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			result[i] = min(result[i], result[i / 3] + 1);
		}
	}
	cout << result[n];
}

