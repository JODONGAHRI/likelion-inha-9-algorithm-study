#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	// �ð��� ���� ��찡 ������, �ð��� ���ٸ� ���̰� ���� ��찡 ������.
	if (a[0] == b[0]) return a[1] > b[1];
	else return a[0] < b[0];
}

int main() {
	int N, M, B, input;

	cin >> N >> M >> B;

	vector<vector<int>> space;
	for (int i = 0; i < N; i++) {
		space.push_back({});
		for (int j = 0; j < M; j++) {
			cin >> input;
			space[i].push_back(input);
		}
	}

	vector<vector<int>> results;
	for (int i = 256; i >= 0; i--) {
		// ���� �ִ� ���� 256���� Ȯ���غ���.
		int duration = 0, inven = B;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (space[j][k] > i) {
					// �ش� ĭ�� ���̰� ���� ���̺��� ���� ���.
					inven += space[j][k] - i;
					// ���� ��ŭ ����� �����ؼ� �κ��丮�� �ֱ�
					duration += 2 * (space[j][k] - i);
					// ������ ���*2 ��ŭ �ҿ� �ð� �߰�.
				}

				if (space[j][k] < i) {
					// �ش� ĭ�� ���̰� ���� ���̺��� ���� ���.
					inven -= i - space[j][k];
					// �κ����� �ʿ��� ��ϸ�ŭ ������
					duration += i - space[j][k];
					// ���� ��ϸ�ŭ �ҿ�ð� �߰�
				}
			}
		}

		if (inven >= 0) {
			// ���� �� �κ��丮�� �ִ� ���� 0 �̻��̸� �� ���̸� ���� �� �ְ�, 0 �̸��̸� �� ����� �����̴�.
			if (!results.empty() && duration > results[results.size() - 1][0]) break;
			// �ҿ�ð��� Ŀ���� ��Ȳ�� �߻��ϸ� �� ������ �ּҰ��̴�. �ٽ� �������� ���� ����.
			results.push_back({ duration,i });
		}
	}

	sort(results.begin(), results.end(), compare);
	cout << results[0][0] << " " << results[0][1];
}