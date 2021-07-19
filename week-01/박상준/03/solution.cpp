#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	string name;
	string type;
	Node* next;

	Node() {
		next = NULL;
	}
	Node(string name, string type) {
		this->name = name;
		this->type = type;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = new Node;
		tail = new Node;
		head = tail = NULL;
	}

	bool empty() {
		return head == NULL && tail == NULL;
	}

	void insert(Node* newNode) {
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
};

class Hash {
public:
	LinkedList* arr;
	int sz;

	Hash(int N) {
		arr = new LinkedList[N];
		sz = N;
	}

	int hashingType(string type) { // ���� ���� �ؽ�
		int hash = 0;
		for (char c : type) {
			hash += int(c);
		}
		return hash % sz;
	}

	void insert(string name, string type) {
		Node* newNode = new Node(name, type);
		arr[hashingType(type)].insert(newNode);
	}

	int find(string type) {
		int cnt = 0, hashIndex = hashingType(type);
		Node* temp = arr[hashIndex].head;
		while (temp != NULL) {
			if (type == temp->type) cnt++;
			temp = temp->next;
		}
		return cnt;
	}
};

int solution(vector<vector<string>> clothes) {
	vector<string> types; // ������ ������ ����
	Hash hash(clothes.size());

	for (int i = 0; i < clothes.size(); i++) {
		hash.insert(clothes[i][0], clothes[i][1]);
		types.push_back(clothes[i][1]);
	}
	sort(types.begin(), types.end()); // unique ����ϱ� ���� ����
	types.erase(unique(types.begin(), types.end()), types.end()); // unique�� ���� ���Ϳ��� �ߺ� ����

	int answer = 1;
	for (int i = 0; i < types.size(); i++) {
		answer *= hash.find(types[i]) + 1;  // �������� �ϳ��� ���ϰų� or �ƹ��͵� �����ϰų�
	}
	return answer - 1; // ��� ������ ���ؼ� �� ���� ���(�ƹ��͵� ���Դ� ��� ���� -1)
}