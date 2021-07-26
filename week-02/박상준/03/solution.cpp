#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;
	int answer = 0, size = 0; //size�� "����" �ö��ִ� ����

	for (int i = 0; i < bridge_length; i++) q.push(0); //ó�� ���� �� q�� �ٸ� ���̸�ŭ �ʱ�ȭ. 
	//ex) 0 0 0 0 0 �̷������� �ٸ� ���� ��ŭ ������ ������ �����ϸ鼭 ����
	for (int num : truck_weights) {
		size -= q.front();
		q.pop(); // ���ο� Ʈ���� �ø��� ���� �տ��� �ϳ� �� ex) 0 0 0 0

		while ((size + num) > weight) { //�ٸ��� ���԰� ������ ���ο� Ʈ���� ���ö󰡴� �Ⱓ
			size -= q.front();
			q.pop(); // �� �� Ʈ�� ������.
			q.push(0); // ���ο� Ʈ���� ���ö���� �� ĭ�� 0���� ä����.
			answer++;
		}
		// while�� Ż�� -> ���ο� Ʈ���� �ٸ��� �ö�� �� �ִ�.
		q.push(num);
		size += num; // ���ο� Ʈ���� �ٸ��� �ö��
		answer++;
	}
	// ���� ���� ������ Ʈ���� "�ٸ��� �ö���� ����" for�� ����.
	// �ٸ��� �� ���� Ʈ���� �����ִ����� ������� ��� �ٸ��� �ö�� ������ Ʈ���� �����Ű�� �ȴ�.
	answer += bridge_length; // �ٸ� ���̸�ŭ + ���ָ� ������ Ʈ�� ���.
	return answer;
}