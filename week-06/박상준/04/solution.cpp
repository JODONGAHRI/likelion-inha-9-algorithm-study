#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, score;
	cin >> n;

	vector<int> scores;
	for (int i = 0; i < n; i++) {
		cin >> score;
		scores.push_back(score);
	}

	vector<int> dp = { scores[0] }; // ù ��ܱ����� �ִ밪.
	if (n > 1) dp.push_back(scores[0] + scores[1]); // �ι�° ��ܱ����� �ִ밪.
	if (n > 2) dp.push_back(max(scores[0] + scores[2], scores[1] + scores[2])); // ����° ��ܱ����� �ִ밪.
	for (int i = 3; i < n; i++) {
		// ��Ģ�� ��Ű�鼭 i��° ��ܱ��� �����ϱ� ���� ����� 2������ �ִ�.
		// 1) i-2��° ��ܿ��� �� ����� ������.
		// 2) i-3���� ��ܿ��� �� ����� �ö� i-1��° ��ܿ� �����ϰ�, �ű⼭ �� ����� ������.
		// �̸� ��ȭ������ ǥ���ϸ� �Ʒ��� ����.
		// ��ȭ�� �ȼ���� ������ ���ͷ� �� �����ϸ鼭 �ϴٰ� ��ӵǴ� �޸� �ʰ��� ���������
		dp.push_back(max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]));
	}
	cout << dp[n - 1];
}