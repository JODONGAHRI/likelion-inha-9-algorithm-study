#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 1) {
		// �Էµ� ���� 1�� ��� �ٷ� ��.
		cout << 0;
		return 0;
	}

	vector<vector<int>> dp = { {N} };
	// dp�� n��° �ε����� �ش��ϴ� ���ʹ� n���� ������ ���� ���� �� �ִ� ���ڵ�.
	int flag = 0, cnt = 0; // 1�� ����������� �Ǻ��ϱ� ���� flag�� ���� Ƚ�� cnt
	while (true) {
		vector<int> temp;
		int size = dp[0].size();
		for (int j = 0; j < size; j++) {
			int current = dp[0][j];
			if (current == 2 || current == 3) {
				flag = 1;
				break;
				// 2�ų� 3�ΰ�� 1�� ��������� ������ ����.
			}

			if (current % 3 == 0) temp.push_back(current / 3);
			if (current % 2 == 0) temp.push_back(current / 2);
			if (N > 1) temp.push_back(current - 1);
			// ������ ���� ��������� ���ڵ��� temp�� ����.
		}
		if (flag == 1) break;

		// 1�� �ȸ�������� flag�� 0�̸�,
		cnt++;  // Ƚ�� ����
		dp.push_back(temp); // �������� ������� ���� dp�� �ֱ�.
		dp.erase(dp.begin()); // ���� dp�� �ʿ� ������ �����.
	}
	cout << cnt + 1;
	// current�� 2�� 3�� �� ��쿡 �����Ͽ� �̵��� 1�� ����� ������ ���� �ʾұ� ������ + 1
}