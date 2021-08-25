#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	// ��ΰ� ������ ���� �� �ִٰ� �����ϰ� ����.

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	// ������ ������ �л��� �������� ��� -1�� �ٲ㼭 ����.
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] > lost[i]) break; // ���ĵǾ��� ������ ������ �� Ȯ���� �ʿ� x
			if (lost[i] == reserve[j]) {
				// ������ ������ �л��� �������� ���.
				lost[i] = -1;
				reserve[j] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		if (lost[i] == -1) continue; // ������ ������ �л��� �������� ��� ��ŵ
		int flag = 0; // ������ ���� �� �ִ��� üũ�� ����
		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] > lost[i] + 1) break; // ������ ���� �� ���� ��� ��ž
			else if (reserve[j] == lost[i] - 1 || reserve[j] == lost[i] + 1) { //������ ���� �� �ִ� ���
				flag = 1; // ���� ����
				reserve[j] = -1; // �� �� �����ָ� �� �� ������.
				break;
			}
		}
		if (flag == 0) answer--; // ������ ���
	}
	return answer;
}