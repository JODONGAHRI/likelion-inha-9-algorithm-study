#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	string genre;
	int play;
	int plays; // �� �帣�� total play
	int number; // ������ȣ
	Node* next;

	Node() {
		next = NULL;
	}

	Node(string genre, int play, int number) {
		this->genre = genre;
		this->play = play;
		this->plays = play;
		this->number = number;
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

			Node* temp = head;
			while (temp->genre != newNode->genre) {
				temp = temp->next; // �ؽ� �浹�� �߻����� ��, genre�� ���� ù ��� ã��
			}
			if (temp->number != newNode->number) temp->plays += newNode->play;
			// temp�� head�������� Ž���ϱ� ������, head�� genre�� newNode�� genre�� �ٸ� ��� �׻� ù��°
			// ��忡�� while���� ����. ���� �� ���� temp�� ���� ���� newNode�� �ٸ� ���� total �� +
		}
	}
};

bool func2(Node* a, Node* b) {  // ���� �帣 �������� �� ����
	if (a->play == b->play) return a->number < b->number;  // 3�� ����. ��� Ƚ���� ������ ������ȣ ��
	return a->play > b->play;
}

class Hash {
public:
	LinkedList* arr;
	int sz;

	Hash(int N) {
		arr = new LinkedList[N];
		sz = N;
	}

	int hashingGenre(string genre) { // genre ���� �ؽ�
		int hash = 0;
		for (char c : genre) {
			hash += int(c);
		}
		return hash % sz;
	}

	void insert(string genre, int play, int number) {
		Node* newNode = new Node(genre, play, number);
		arr[hashingGenre(genre)].insert(newNode);
	}

	Node* getHead(string genre) { // genre�� �ش��ϴ� ù ��� ã��.
		int hashIndex = hashingGenre(genre);
		Node* temp = arr[hashIndex].head;
		while (temp->genre != genre) temp = temp->next; // �ؽ� �浹�� �߻��ϴ� ��쿡 ���� ó��.
		return temp;
	}

	vector<Node*> getAll(Node* head) { // �Ķ���Ϳ� �ش��ϴ� ����� genre�� ���� genre�� ��� ��� ����
		vector<Node*> vec;
		Node* temp = getHead(head->genre);
		while (temp != NULL) {
			if (head->genre == temp->genre) vec.push_back(temp);
			temp = temp->next;
		}
		sort(vec.begin(), vec.end(), func2); // ��� Ƚ�� �� ���� ��ȣ �������� ����
		return vec;
	}
};

bool func(Node* a, Node* b) { // �帣�� ��� Ƚ�� ���� ����
	return a->plays > b->plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	Hash hash(genres.size());
	for (int i = 0; i < genres.size(); i++) {
		hash.insert(genres[i], plays[i], i);
	}

	sort(genres.begin(), genres.end());
	genres.erase(unique(genres.begin(), genres.end()), genres.end()); // �帣 �ߺ� ����

	vector<Node*> total; // �帣 �� �ִ� ���� ������ �� �帣�� ��� ��带 ������ ����
	for (int i = 0; i < genres.size(); i++) {
		total.push_back(hash.getHead(genres[i]));
	}
	sort(total.begin(), total.end(), func); // �帣 �� ��� Ƚ�� ���� �帣 ����

	vector<int> answer;
	for (int i = 0; i < total.size(); i++) {
		vector<Node*> temp = hash.getAll(total[i]);
		int cnt = 0;
		for (int i = 0; i < temp.size() && cnt < 2; i++) {
			answer.push_back(temp[i]->number);
			cnt++; // cnt�� �ִ� 2���϶������� ���� ���Ϳ� Ǫ��
		}
	}
	return answer;
}