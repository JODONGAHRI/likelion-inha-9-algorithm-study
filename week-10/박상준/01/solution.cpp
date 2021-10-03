#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, input, middle, most, range;
	double average = 0;
	cin >> N;

	int* arr = new int[N];
	int* check = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
		check[i] = 0;
	}

	sort(arr, arr + N);

	middle = arr[N / 2]; // �߾Ӱ�
	range = arr[N - 1] - arr[0]; // ����
	for (int i = 0; i < N; i++) {
		average += arr[i];
	}
	average = average / N; // ���

	check[0] = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) check[i] = check[i - 1] + 1;
		else check[i] = 1;
	}
	// ���ӵ� ���� ����� Ȯ��

	int mostCnt = *max_element(check, check + N); // �ֺ��� Ƚ�� Ȯ��
	vector<int> mostIdx;
	for (int i = 0; i < N; i++) {
		if (check[i] == mostCnt) mostIdx.push_back(i);
		if (mostIdx.size() == 2) break; // 2�� �̻��̸� 2��������.
	}
	most = arr[mostIdx[mostIdx.size() - 1]];
	// �ֺ�.

	cout << fixed;
	cout.precision(0); // �Ҽ��� ���� ù° �ڸ����� �ݿø�
	cout << average << "\n" << middle << "\n" << most << "\n" << range;
}