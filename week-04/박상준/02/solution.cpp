#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> primes;

bool isPrime(int num) {
	// �־��� ���� �Ҽ����� Ȯ��
	if (num == 2) return true;
	else if (num < 2) return false;
	else if (num % 2 == 0) return false;
	else {
		for (int i = 3; i <= sqrt(num); i++) {
			if (num % i == 0) return false;
		} // num�� �����ٺ��� ���� ��� ���� �������� ��, num�� ���������� �ʴ´ٸ� num�� �Ҽ��̴�.
		return true;
	}
}

void check(string numbers) {
	if (isPrime(stoi(numbers))) {
		primes.push_back(stoi(numbers));
	}
}

int solution(string numbers) {
	sort(numbers.begin(), numbers.end());
	int string_length = numbers.length();

	// ������ ������ ��� ���� ���� Ȯ��
	do {
		for (int i = 1; i <= string_length; i++) {
			string temp = numbers.substr(0, i); // �տ������� �÷����鼭 Ȯ�� ex) "011" -> "0" "01" "011"
			check(temp);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());

	return primes.size();
}