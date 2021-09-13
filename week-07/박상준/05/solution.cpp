#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start, int& connected) {
	visited[start] = true;
	connected++;
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == false) dfs(next, connected);
	}
}

int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i < n; i++) {
		graph.push_back({});
		visited.push_back(false);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (computers[i][j] == 1) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	int connected = 0, networks = 0;
	// ����� ��ǻ���� ���� ��Ʈ��ũ�� ��.
	dfs(0, connected);
	networks++;
	// ù ��ȸ�� ���� ��, connect �� Ȯ��.
	while (connected < n) {
		// ����� ��ǻ���� ���� ��ü ��ǻ���� ���� �� �� ����,
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				// �湮 üũ ���͸� ��ȸ�ϸ鼭 ���� �湮���� ���� ��� Ȯ��.
				dfs(i, connected);
				// �ű⼭���� �ٽ� ��ȸ ����, connected ����.
				networks++;
				// ��Ʈ��ũ�� �� ++
			}
		}
	}
	return networks;
}