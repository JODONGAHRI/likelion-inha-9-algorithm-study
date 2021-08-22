#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> TriangleNum = { 1,3,6,10,15,21 };
	int n, num;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int size = TriangleNum.size();
		if (TriangleNum[size - 1] < num) {
			// �ﰢ�� ���Ϳ� ����� ������ ���� num���� ���� ���
			while (TriangleNum[size - 1] + size + 1 < num) {
				// ���� �ﰢ�� ���� num���� ������ ���Ϳ� �߰�.
				TriangleNum.push_back(TriangleNum[size - 1] + size + 1);
				size++;
			}
		}

		int flag = 0;
		for (int first = size - 1; first >= 0 && flag != -1; first--) {
			if (TriangleNum[first] * 3 < num) break; // ���� ū ���� 3�� ���Ѱ� num���� ������ �� �� �ʿ� ����.
			
			for (int second = first; second >= 0; second--) {
				if (flag == 1) break; // ���� ã�� ���.

				if (second==first-1&&TriangleNum[first] + TriangleNum[second] * 2 < num) {
					// second�� first �̸��� �� �� ���� ū ���϶�, first + second + second�� num���� ������ �� second���� ���� second�� �� Ȯ���� �ʿ� ����.
					flag = -1;
					break;
				}

				for (int third = second; third >= 0; third--) {
					if (TriangleNum[first] + TriangleNum[second] + TriangleNum[third] < num) break;
					// �� ���� ���� ���� num���� �۾����� �� ���� ���� third�� �� Ȯ���� �ʿ� ����.
					
					if (TriangleNum[first] + TriangleNum[second] + TriangleNum[third] == num) {
						// ���� ã�� ���.
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break; // ���� ã�� ���.
		}
		if (flag == 1) cout << "1\n";
		else cout << "0\n";
	}
}