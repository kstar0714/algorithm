#include<iostream>
using namespace std;


/*
피보나치 함수를 bottom_up 방법으로 푼다.
0은 0이 1개 1이 0개,
1은 0이 0개 1이 1개,
2는 0과 1을 더한 값,
3은 1과 2를 더한 값.....
이런식으로 아래서 부터 더해서 올라간다.

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

