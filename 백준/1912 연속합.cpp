#include<iostream>

using namespace std;

/*
�������� ���� ���ؾ� �Ǳ� ������ 0��° ���� �������Ѵ�.
���ʴ�� ���ϴ� �Ͱ� ó������ �ٽ� �����ϴ� �� �� ���� ���ؼ�
�� ū������ ������ �ϸ� �ȴ�.
�׷��� ������ ���±��� ���� �Ǵ� ���鳢�� �񱳸� �Ѵ�.

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