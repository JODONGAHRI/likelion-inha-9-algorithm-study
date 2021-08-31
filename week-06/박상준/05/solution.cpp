#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	// �ﰢ���� �� ĭ�� �� ĭ���� �����ϸ鼭 ��ġ�� ������ �ִ밪���� ������.
	int triangle_size = triangle.size();
	for (int i = 1; i < triangle_size; i++) {
		for (int j = 0; j < i + 1; j++) {
			// ���� �� -> �밢�� ������ ��
			if (j == 0)  triangle[i][j] += triangle[i - 1][0];

			// ������ �� -> �밢�� ���� ��
			else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];

			else {
				// �����ʰ� ���� �� �� ū ��
				if (triangle[i - 1][j - 1] >= triangle[i - 1][j]) triangle[i][j] += triangle[i - 1][j - 1];
				else triangle[i][j] += triangle[i - 1][j];
			}
		}
	}
	// �ﰢ���� ���� �Ʒ� ���� �����ؼ� �ִ� �� ã��.
	sort(triangle[triangle_size - 1].begin(), triangle[triangle_size - 1].end());
	int answer = triangle[triangle_size - 1][triangle_size - 1];
	return answer;
}