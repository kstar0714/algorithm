#include<iostream>

/*/////////////////////////////////////////////////////////
dfs�� Ǯ��
�Է��� �ް� dfs�� 6���� �迭��  count(�迭�� ��� ä��������
), last(������������ �޾ƾ� �ϴ� ������ ������ �迭�� ä���)
�� 3���� ���ڸ� ���ؼ� �Ѵ�.



/////////////////////////////////////////////////////////*/


using namespace std;

int k;
int s[13];

void input();
void start();
void dfs(int count, int a[], int last);

int main()
{
	//���ɸ� �޴µ� 0 �Է��̸� ����
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		input();
		start();
		cout << endl;
	}
}

void start()
{
	//�迭 �ϳ��� �����ϰ� �ֱ�//
	int a[6];
	dfs(0, a, 0);
}

void dfs(int count, int a[], int last)
{
	//�迭�� �� ���� ���//
	if (count == 6)
	{
		int temp;
		for (temp = 0; temp < 6; temp++)
		{
			cout << a[temp] << " ";
		}
		cout << endl;
	}
	//�ƴ϶�� ä���
	else {
		int i;
		//������ �������� �ִ� k������ ������ dfs�� �����鼭 ���
		for (i = last; i < k; i++)
		{
			a[count] = s[i];
			dfs(count + 1, a, i + 1);
		}

	}
}

void input()
{
	int i;
	for (i = 0; i < k; i++)
	{
		cin >> s[i];
	}

}