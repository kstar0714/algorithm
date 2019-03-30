#include<iostream>
using namespace std;


/*
�Ǻ���ġ �Լ��� bottom_up ������� Ǭ��.
0�� 0�� 1�� 1�� 0��,
1�� 0�� 0�� 1�� 1��,
2�� 0�� 1�� ���� ��,
3�� 1�� 2�� ���� ��.....
�̷������� �Ʒ��� ���� ���ؼ� �ö󰣴�.

*/



class myClass {
public:
	int zero = 0;
	int one = 0;
};

myClass arr[41];

int n;
int testCaseCount;


int main()
{
	cin >> testCaseCount;
	int j;
	for (j = 0; j < testCaseCount; j++)
	{
		cin >> n;
		arr[0].zero = 1;
		arr[1].one = 1;

		int i;
		for (i = 2; i <= n; i++)
		{
			arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
			arr[i].one = arr[i - 1].one + arr[i - 2].one;
		}

		cout << arr[n].zero << " " << arr[n].one << endl;
	}
}

