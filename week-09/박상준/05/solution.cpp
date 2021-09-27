#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> space;
vector<vector<bool>> visited;
queue<vector<int>> q;
int N, M;

int countTop(int i, int j) {
	// �������� ������ ���
	int top = 0;
	while (i > 0 && space[--i][j] != 1) {
		if (space[i][j] == 0) {
			top++;
			q.push({ i,j });
			space[i][j] = 2;
		}
	}
	return top;
}

int countBottom(int i, int j) {
	// �Ʒ������� ������ ���
	int bottom = 0;
	while (i < N - 1 && space[++i][j] != 1) {
		if (space[i][j] == 0) {
			bottom++;
			q.push({ i,j });
			space[i][j] = 2;
		}
	}
	return bottom;
}

int countLeft(int i, int j) {
	// �������� ������ ���
	int left = 0;
	while (j > 0 && space[i][--j] != 1) {
		if (space[i][j] == 0) {
			left++;
			q.push({ i,j });
			space[i][j] = 2;
		}
	}
	return left;
}

int countRight(int i, int j) {
	// ���������� ������ ���
	int right = 0;
	while (j < M - 1 && space[i][++j] != 1) {
		if (space[i][j] == 0) {
			right++;
			q.push({ i,j });
			space[i][j] = 2;
		}
	}
	return right;
}

int spread(int i, int j) {
	return countTop(i, j) + countRight(i, j) + countBottom(i, j) + countLeft(i, j);
}

int bfs(int i, int j) {
	q.push({ i,j });
	visited[i][j] = true;

	int visit = 0;
	while (!q.empty()) {
		vector<int> current = q.front();
		q.pop();
		visit += spread(current[0], current[1]);
	}
	return visit;
}

int main() {
	vector<vector<int>> virus, safeArea, temp;
	int input, safe = 0, min = 9999;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		space.push_back({});
		temp.push_back({});
		visited.push_back({});
		for (int j = 0; j < M; j++) {
			cin >> input;
			space[i].push_back(input);
			temp[i].push_back(input);
			visited[i].push_back(false);
			if (input == 0) {
				safeArea.push_back({ i, j });
				safe++;
			}

			if (input == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	vector<bool> combination(safeArea.size() - 3, false);
	combination.insert(combination.end(), 3, true);
	// 0�� �Էµ��ִ� ���������� �߿��� ���Ƿ� 3���� �̾� ���� ����� ��� ����� ��.
	int cnt = 1;
	do {
		vector<vector<int>> selected;
		for (int i = 0; i < safeArea.size(); i++) {
			if (combination[i]) selected.push_back(safeArea[i]);
		}

		for (int i = 0; i < selected.size(); i++) {
			space[selected[i][0]][selected[i][1]] = 1;
		}

		int virused = 0;
		for (int i = 0; i < virus.size(); i++) {
			virused += bfs(virus[i][0], virus[i][1]);
			// ������ ��쿡 �����Ǵ� �� Ȯ��.
		}
		if (virused < min) min = virused;
		// �ּҰ��̸� ����.
		space = temp;
	} while (next_permutation(combination.begin(), combination.end()));

	if (min == 9999) min = 0;
	cout << safe - min - 3;
	// �������� - ������ ������ �ּҰ� - �� 3��
}