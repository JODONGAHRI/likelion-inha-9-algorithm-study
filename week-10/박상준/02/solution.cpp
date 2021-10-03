#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> farm;
vector<vector<bool>> visited;

int N, M;

void bfs(int x, int y) {
	queue<vector<int>> q;

	q.push({ x,y });
	visited[y][x] = true;

	int cnt = 0;
	while (!q.empty()) {
		vector<int> current = q.front();
		q.pop();

		if (current[1] > 0 && farm[current[1] - 1][current[0]] == 1 && visited[current[1] - 1][current[0]] == false) {
			// ��
			q.push({ current[0], current[1] - 1 });
			visited[current[1] - 1][current[0]] = true;
		}

		if (current[1] < N - 1 && farm[current[1] + 1][current[0]] == 1 && visited[current[1] + 1][current[0]] == false) {
			// �Ʒ�
			q.push({ current[0], current[1] + 1 });
			visited[current[1] + 1][current[0]] = true;
		}

		if (current[0] > 0 && farm[current[1]][current[0] - 1] == 1 && visited[current[1]][current[0] - 1] == false) {
			// ����
			q.push({ current[0] - 1, current[1] });
			visited[current[1]][current[0] - 1] = true;
		}

		if (current[0] < M - 1 && farm[current[1]][current[0] + 1] == 1 && visited[current[1]][current[0] + 1] == false) {
			// ������
			q.push({ current[0] + 1, current[1] });
			visited[current[1]][current[0] + 1] = true;
		}
	}
}

int main() {
	int T, K;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < N; j++) {
			farm.push_back({});
			visited.push_back({});
			for (int k = 0; k < M; k++) {
				farm[j].push_back(0);
				visited[j].push_back(false);
			}
		}

		int x, y;
		vector<vector<int>> planted;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			farm[y][x] = 1;
			planted.push_back({ x,y });
		}

		int cnt = 0;
		for (int j = 0; j < planted.size(); j++) {
			if (visited[planted[j][1]][planted[j][0]] == false) {
				bfs(planted[j][0], planted[j][1]);
				cnt++;
				// ���߰� �ɾ����ִ� ��ǥ�鿡 ���ؼ� bfs �Լ��� ���� Ƚ�� Ȯ��.
				// ���� �� ���� ������ �� ����.
			}
		}
		cout << cnt << "\n";

		farm.clear();
		visited.clear();
	}
}