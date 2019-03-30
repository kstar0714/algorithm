#include "pch.h"
#include<iostream>

using namespace std;

/*
�� ������ �������� ���� �ΰ��� �迭���� ����.
�� ���� �� 4���� ���� �������� ũ�ٸ� �������� ����Ѵ�.
4���� ���� ū �� max�� ��Ƴ��� ���� ������ max�� �� ����
���� max�� �ִ´�

*/


int n;
int building_arr[1004];

int max_count;

void input();
void erase();
void start();

int main()
{
	int i;
	for (i = 1; i < 11; i++)
	{
		max_count = 0;
		erase();
		input();
		start();
		printf("#%d %d\n", i, max_count);
	}

}

void start()
{
	int i;
	for (i = 2; i < n + 2; i++)
	{
		if (building_arr[i] > building_arr[i - 2] && building_arr[i] > building_arr[i - 1] && building_arr[i] > building_arr[i + 1] && building_arr[i] > building_arr[i + 2])
		{
			int there_max = 0;
			if (there_max < building_arr[i - 2])
			{
				there_max = building_arr[i - 2];
			}
			if (there_max < building_arr[i - 1])
			{
				there_max = building_arr[i - 1];
			}
			if (there_max < building_arr[i + 1])
			{
				there_max = building_arr[i + 1];
			}
			if (there_max < building_arr[i + 2])
			{
				there_max = building_arr[i + 2];
			}
			max_count += building_arr[i] - there_max;
		}
	}
}


void erase()
{
	int i;
	for (i = 0; i < 1004; i++)
	{
		building_arr[i] = 0;
	}
}

void input()
{
	scanf("%d", &n);
	int i;
	for (i = 2; i < n + 2; i++)
	{
		scanf("%d", &building_arr[i]);
	}
}