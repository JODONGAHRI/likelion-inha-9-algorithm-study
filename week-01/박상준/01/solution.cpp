#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node() {
        name = "";
        next = NULL;
    }
    Node(string name) {
        this->name = name;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList() {
        head = new Node;
        tail = new Node;
        head = tail = NULL;
        sz = 0;
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
        sz++;
    }
};

class Hash {
public:
    LinkedList* participant;
    int sz;

    Hash(int N) {
        participant = new LinkedList[N];
        sz = N;
    }

    void insert(string name) {
        Node* newNode = new Node(name);
        participant[hashingName(name)].insert(newNode);
    }

    int find(string name) { // ���������� ���� �� �ֱ� ������, �� �� ã�� �����ڴ� ���Ḯ��Ʈ���� ����.
        Node* previous, * current;
        int flag = 0;

        previous = current = participant[hashingName(name)].head;
        while (current != NULL) {
            if (name == current->name) {
                flag = 1;
                break;
            }
            previous = current;
            current = current->next;
        }

        if (flag == 1) {
            if (current == participant[hashingName(name)].head) { // ã�� �����ڰ� ���Ḯ��Ʈ�� ����� ���
                if (participant[hashingName(name)].sz == 1) {
                    participant[hashingName(name)].head = participant[hashingName(name)].tail = NULL;
                }
                else {
                    participant[hashingName(name)].head = current->next;
                }
            }

            else { // ã�� �����ڰ� ���Ḯ��Ʈ�� ��尡 �ƴ� ���
                previous->next = current->next;
                if (current == participant[hashingName(name)].tail) participant[hashingName(name)].tail = previous;
            }
            return flag;
        }
        return flag;
    }

    int hashingName(string name) {
        int hash = 0;
        for (char c : name) {
            hash += int(c);
        }
        return hash % sz;
    }
};

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    Hash hash(participant.size());
    int result;
    for (int i = 0; i < completion.size(); i++) {
        hash.insert(completion[i]); // �����ڸ� �ؽÿ� ����
    }

    for (int i = 0; i < participant.size(); i++) {
        // �����ڿ� ���͸� ��ȸ�ϸ鼭 �ؽÿ� ����� �����ڿ� ��
        result = hash.find(participant[i]);
        if (result == 0) { //ã�� ���� ���(�������� ���� ���)
            answer += participant[i];
            break;
        }
    }
    return answer;
}