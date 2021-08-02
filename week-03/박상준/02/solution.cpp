#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ū ���� ���� �����ϱ� ���� �Լ�.
bool compare(string left, string right) {
	int len = min(left.length(), right.length());

	for (int i = 0; i < len; i++) { // �� ���� �� �� ª�� ���� ���̸�ŭ ��.
		if (left[i] > right[i]) return true;
		else if (left[i] < right[i]) return false;
	} // �� ª�� ���� ���̸�ŭ ������ ��, �� ū ���� �����Ǹ� ����

	// ������ len��ŭ ������ ��, ���� ������, �� �� ���� ���� ���̸�ŭ ��.
	// �� �� ������ len ������ �� + �� �ڿ� �� ª�� ���� ���� ���� 
	// vs �׳� �� �� ���� ���� ��� ��.
	// ex) 3333123  33331�� ���, 33331 vs 33331�� for�� ����ϰ� ������ ������
	// (33331) 2333331  vs  (33331) 3333123 ���ؼ� ����.
	if (left.length() > right.length()) {
		string sub = left.substr(len, left.size() - 1) + right;
		if (sub > left) return true;
		else return false;
	}

	else if (right.length() > left.length()) {
		string sub = right.substr(len, right.size() - 1) + left;
		if (sub > right) return false;
		else return true;
	}
	return false;
}

string solution(vector<int> numbers) {
	vector<string> toStringNumbers;

	int size = numbers.size();
	for (int i = 0; i < size; i++) toStringNumbers.push_back(to_string(numbers[i]));
	sort(toStringNumbers.begin(), toStringNumbers.end(), compare); // ���� ū �� ã�Ƽ� ����.

	string answer = "";
	for (string str : toStringNumbers) {
		if (answer == "" && str == "0") continue; // �� �տ� 0�� �� �� ����.
		answer += str;
	}
	if (answer == "") answer = "0";
	// numbers�� 0�� �ִ� ���, �� for������ continue �߱⿡ answer�� ���.
	return answer;
}