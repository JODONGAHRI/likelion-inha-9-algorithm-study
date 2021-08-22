#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int col, row;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            // �� ���� ���� ���� ����� ī���� ���� ���
            col = i;
            row = yellow / i;
            if (2 * col + 2 * row + 4 == brown) break;
            // ���� ���� �� = ��� ���� (���� * 2 + ���� * 2 + 4)
        }
    }
    vector<int> answer = { row + 2, col + 2 };
    // ī���� ���� ���� ���̴� ������� ���ΰ� �ִ� ��������� ���� ���� ������� ���� ���ο� + 2 �� ���ش�.
    return answer;
}