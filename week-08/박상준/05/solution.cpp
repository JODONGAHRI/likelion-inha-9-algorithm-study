#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	long long max = times[times.size() - 1], left = 0, right = max * n, current = right;
	// ������ �ִ� ���� ���� �� �ð����� n��.
	while (left < right) {
		long long person = 0;
		for (int i = times.size() - 1; i >= 0; i--) {
			person += current / times[i];
			// ���� �ð����� �� ���� �Ա��ɻ縦 ���� �� �ִ��� Ȯ��.
			if (person > n) break;
			// n���� �Ѿ�� �� �غ� �ʿ� ����.
		}
		if (person == n) break;
		// �� n���� ���� �� �ִ� �ð��̸� stop.

		if (person < n) left = current + 1; // n���� ���� �޾����� �ð��� �÷�����.
		else right = current - 1; // n���� ���� �޾����� �ð��� �ٿ�����.
		current = (left + right) / 2;
	}
	// ������ ������ �� �� �ð��� �ּҰ��� �ƴ� �� ����.

	while (true) {
		long long person = 0;
		for (int i = times.size() - 1; i >= 0; i--) {
			person += current / times[i];
		}
		if (person < n) break;
		// ���� �� �ִ� ����� n���� �������� �� �� �ð��� �ּҰ�.
		current--;
	}
	return current + 1;
}