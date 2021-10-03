#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hashing(string address, int N) {
	// �ּ� ���� �ؽ�.
	int hashedIndex = 0;
	for (char c : address) {
		hashedIndex += int(c);
	}
	return hashedIndex % N;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<vector<string>>> saves;
	for (int i = 0; i < N; i++) {
		saves.push_back({});
	}

	string address, password;
	for (int i = 0; i < N; i++) {
		cin >> address >> password;
		saves[hashing(address, N)].push_back({ address,password });
		// �Է� ���� �ּҷ� �ؽ��Ͽ� �ּҿ� ��й�ȣ ����.
	}

	for (int i = 0; i < M; i++) {
		cin >> address;
		int hashedIndex = hashing(address, N);
		for (int j = 0; j < saves[hashedIndex].size(); j++) {
			if (address == saves[hashedIndex][j][0]) {
				// �Է� ���� �ּҷ� �ؽ��Ͽ� ��й�ȣ �ҷ�����.
				cout << saves[hashedIndex][j][1] << "\n";
				break;
			}
		}
	}
}