
#include<iostream>

using namespace std;

int testcase;
int temp;

/*
�ֺ���� ���ϴ� ����� ����.
���ʿ� �Է��� ������ ī��Ʈ�� ���� �Է¹��� �迭ĭ�� ++�� ���ش�.
�Է��� ������ for���� ���ؼ� ���� ���� Ŭ�� �� �迭�� ��� ��¸� �ϸ� �ȴ�.


*/


int maximum_i;
int maximum;

void input();
void start();
void count_erase();

int count_arr[1000];

int main()
{
	scanf("%d", &testcase);
	int i;
	for (i = 1; i < testcase + 1; i++)
	{
		maximum = 0;
		maximum_i = 0;
		count_erase();
		input();
		start();
		printf("#%d %d\n", i, maximum_i + 1);
	}

}

void start()
{
	int i;
	for (i = 0; i < 1000; i++)
	{
		if (count_arr[i] >= maximum)
		{
			if (i > maximum_i)
			{
				maximum_i = i;
				maximum = count_arr[i];
			}
		}
	}
}

void count_erase()
{
	int i;
	for (i = 0; i < 1000; i++)
	{
		count_arr[i] = 0;
	}
}

void input()
{
	scanf("%d", &temp);
	int i;
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &temp);
		count_arr[temp - 1] ++;
	}
}