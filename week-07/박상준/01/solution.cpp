#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	bool visited[2400000] = { false, }; // A = 9999, P = 5�� ��� 236,196
	int A, P;
	long long current; // ���� ����

	cin >> A >> P;
	vector<long long> result;

	current = A;
	while (visited[current] == false) {
		// true�� ������ �ݺ� ���� ������ ã�� ��.
		result.push_back(current);
		visited[current] = true;

		int temp = current;
		current = 0;
		while (temp >= 10) {
			current += pow(temp % 10, P);
			temp /= 10;
		}
		current += pow(temp, P);
	}

	int answer = 0;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == current) break;
		answer++;
	}
	cout << answer;
}