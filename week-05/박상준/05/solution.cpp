#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����� �������� �������� ����
bool sortByCost(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
	//costs�� ����� �������� �������� ����
	sort(costs.begin(), costs.end(), sortByCost);

	// ����� ������ �����ϴ� ����. ���� ���� ����� ��ΰ� �̾��ִ� �� ������ �ʱ�ȭ.
	vector<int> connected = { costs[0][0], costs[0][1] };
	int answer = costs[0][2];

	// �ش� ���� ����Ǿ����� Ȯ���ϱ� ����. ó�� �� ���� �̾��� ���·� ����.
	vector<int> check;
	for (int i = 0; i < n; i++) check.push_back(0);
	check[costs[0][0]]++;
	check[costs[0][1]]++;

	//ù ���� �̾��ְ� �����ϴ� ��������.
	costs.erase(costs.begin());
	while (connected.size() < n) {
		// ��� ���� �̾���������
		int size = costs.size();
		for (int i = 0; i < size; i++) {
			if (check[costs[i][0]] == 0 && check[costs[i][1]] != 0) {
				// costs�� 0��° �ε��� ���� �̾����� �ʾ��� ��, 1��° �ε����� ���� �̾����ִ� ���¶��
				check[costs[i][0]]++;
				connected.push_back(costs[i][0]);
				answer += costs[i][2];
				costs.erase(costs.begin() + i);
				break;
			}

			if (check[costs[i][1]] == 0 && check[costs[i][0]] != 0) {
				// costs�� 1��° �ε��� ���� �̾����� �ʾ��� ��, 0��° �ε����� ���� �̾����ִ� ���¶��
				check[costs[i][1]]++;
				connected.push_back(costs[i][1]);
				answer += costs[i][2];
				costs.erase(costs.begin() + i);
				break;
			}
		}
	}
	return answer;
}