#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, left = 0, right = people.size() - 1;

    sort(people.begin(), people.end());

    while (left < right) {  // ���� ���� ��(left)�� ���� ū ��(right)�� ���ϸ鼭 �߰� ������ ������
        if (people[left] + people[right] <= limit) { // ���� ū + ���� ������ limit ������ ��
            answer++;
            left++;
            right--;  // �� �� �¿��� ����
        }
        else { // ���� ��
            answer++;
            right--;  // ���� ū �� ��Ʈ �¿��� ����
        }
    }
    if (left == right) answer += 1;  // ���� ������, ���� ���� �ش��ϴ� ���� ��Ʈ ���¿�������. �̳� ����
    return answer;
}