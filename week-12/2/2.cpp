#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows�� 2���� �迭 sizes�� �� ����, sizes_cols�� 2���� �迭 sizes�� �� �����Դϴ�.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
	int answer = 0;

	// ���� �����ֱ�
	for (int i = 0; i < sizes_rows; i++) {
		if (sizes[i][0] < sizes[i][1]) {
			int tmp = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = tmp;
		}
	}

	//�� ���ο� ������ �ִ� �����ֱ� 
	int row_max = 0, col_max = 0;
	for (int i = 0; i < sizes_rows; i++) {
		if (row_max < sizes[i][0])
			row_max = sizes[i][0];
		if (col_max < sizes[i][1])
			col_max = sizes[i][1];
	}
	row_max *= col_max;
	answer = row_max;
	return answer;
}