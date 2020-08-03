#include <stdio.h>

#define maxsize 5

//矩阵的转置
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

//矩阵相加
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

//矩阵相乘
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

//2.1 设数组A[0，...，n-1]的n个元素中有多个零元素，设计一个算法，将A中所有的非零元素依次移动到A数组的前端
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
				printf("%d之后的值都为0", i);
				return 1;
			}
		}
	}
	return 1;
}

//2.1 关于浮点型数组A[0，...，n-1]，用递归算法求最大值
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

//2.2 关于浮点型数组A[0，...，n-1]，用递归算法求数组中n个数之和
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

//2.3 关于浮点型数组A[0，...，n-1]，用递归算法求n个数的平均值
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

//3 试设计一个算法，将数组A[0，...，n-1]中所有奇数移到偶数之前。要求不另增加存储空间，且时间复杂度为O（n）
void moveto(int A[], int n) {
	int i, j, tag;
	for (i = 0; i < n; i++) {
		//判断是否是奇数
		if (A[i] / 2 != 0) {

		} 
	}
}


int main() {

}