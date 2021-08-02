#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
	int* arr;
	int arrSize;
	int lastIdx = 0;
	int direction; // �ּ� / �ִ� �� ���� ����. 1�̸� �ּ�, -1�̸� �ִ� ��.

	Heap(int size, int direction) {
		this->arrSize = size;
		arr = new int[size];
		arr[0] = -1;
		this->direction = direction;
	}

	void swap(int parentIdx, int childIdx) {
		arr[0] = arr[parentIdx];
		arr[parentIdx] = arr[childIdx];
		arr[childIdx] = arr[0];
	}

	bool empty() { return lastIdx == 0; }

	int findRoot() {
		if (empty()) return 0;
		return arr[1];
	}

	void upHeap(int childIdx) {
		if (childIdx == 1) return; // ��Ʈ�� ���.

		else if (arr[childIdx / 2] * direction > arr[childIdx] * direction) {
			// �ּ� / �ִ뿡 ���� direction�� ���ؼ� �ε�ȣ ���� �ٲٱ�
			swap(childIdx / 2, childIdx);
			upHeap(childIdx / 2);
			return;
		}
		else return;
	}

	void downHeap(int parentIdx) {
		int child;
		if (parentIdx * 2 > lastIdx) return; // �ڽ��� ���� ���.
		else {
			if (parentIdx * 2 == lastIdx) child = parentIdx * 2; // �ڽ��� �� ���� ���.

			else { // �ڽ��� �� ���� ���, ���� �ڽ� ����.
				if (arr[parentIdx * 2] * direction <= arr[parentIdx * 2 + 1] * direction) child = parentIdx * 2;
				else child = parentIdx * 2 + 1;
			}

			if (arr[child] * direction < arr[parentIdx] * direction) {
				swap(parentIdx, child);
				downHeap(child);
				return;
			}
			else return;
		}
	}

	void insert(int num) {
		arr[++lastIdx] = num;
		upHeap(lastIdx);
	}

	void deleteRoot() {
		if (empty()) return;
		arr[1] = arr[lastIdx--];
		downHeap(1);
	}

	int mix(int k) {
		// ��� ������ ���ں� ������ k �̻��� �� �� ���� ���� �Լ�.
		int cnt = 0; // ����� �ϴ� Ƚ��
		while (arr[1] < k) { // ��Ʈ�� ����� �ּ� ���� k���� ���� ��� ��� �ݺ�
			if (lastIdx == 1) return -1;
			// ��Ʈ�� ���� ���. �� �̻� �� ���� ���� K �̻����� ���� �� ����. -1 ����.
			int num1 = arr[1]; // ���� ���� ���� ������ ���ں� ����
			deleteRoot();
			int num2 = arr[1]; // �� ��°�� ���� ���� ������ ���ں� ����
			deleteRoot();
			insert(num1 + (num2 * 2)); // ��� �ֱ�.
			cnt++;
		}
		return cnt;
	}
};

int solution(vector<int> scoville, int K) {
	int min = 1, size = scoville.size();
	Heap heap(size + 1, min); // �ּ� ������ ����.
	for (int i = 0; i < size; i++) {
		heap.insert(scoville[i]);
	}
	return heap.mix(K); // �ּ� Ƚ�� ã��.
}