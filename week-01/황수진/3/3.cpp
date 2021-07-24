#include <string>
#include <vector>
#include <map>

using namespace std;

//�� ���� map���� ���ϱ�(key��)
//(key,value)=(face,3),(eyewear,2),(headgear,1)



int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> category;

	//(key,value) ���� �����ϱ�
	for (int i = 0; i < clothes.size(); i++) {
		if (category.count(clothes[i][1]) == 1)
			category[clothes[i][1]]++;
		else
			category[clothes[i][1]] = 1;
	}
	//����� �� ����

	for (auto iter = category.begin(); iter != category.end(); ++iter) {
		answer *= ((iter->second) + 1);
	}
	answer--;
	return answer;
}

