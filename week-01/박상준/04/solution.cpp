#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    // ���� ������ ���, a�� b�� ���� ������ 2�� ���� �� + �������� ���� ����.
    // ���� �������� ���� �־����� ��ȣ�� ������ ��ȣ�� 2�� ���� �� + �������� ���̴�.
    // ���� a == b �϶� break.
    while (true) {
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
        if (a == b) break;
    }
    return answer;
}