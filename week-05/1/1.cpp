#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n, 1); //����ũ�Ⱑ n�̰� ��� ���Ҹ� 1�� �ʱ�ȭ��Ű��

	//student vector�� �л� ���� �����ϱ� 
	for (int i = 0; i < reserve.size(); i++) {
		student[reserve[i] - 1]++;
	}
	for (int i = 0; i < lost.size(); i++) {
		student[lost[i] - 1]--;
	}

	//ü���� �ΰ��� ����� �����ֱ�
	for (int i = 0; i < n; i++) {
		if (student[i] == 0 && student[i - 1] == 2) {
			student[i]++; student[i - 1]--;
		}
		if (student[i] == 0 && student[i + 1] == 2) {
			student[i]++; student[i + 1]--;
		}
	}
	//ü���������ִ� �л� �� ����
	for (int i = 0; i < student.size(); i++) {
		if (student[i] > 0) answer++;
	}

	return answer;
}