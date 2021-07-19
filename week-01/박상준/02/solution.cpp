#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    // ������ ����(���� ���ڳ��� ���ĵ�.) -> �ٷ� �ڿ� ��ġ�°� �ִ����� ���� ��.
    bool answer = true;

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i].length() >= phone_book[i + 1].length()) continue;
        //�� ��ȣ�� ���̰� �� ��ȣ�� ���̺��� ��ų� ������ �ߺ� Ȯ�� x

        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) {
            answer = false; // ���ξ��� ���.
            break;
        }
    }
    return answer;
}