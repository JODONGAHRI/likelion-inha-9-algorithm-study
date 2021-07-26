#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int N = nums.size();

    sort(nums.begin(), nums.end()); // unique ���� ���� ����
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // unique�� ������ �ߺ��� ����

    if (nums.size() > N / 2) return N / 2;
    // �ߺ��� ���ŵ� ������ ����� �� �� �ִ� N//2���� ũ��, N/2���� ��ȣ�� ��� �ٸ���.
    else return nums.size(); // N/2���� ���� ���� �ߺ��� ���ŵ� ������ ������ ��ŭ �� �� �ִ�.
}