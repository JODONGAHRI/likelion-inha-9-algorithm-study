#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int arr[8002] = { 0, };
	int n, mid, input, hight = 0, alway;
	double avg = 0;

	cin >> n;        //n: ������ �Է� Ƚ��

	for (int i = 0; i < n; i++)
	{
		cin >> input;            //input: ������ �Է°�
		arr[4000 + input]++;     //ī���� ���� ����

		avg += input;            //avg: ��հ�

		if (hight < arr[4000 + input])        //�Է� �� �ִ� �� Ȯ��
		{
			hight = arr[4000 + input];        //hight: ���� �ִ�
			alway = input;                    //alway: �ִ��� �󵵸� �����ϴ� ��
		}
	}
	int min, max;                 //max: �ִ�, min: �ּڰ�
	min = max = input;

	bool flag = false;            //mid���� �ʱ�ȭ�� �ߴ��� Ȯ�� �뵵
	int cnt = 0;                  //�ִ��� �󵵸� ���� ���� ���� Ȯ�� �뵵
	int sum = 0;                  //�Էµ� Ƚ�� Ȯ�� �뵵

	for (int i = 0; i < 8002; i++)
	{
		int value = i - 4000;
		if (arr[i] > 0)
		{
			sum += arr[i];
			if (sum >= n / 2 + 1 && !flag)
			{
				mid = value;
				flag = true;
			}
			if (min > value) min = value;
			if (max < value) max = value;

			if (arr[i] == hight) cnt++;
			if (cnt == 2)        //�� ��°�� ���� ����
			{
				cnt = 3;
				alway = value;
			}
		}
	}

	cout << round(avg / n) << "\n" << mid << "\n" << alway << "\n" << max - min;
	return 0;
}