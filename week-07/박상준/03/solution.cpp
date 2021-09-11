#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<int>> costs;
	vector<int> cities;
	int N, cost;

	cin >> N;
	for (int i = 0; i < N; i++) {
		costs.push_back({});
		cities.push_back(i);
		for (int j = 0; j < N; j++) {
			cin >> cost;
			costs[i].push_back(cost);
		}
	}

	int min = -1;
	do {
		// ������ ��� ������ ���� ��ȸ�� �������� Ȯ������.
		int check = 0, result = 0;
		for (int i = 0; i < cities.size() - 1; i++) {
			if (costs[cities[i]][cities[i + 1]] == 0) {
				// ��ȸ�� ���� ���ϰ� �߰��� ��Ű�� ���.
				check = 1;
				break;
			}
			result += costs[cities[i]][cities[i + 1]];
		}

		if (costs[cities[cities.size() - 1]][cities[0]] == 0) check = 1;
		// ��ȸ�� ������ ������ ���ÿ��� ����ߴ� ���÷� ���ư� ���� ���� ���.

		if (check == 0) {
			// ��ȸ�� �Ϸ��� ���.
			result += costs[cities[cities.size() - 1]][cities[0]];
			// ������� ���ư��� �� ���ϱ�.
			if (min == -1 || result < min) min = result;
		}
	} while (next_permutation(cities.begin(), cities.end()));
	cout << min;
}