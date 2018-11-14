#include<iostream>
#include<queue>

using namespace std;

int n;
int a[1000000];
int b, c;
long long result = 0;

void input();
void search();

int main()
{
	input();
	search();

	cout << result;
}


void search()
{
	int i;
	for (i = 0; i < n; i++)
	{
		a[i] -= b;
		result++;
		if (a[i] > 0)
		{
			if (a[i] % c == 0)
				result += (a[i] / c);
			else
				result += (a[i] / c) + 1;
		}
	}
}

void input()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> b;
	cin >> c;
}