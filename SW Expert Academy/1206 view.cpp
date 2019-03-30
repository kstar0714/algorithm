#include "pch.h"
#include<iostream>

using namespace std;

/*
한 빌딩을 기준으로 양쪽 두개의 배열들을 본다.
그 다음 총 4개의 양쪽 빌딩보다 크다면 조망권을 계산한다.
4개중 가장 큰 걸 max로 잡아놓고 기준 빌딩과 max를 뺀 값을
최종 max에 넣는다

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