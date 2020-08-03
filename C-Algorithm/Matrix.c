#include <stdio.h>

#define maxsize 5

//�����ת��
void trans(int a[][maxsize], int i) {
	int m, n;
	int b[maxsize][4];
	for (m = 0; m < maxsize; m++) {
		for (n = 0; n < i; n++) {
			b[m][n] = a[n][m];
		}
	}
	for (m = 0; m < maxsize; m++) {
		for (n = 0; n < i; n++) {
			printf("%d ", b[m][n]);
		}
		printf("\n");
	}
}

//�������
void add(int a[][maxsize], int b[][maxsize], int c[][maxsize],int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[j][i];
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

//�������
void mul(int a[][maxsize], int b[][maxsize], int c[][maxsize], int m, int n,int k) {
	int i, j, h;
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++) {
			c[i][j] = 0;
			for (h = 0; h < n; h++) {
				c[i][j] += a[i][h] * b[h][j];
			}
			printf("%d ", c[m][n]);
		}
		printf("\n");
	}
}

//2.1 ������A[0��...��n-1]��n��Ԫ�����ж����Ԫ�أ����һ���㷨����A�����еķ���Ԫ�������ƶ���A�����ǰ��
int move1(int A[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (A[i] == 0) {
			j = i + 1;
			while (A[j] == 0 && j < n) {
				j++;
			}
			if (j < n) {
				A[i] = A[j];
				A[j] = 0;
			}
			else {
				printf("%d֮���ֵ��Ϊ0", i);
				return 1;
			}
		}
	}
	return 1;
}

//2.1 ���ڸ���������A[0��...��n-1]���õݹ��㷨�����ֵ
float floatmax(float A[],int i, int j) { 
	float max;
	if (i == j) {
		return A[i];
	}
	else {
		max = floatmax(A, i + 1, j);
		if (A[i] > max)
			return A[i];
		else
			return max;
	}
}

//2.2 ���ڸ���������A[0��...��n-1]���õݹ��㷨��������n����֮��
float floatsum(float A[],int i, int n) {
	float sum; 
	if (i == n) {
		return A[i];
	}
	else {
		sum = A[i] + floatsum(A, i + 1, n);
		return sum;
	}
}

//2.3 ���ڸ���������A[0��...��n-1]���õݹ��㷨��n������ƽ��ֵ
float floatavg(float A[], int i, int n) {
	float avg;
	if (i == n) {
		return A[i];
	}
	else {
		avg = (A[i] + floatavg(A, i + 1, n)) / 2;
		return avg;
	}
}

//3 �����һ���㷨��������A[0��...��n-1]�����������Ƶ�ż��֮ǰ��Ҫ�������Ӵ洢�ռ䣬��ʱ�临�Ӷ�ΪO��n��
void moveto(int A[], int n) {
	int i, j, tag;
	for (i = 0; i < n; i++) {
		//�ж��Ƿ�������
		if (A[i] / 2 != 0) {

		} 
	}
}


int main() {

}