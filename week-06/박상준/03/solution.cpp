#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> dp = { 1,2,4 };
	int i = 2;
	while (i < 9) {
		// �־����� ���� 11���� �۱� ������ 10������ ���� �����Ѵ�.
		// 4��° �� ���ʹ� (1 + i-1�� ǥ���ϴ� ���)�� �ش��ϴ� ���� + (2 + i-2�� ǥ���ϴ� ���) + (3 + i-3�� ǥ���ϴ� ���) ....
		// ���� ��Ģ�� �����Ͽ� �Ʒ��� ���� ��ȭ���� �����Ѵ�. (���� 1, 2, 3�� ������ �� ����� �� �տ� ��ġ�Ѵ�.) 
		dp.push_back(dp[i - 2] + dp[i - 1] + dp[i]);
		i++;
	}

	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n - 1] << "\n";
	}
}