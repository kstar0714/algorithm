#include<iostream>

using namespace std;

int n;
int day[15];
int pay[15];

int max_pay = 0;
void input();
void dps(int dps_pay, int max_day);

int main()
{
	int i;
	input();
	for (i = 0; i < n; i++)
	{
		dps(0, i);
	}
	cout << max_pay;
}

void dps(int dps_pay, int max_day)
{
	int i;
	for (i = 0; i < n - max_day; i++)
	{
		if (max_day + i + day[max_day + i] <= n)
		{
			dps(dps_pay + pay[i + max_day], max_day + i + day[i + max_day]);
		}
	}
	if (max_pay < dps_pay)
		max_pay = dps_pay;


}

void input()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> day[i];
		cin >> pay[i];
	}

}