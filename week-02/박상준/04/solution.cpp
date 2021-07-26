#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
	stack<int> indexes;
	vector<int> answer;

	int priceSize = prices.size();
	for (int i = 0; i < priceSize; i++) {
		answer.push_back(priceSize - 1 - i); // ������ ������ �������� �ʴ´ٰ� �����ϰ� �ִ밪���� �ʱ�ȭ.

		if (indexes.empty()) indexes.push(i);
		else {
			while (prices[indexes.top()] > prices[i]) { // ������ ������ ��� while������ ��.
				answer[indexes.top()] = i - indexes.top();
				// �ִ밪���� �ʱ�ȭ�ߴ� answer�� �ش� �ε��� ���� �������� ���� �Ⱓ���� ����.
				indexes.pop(); // ������ �ε��� ����.
				if (indexes.empty()) break;
				// ���� �ε������� ������ ������ ��ų�, �������� �ʾ��� ������ �ݺ�.
			}
			indexes.push(i);
		}
	}
	// for ���� Ż��������, ������ �������� ���� ���� ó���� �ʱ�ȭ�ߴ� �ִ밪 ����. 
	// ������ ���� while������ �������� ���� �Ⱓ���� ������.
	return answer;
}