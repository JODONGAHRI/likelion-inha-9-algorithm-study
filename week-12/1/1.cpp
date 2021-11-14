#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len�� �迭 numbers�� �����Դϴ�.
int solution(int numbers[], size_t numbers_len) {
	int answer = 0;
	int flag[10];
	for (int i = 0; i < 10; i++) {
		flag[i] = 0;
	}
	for (int i = 0; i < numbers_len; i++) {
		flag[numbers[i]] = 1;
	}
	for (int i = 0; i < 10; i++) {
		if (!flag[i])
			answer += i;
	}
	if (answer == 0)
		answer = -1;
	return answer;
}