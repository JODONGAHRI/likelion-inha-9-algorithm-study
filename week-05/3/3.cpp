#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {

	sort(people.begin(), people.end());
	int index = 0;  int answer = 0;

	//people vector�� empty�� ���� ���� ������
	while (index < people.size()) {
		int last = people.back(); people.pop_back();

		//���� ������ ��� + ���� ���ſ� ��� 
		if (people[index] + last <= limit)
			index++;
		answer++;
	}
	return answer;
}