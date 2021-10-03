#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, R, G, B;
	cin >> N;

	cin >> R >> G >> B;
	vector<int> min = { R,G,B };
	// R�� ���, �� �������� min[1]�� min[2]�� ���� ���� �����Ͽ� ���ο� R�� ���ؼ� min[0]�� ��������.
	// �ٸ� ���� ��쿡�� ���� �������.
	for (int i = 0; i < N - 1; i++) {
		cin >> R >> G >> B;
		if (min[1] < min[2]) R += min[1];
		else R += min[2];

		if (min[0] < min[2]) G += min[0];
		else G += min[2];

		if (min[0] < min[1]) B += min[0];
		else B += min[1];

		min[0] = R;
		min[1] = G;
		min[2] = B;
		// min[0~2]�� ���� �ﰢ�� ���� ó�� �ű���� ���µ� �ʿ��� �ּ� ����� �����س�����.
	}
	sort(min.begin(), min.end());
	cout << min[0];
}