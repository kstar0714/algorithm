#include<stdio.h>

/*
8칸의 배열을 4개로 만들어서 톱니바퀴를 만든다.
rotate함수를 만들어서 시계방향으로 돌 때의 배열 8칸의 이동을 표현
rev_rotate함수를 통해서 반시계 또한 만든다.

near search에선 회전을 한 시작점과 움직이려는 톱니바퀴, 방향을 인자로 받는다.
움직이려는 톱니바퀴는 인접한 톱니바퀴와의 정보를 체크해서 인접한 톱니바퀴가 도는지를
확인한다. 그 후 , 움직일 수 있는 상황이면 재귀를 통해서 nearsearch함수를 돌린다.
이때 시작점 인자는 바꿔서 넣는다. 이유는 1번때문에 2번이 이동했는데 2번이 1번을 또 
확인할 필요가 없기 때문이다.

*/



using namespace std;

class MyClass
{
public:
	int rotate_count;
	int rotate_arrow;
};



//돌리는 횟수
int k;
MyClass k_info[100];

//톱니바퀴 정보
int topni1[8];
int topni2[8];
int topni3[8];
int topni4[8];


void input();
void start();

int result = 0;

void rotate_func(int topni);
void rev_rotate_func(int topni);
void near_search(int i, int rotate_Arrow, int start_topni);

int main()
{
	input();
	start();
	if (topni1[0] == 1)
		result += 1;
	if (topni2[0] == 1)
		result += 2;
	if (topni3[0] == 1)
		result += 4;
	if (topni4[0] == 1)
		result += 8;

	printf("%d", result);
}

void start()
{
	int i;
	for (i = 0; i < k; i++)
	{
		near_search(k_info[i].rotate_count, k_info[i].rotate_arrow, k_info[i].rotate_count);
	}
}


void near_search(int i, int rotate_Arrow, int start_topni)
{

	int temp_kk;
	for (temp_kk = 0; temp_kk < 8; temp_kk++)
	{
		printf("%d, ", topni1[temp_kk]);
	}
	printf("\n");
	for (temp_kk = 0; temp_kk < 8; temp_kk++)
	{
		printf("%d, ", topni2[temp_kk]);
	}
	printf("\n");
	for (temp_kk = 0; temp_kk < 8; temp_kk++)
	{
		printf("%d, ", topni3[temp_kk]);
	}
	printf("\n");
	for (temp_kk = 0; temp_kk < 8; temp_kk++)
	{
		printf("%d, ", topni4[temp_kk]);
	}
	printf("\n");
	printf("\n");
	printf("\n");


	if (i == 1)
	{
		if (start_topni == 2)
		{
			if (rotate_Arrow == 1)
			{
				rotate_func(1);
			}
			else
			{
				rev_rotate_func(1);
			}
		}
		else
		{
			if (topni1[2] != topni2[6])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(1);
					near_search(2, -1, start_topni);
				}
				else
				{
					rev_rotate_func(1);
					near_search(2, 1, start_topni);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(1);
				}
				else
				{
					rev_rotate_func(1);
				}
			}
		}
	}
	else if (i == 2)
	{
		if (start_topni == 1)
		{
			if (topni2[2] != topni3[6])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
					near_search(3, -1, 2);
				}
				else
				{
					rev_rotate_func(2);
					near_search(3, 1, 2);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
				}
				else
				{
					rev_rotate_func(2);
				}
			}
		}
		else if (start_topni == 3)
		{
			if (topni2[6] != topni1[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
					near_search(1, -1, 2);
				}
				else
				{
					rev_rotate_func(2);
					near_search(1, 1, 2);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
				}
				else
				{
					rev_rotate_func(2);
				}
			}
		}
		else
		{
			if (topni2[2] != topni3[6] && topni2[6] != topni1[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
					near_search(3, -1, start_topni);
					near_search(1, -1, start_topni);
				}
				else
				{
					rev_rotate_func(2);
					near_search(3, 1, start_topni);
					near_search(1, 1, start_topni);
				}
			}
			else if (topni2[2] != topni3[6])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
					near_search(3, -1, start_topni);
				}
				else
				{
					rev_rotate_func(2);
					near_search(3, 1, start_topni);
				}
			}
			else if (topni2[6] != topni1[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
					near_search(1, -1, start_topni);
				}
				else
				{
					rev_rotate_func(2);
					near_search(1, 1, start_topni);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(2);
				}
				else
				{
					rev_rotate_func(2);
				}
			}
		}

	}
	else if (i == 3)
	{
		if (start_topni == 2)
		{
			if (topni3[2] != topni4[6])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
					near_search(4, -1, 3);
				}
				else
				{
					rev_rotate_func(3);
					near_search(4, 1, 3);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
				}
				else
				{
					rev_rotate_func(3);
				}
			}
		}
		else if (start_topni == 4)
		{
			if (topni3[6] != topni2[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
					near_search(2, -1, 3);
				}
				else
				{
					rev_rotate_func(3);
					near_search(2, 1, 3);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
				}
				else
				{
					rev_rotate_func(3);
				}
			}
		}
		else
		{
			if (topni3[2] != topni4[6] && topni3[6] != topni2[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
					near_search(4, -1, start_topni);
					near_search(2, -1, start_topni);
				}
				else
				{
					rev_rotate_func(3);
					near_search(4, 1, start_topni);
					near_search(2, 1, start_topni);
				}
			}
			else if (topni3[2] != topni4[6])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
					near_search(4, -1, start_topni);
				}
				else
				{
					rev_rotate_func(3);
					near_search(4, 1, start_topni);
				}
			}
			else if (topni3[6] != topni2[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
					near_search(2, -1, start_topni);
				}
				else
				{
					rev_rotate_func(3);
					near_search(2, 1, start_topni);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(3);
				}
				else
				{
					rev_rotate_func(3);
				}
			}
		}
	}
	else if (i == 4)
	{
		if (start_topni == 3)
		{
			if (rotate_Arrow == 1)
			{
				rotate_func(4);
			}
			else
			{
				rev_rotate_func(4);
			}
		}
		else
		{
			if (topni4[6] != topni3[2])
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(4);
					near_search(3, -1, start_topni);
				}
				else
				{
					rev_rotate_func(4);
					near_search(3, 1, start_topni);
				}
			}
			else
			{
				if (rotate_Arrow == 1)
				{
					rotate_func(4);
				}
				else
				{
					rev_rotate_func(4);
				}
			}
		}
	}
}

void rotate_func(int topni)
{
	int temp, i;
	if (topni == 1)
	{
		temp = topni1[7];
		for (i = 7; i > 0; i--)
		{
			topni1[i] = topni1[i - 1];
		}
		topni1[0] = temp;
	}
	else if (topni == 2)
	{
		temp = topni2[7];
		for (i = 7; i > 0; i--)
		{
			topni2[i] = topni2[i - 1];
		}
		topni2[0] = temp;
	}
	else if (topni == 3)
	{
		temp = topni3[7];
		for (i = 7; i > 0; i--)
		{
			topni3[i] = topni3[i - 1];
		}
		topni3[0] = temp;
	}
	else if (topni == 4)
	{
		temp = topni4[7];
		for (i = 7; i > 0; i--)
		{
			topni4[i] = topni4[i - 1];
		}
		topni4[0] = temp;
	}

}

void rev_rotate_func(int topni)
{
	int temp, i;
	if (topni == 1)
	{
		temp = topni1[0];
		for (i = 0; i < 7; i++)
		{
			topni1[i] = topni1[i + 1];
		}
		topni1[7] = temp;
	}
	else if (topni == 2)
	{
		temp = topni2[0];
		for (i = 0; i < 7; i++)
		{
			topni2[i] = topni2[i + 1];
		}
		topni2[7] = temp;
	}
	else if (topni == 3)
	{
		temp = topni3[0];
		for (i = 0; i < 7; i++)
		{
			topni3[i] = topni3[i + 1];
		}
		topni3[7] = temp;
	}
	else if (topni == 4)
	{
		temp = topni4[0];
		for (i = 0; i < 7; i++)
		{
			topni4[i] = topni4[i + 1];
		}
		topni4[7] = temp;
	}

}


void input()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		scanf("%1d", &topni1[i]);
	}
	for (i = 0; i < 8; i++)
	{
		scanf("%1d", &topni2[i]);
	}
	for (i = 0; i < 8; i++)
	{
		scanf("%1d", &topni3[i]);
	}
	for (i = 0; i < 8; i++)
	{
		scanf("%1d", &topni4[i]);
	}
	scanf("%d", &k);
	for (j = 0; j < k; j++)
	{
		int temp_i, temp_j;
		scanf("%d", &temp_i);
		scanf("%d", &temp_j);
		k_info[j].rotate_count = temp_i;
		k_info[j].rotate_arrow = temp_j;
	}
}