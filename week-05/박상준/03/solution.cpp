#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//�������� ���� �� �Լ�
bool func(char a, char b) {
    return a > b;
}

string solution(string number, int k) {
    int cnt = 0;
    string temp = number;
    sort(temp.begin(), temp.end(), func);

    if (temp == number) {
        // �̹� �������� ���ĵ� ���� ��� -> �׳� �ڿ��� k�� ������.
        while (cnt < k) {
            number.pop_back();
            cnt++;
        }
    }

    else {
        // �������� ���ĵ� ���� �ƴ� ���
        while (cnt < k) {
            for (int i = 0; i < number.length() - 1; i++) {
                if (number[i] < number[i + 1]) { // a �ڿ� ���� ���� a ���� ū ���.
                    number = number.substr(0, i) + number.substr(i + 1); // a ����
                    cnt++; // ���� Ƚ�� ++
                    break;
                }
                // a �ڿ� ���� ���� a ���� �۰ų� ���� ��� �׳� �α�
            }
        }
    }
    return number;
}