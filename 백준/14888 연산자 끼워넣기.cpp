#include<iostream>

using namespace std;
int maximum = -1000000001;
int minimum = 1000000001;

int N;
int A[100];
int S[4];

int temp;

void input();
void dfs(int a, int b, int c, int d, int n, int total);

int main()
{
	input();
	dfs(0, 0, 0, 0, 1, A[0]);


	cout << maximum<< endl;
	cout << minimum;

}

void input()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (i = 0; i < 4; i++)
	{
		cin >> S[i];
	}
}

void dfs(int a, int b, int c, int d, int n, int total)
{
	if (n >= N)
	{
		if (maximum < total)
			maximum = total;
		if (minimum > total)
			minimum = total;

	}
	else
	{
		if (a < S[0])
		{
			dfs(a + 1, b, c, d, n + 1, total + A[n]);
		}
		if (b < S[1])
		{
			dfs(a, b + 1, c, d, n + 1, total - A[n]);
		}
		if (c < S[2])
		{
			dfs(a, b, c + 1, d, n + 1, total * A[n]);
		}
		if (d < S[3])
		{
			dfs(a, b, c, d + 1, n + 1, total / A[n]);
		}
	}


}