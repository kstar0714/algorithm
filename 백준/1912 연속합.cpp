#include<iostream>

using namespace std;

/*
연속적인 합을 구해야 되기 때문에 0번째 부터 시작을한다.
차례대로 더하는 것과 처음부터 다시 시작하는 것 두 개를 비교해서
더 큰값으로 시작을 하면 된다.
그러고 최종값 여태까지 제일 컸던 값들끼리 비교를 한다.

*/



int n;
int arr[100001];
int result[100001];

int f_result;

int main()
{
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	result[0] = arr[0];
	f_result = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > arr[i] + result[i - 1])
		{
			result[i] = arr[i];
		}
		else
		{
			result[i] = arr[i] + result[i - 1];
		}
		if (f_result < result[i])
			f_result = result[i];
	}

	cout << f_result;
}