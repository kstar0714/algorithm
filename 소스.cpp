#include <iostream>
#include <vector>

using namespace std;

bool arr1[100][100];
int arr[100][100];
int a, b;

class MyClass
{
public:
	int Ci, Cj;
	int dept;
};

int main()
{
	int x[4] = { 0, 0, -1, 1 };
	int y[4] = { 1,-1,0,0 };
	vector<MyClass> myVector;
	MyClass temp;
	temp.Ci = 0;
	temp.Cj = 0;
	temp.dept = 1;
	myVector.push_back(temp);
	int c;
	int i, j;

	cin >> a;
	cin >> b;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			scanf("%1d", &c);
			if (c == 1)
				arr1[i][j] = true;
		}
	}
	while (1)
	{
		for (i = 0; i < 4; i++)
		{
			temp.Ci = myVector[0].Ci;
			temp.Cj = myVector[0].Cj;
			temp.dept = myVector[0].dept;

			temp.Ci += x[i];
			temp.Cj += y[i];
			if (temp.Ci < a && temp.Cj < b && temp.Ci >= 0 && temp.Cj >= 0)
			{
				if (arr1[temp.Ci][temp.Cj] == true)
				{
					if (arr[temp.Ci][temp.Cj] == 0)
					{
						arr[temp.Ci][temp.Cj] = temp.dept;
						temp.dept += 1;
						myVector.push_back(temp);
					}
				}

			}
		}
		if (myVector[0].Ci + 1 == a && myVector[0].Cj + 1 == b)
		{
			break;
		}
		arr1[myVector[0].Ci][myVector[0].Cj] = false;
		myVector.erase(myVector.begin());
	}
	cout << myVector[0].dept << endl;

}