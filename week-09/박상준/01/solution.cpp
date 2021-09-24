#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	vector<int> toMake;
	int n, input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		toMake.push_back(input);
	}

	stack<int> stack;
	vector<char> answer;
	int index = 0, cnt = 1;
	while (cnt <= n) {
		// 1���� n���� ������� ����.
		if (!stack.empty() && stack.top() == toMake[index]) {
			// ������ ����ų�, ���� ž�� ���;� �ϴ� ���
			stack.pop();
			answer.push_back('-');
			index++;
		}

		else {
			// cnt�� �׳� ���ÿ� �ִ� ���
			stack.push(cnt++);
			answer.push_back('+');
		}
	}
	// n���� ���ÿ� �ְ� �ݺ����� Ż���ϸ� ���ÿ� �����ִ� ������ �����Ѵ�.

	int flag = 0;
	while (!stack.empty()) {
		// ���ÿ� ���� ���� ���� ������
		if (stack.top() == toMake[index++]) {
			// ž�� �ִ� ���� ���;� �� ���� ������.
			stack.pop();
			answer.push_back('-');
		}

		else {
			//ž�� �ִ� ���� ���;� �� ���� �ƴϸ�, ���ο� ���� ������ �����Ƿ� �� ������ �� �����.
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		// ���� �� �ִ� ������ ���
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
	}
	else cout << "NO"; // �� ����� ������ ���
}