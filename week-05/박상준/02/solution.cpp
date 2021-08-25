#include <iostream>
#include <string>
using namespace std;

int solution(string name) {
	int answer = 0, move = name.length() - 1, len = name.length();
	// move�� �ּ� �̵� �Ÿ�.(�� �������� �����ϴ� ���� �ʱ�ȭ)
	for (int i = 0; i < name.length(); i++) {
		int aIndex = i; // ���ӵ� A���� ���� �� �ε���. 'A' / AA'A' / AAAA'A'
		if (name[i + 1] == 'A') aIndex++; // ���� �ε����� ���� ���� A�� ��� ���� �ε����� ��ġ��Ŵ
		while (aIndex < name.length() && name[aIndex] == 'A') {
			aIndex++; // ���� �� �ε��� ã��
		}

		if (aIndex > i) { // A�� �����ϴ� ���.
			move = min(move, 2 * i + len - aIndex);
			// ���� �ּ� �̵��Ÿ� move.
			// ���� ��ġ(i)���� �ڷ� ���ư� ����� �Ÿ� = �� ��ŭ i + �ٽ� ó������ i + �ڵ��Ƽ� ������ A ������ len-aIndex.
			// A�� �����Ҷ����� �ּ� �Ÿ� ������Ʈ.
		}

		//������ ���� ������Ʈ -> ��� ��ġ�� N�� �������� ����.
		if (int(name[i]) <= 78) {
			answer += int(name[i] - 65);
		}
		else {
			answer += int(91 - name[i]);
		}
	}
	answer += move; //�̵� Ƚ�� ������
	return answer;
}