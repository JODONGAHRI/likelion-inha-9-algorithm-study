#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<vector<int>> paper;
	int answer[3] = { 0,0,0 }, N, input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		paper.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}

	int use = 0, current = N, cut = 0;
	while (current >= 3) {
		// current : ���� �� ���� ����. 3x3���� �߸������� �ݺ�
		int startx = 0, starty = 0;
		for (int i = 0; i < pow(3, cut * 2); i++) {
			int first = paper[starty][startx], flag = 0;

			if (first == -2) continue;

			for (int j = starty; j < starty + current; j++) {
				for (int k = startx; k < startx + current; k++) {
					if (first != paper[j][k]) {
						// �� ���̰� ���� ������ �̷���� ���� ������
						flag = 1;
						break;
					}
				}
			}

			if (flag == 0) {
				// ���̰� ���� ������ �̷���� �ִ� ���
				answer[first + 1]++;
				for (int j = starty; j < starty + current; j++) {
					for (int k = startx; k < startx + current; k++) {
						// ����� �����̹Ƿ� -2�� �� �ٲ㼭 ��� ǥ��.
						paper[j][k] = -2;
					}
				}
			}

			startx += current;
			if (startx >= N) {
				// �� �ٲٱ�.
				startx = 0;
				starty += current;
			}
		}
		cut++;
		current = current / 3;
		// ���̸� �߶��ش� -> �� ���� ���� / 3
	}
	// �ݺ����� Ż���ϸ� ���� 1 x 1 ũ�⸸ ���´�. -> �� ���鼭 Ȯ��������.

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 1 x 1 ũ���� ���� ���� Ȯ��.
			if (paper[i][j] != -2) answer[paper[i][j] + 1]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << "\n";
	}
}