#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	queue<int> days; // �� ��� ���߿� �ҿ�� �ϼ��� ���� ť

	int size = progresses.size();
	for (int i = 0; i < size; i++) {
		int day = (100 - progresses[i]) / speeds[i];
		if ((100 - progresses[i]) % speeds[i] != 0) day++;
		//�� ��� ���߿� �ҿ�Ǵ� �ϼ� ���
		days.push(day);
	}

	vector<int> answer;
	while (!days.empty()) {
		int pop = 1, front = days.front();
		days.pop(); // �� �� ��� ����.
		while (!days.empty() && front >= days.front()) {
			days.pop();
			pop++;
			// �� ��ɵ��� �ҿ� �ϼ��� �۰ų� ���� ��� �Բ� ����.
		}
		answer.push_back(pop);
	}
	return answer;
}