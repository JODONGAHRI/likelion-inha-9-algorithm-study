#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int size = commands.size();
    for (int i = 0; i < size; i++) {
        vector<int> sol;  // �߶� ������ �ӽ� ����
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) sol.push_back(array[j]);
        // i��° ~ j��° ���ڱ��� �߶� sol�� �ֱ�.
        sort(sol.begin(), sol.end());
        answer.push_back(sol[commands[i][2] - 1]); // k��° ��
    }
    return answer;
}