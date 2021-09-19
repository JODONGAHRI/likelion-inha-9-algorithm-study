#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int K, N, length;
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> length;
		arr.push_back(length);
	}
	sort(arr.begin(), arr.end());

	long long left = 1, right = arr[arr.size() - 1], current = right;
	// ���� �� ��츦 �ִ�� �ؼ� ����.
	while (left < right) {
		int cnt = 0;
		// ��������� ������ ����
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt == N) break;
		// �� N���� ��������� stop.

		if (cnt < N) right = current - 1; // ���� ��������� �ϳ��� ���̸� �ٿ�����.
		else left = current + 1; // ���� ��������� �ϳ��� ���̸� �÷�����.
		current = (left + right) / 2;
	}
	// ������ ������ ��, �װ� �ִ� ���̰� �ƴ� �� ����.
	while (true) {
		int cnt = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			cnt += arr[i] / current;
		}
		if (cnt < N) break;
		// ������ N���� �۾����� �� �� ���� �ִ� ��.
		current++;
	}
	cout << current - 1;
}