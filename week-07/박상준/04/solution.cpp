#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int target) {
	vector<vector<int>> triangle = { {0} };
	// ��Ʈ(0)�������� ������ ���� +�� - ������ ������� �ڽ����� ���� ���� Ʈ��.
	// �ﰢ���� ���� �Ʒ� ������ Ÿ�� �ѹ��� �� ����.
	for (int i = 0; i < numbers.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < triangle[i].size(); j++) {
			temp.push_back(triangle[i][j] + numbers[i]);
			temp.push_back(triangle[i][j] - numbers[i]);
		}
		triangle.push_back(temp);
	}

	int lastIndex = triangle.size() - 1, answer = 0;
	for (int i = 0; i < triangle[lastIndex].size(); i++) {
		if (triangle[lastIndex][i] == target) answer++;
	}
	return answer;
}