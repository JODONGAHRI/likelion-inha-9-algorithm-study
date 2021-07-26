#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
	vector<int> fibo = { 1,2 };

	if (n == 1 || n == 2) return n;
	for (int i = 2; i < n; i++) {
		fibo.push_back((fibo[i - 2] + fibo[i - 1]) % 1000000007);
	}
	return fibo[n - 1];
	// "����" ������� �����ϰ� Ǯ�鼭 �ð��ʰ� �ذ��غ����� �� �ð��� �����ߴµ�
	// �� ���� �׳� �Ǻ���ġ ���� ��������...
	// ��¥... �� �Ǻ���ġ������ �𸣰ڴ�. �밡���ϴٰ� �󶳰ῡ �˰Եǹ��ȴ�...
	// �� �Ǻ���ġ���� �ƽô� �� �ǵ�� ��Ź�帳�ϴ� ��
}