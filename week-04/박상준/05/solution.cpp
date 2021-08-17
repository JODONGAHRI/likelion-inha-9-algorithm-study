#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<char>> candies;
	int n, max = 1;
	char input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < n; j++) {
			cin >> input;
			temp.push_back(input);
		}
		candies.push_back(temp);
	}

	// ���ο� ���� Ȯ��
	for (int i = 0; i < n; i++) {
		char current = candies[i][0];
		int cnt = 1, change = 0;
		// if (max == n) break;

		for (int j = 1; j < n; j++) {
			if (current == candies[i][j]) cnt++; // ���� ���� ���ӵǴ� ���
			else {
				if (change == 0 && ((i > 0 && current == candies[i - 1][j]) || (i < n - 1 && current == candies[i + 1][j]) || (j < n - 1 && current == candies[i][j + 1]))) {
					// �ٲܼ� �ִ� ���
					cnt++;
					change = 1;
					if ((i==0||(i > 0 && current != candies[i - 1][j])) && (i==n-1||(i < n - 1 && current != candies[i + 1][j])) && (j < n - 1 && current == candies[i][j + 1])) {
						// ���� �����̶� �ٲ� ��� -> �װ� ��������
						if (max < cnt) max = cnt;
						current = candies[i][j];
						change = 0;
						cnt = 1;
						if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							// ���ŵ� current�� �տ��� �ٲ�� �� �ִ� ���
							change = 1;
							cnt++;
						}
					}
					else {
						// �ٲ� ��� �󸶳� ������ Ȯ��
						while (j + change < n && current == candies[i][j + change]) {
							cnt++;
							change++;
						}
						if (max < cnt) max = cnt;
						cnt = 1;
						change = 0;
						current = candies[i][j];
						if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							// ���ŵ� current�� �տ��� �ٲ�� �� �ִ� ���
							change = 1;
							cnt++;
							if ((i > 0 && current == candies[i - 1][j - 1]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
								// ���� �Ʒ����� ������ ���
								int checkFront = j - 2;
								while (checkFront >= 0 && candies[i][checkFront--] == current) {
									cnt++;
								}
							}
						}
					}
				}
				else {
					// ���ٲٴ� ���.
					current = candies[i][j];
					change = 0;
					cnt = 1;
					if ((i > 0 && current == candies[i - 1][j - 1]) || (j > 1 && current == candies[i][j - 2]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
						// ���ŵ� current�� �տ��� �ٲ�� �� �ִ� ���
						change = 1;
						cnt++;
						if ((i > 0 && current == candies[i - 1][j - 1]) || (i < n - 1 && current == candies[i + 1][j - 1])) {
							int checkFront = j - 2;
							while (checkFront >= 0 && candies[i][checkFront--] == current) {
								cnt++;
							}
						}
					}
				}
			}
			if (max < cnt) max = cnt;
		}
	}

	if (max == n) {
		// ���ο��� �ִ밪 �������� �� Ȯ���� �ʿ� ����.
		cout << max;
		return 0;
	}

	// ���ο� ���� Ȯ��
	for (int i = 0; i < n; i++) {
		char current = candies[0][i];
		int cnt = 1, change = 0;
		if (max == n) break;

		for (int j = 1; j < n; j++) {
			if (current == candies[j][i]) cnt++; // ���� ���� ���ӵǴ� ���
			else {
				if (change == 0 && ((i > 0 && current == candies[j][i - 1]) || (i < n - 1 && current == candies[j][i + 1]) || (j < n - 1 && current == candies[j + 1][i]))) {
					// �ٲܼ� �ִ� ���
					cnt++;
					change = 1;
					if ((i==0||(i > 0 && current != candies[j][i - 1])) && (i==n-1||(i < n - 1 && current != candies[j][i + 1])) && (j < n - 1 && current == candies[j + 1][i])) {
						// ���� �����̶� �ٲ� ��� -> �װ� ��������
						if (max < cnt) max = cnt;
						current = candies[j][i];
						change = 0;
						cnt = 1;
					}
					else {
						// �ٲ� ��� �󸶳� ������ Ȯ��
						while (j + change < n && current == candies[j + change][i]) {
							cnt++;
							change++;
						}
						if (max < cnt) max = cnt;
						cnt = 1;
						change = 0;
						current = candies[j][i];
						if ((i > 0 && current == candies[j - 1][i - 1]) || (j > 1 && current == candies[j - 2][i]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
							// ���ŵ� current�� �տ��� �ٲ�� �� �ִ� ���
							change = 1;
							cnt++;
							if ((i > 0 && current == candies[j - 1][i - 1]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
								// �����̳� �����ʿ��� ������ ���
								int checkFront = j - 2;
								while (checkFront >= 0 && candies[checkFront--][i] == current) {
									cnt++;
								}
							}
						}
					}
				}
				else {
					// ���ٲٴ� ���.
					current = candies[j][i];
					change = 0;
					cnt = 1;
					if ((i > 0 && current == candies[j - 1][i - 1]) || (j > 1 && current == candies[j - 2][i]) || (i < n - 1 && current == candies[j - 1][i + 1])) {
						// ���ŵ� current�� �տ��� �ٲ�� �� �ִ� ���
						change = 1;
						cnt++;
					}
				}
			}
			if (max < cnt) max = cnt;
		}
	}
	cout << max;
}