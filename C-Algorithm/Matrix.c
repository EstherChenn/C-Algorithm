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
			c[i][j] = a[i][j] + b[i][j];
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
	int i, j, k;
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
				printf("%d之后的值都为0\n", i);
				for (k = 0; k < n; k++) {
					printf("%d ", A[k]);
				}
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
		else {
			printf("max = %d\n", max);
			return max;
		}
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
	//tag是奇数的插入标志
	int i, j, tag = 0;
	int s;
	//判断首位
	if (A[0] / 2 != 0) {
		tag = 1;
	}
	else {
		tag = 0;
	}
	for (i = 1; i < n; i++) {
		//判断是否是奇数
		if (A[i] / 2 != 0) {
			s = A[tag];
			A[tag] = A[i];
			A[i] = s;
			tag++;
		} 
	}
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
}

//4. 设有一元素为整数的线性表L，存放在一维数组A[0，...，n-1]中，设计一个算法，以A[n-1]为参考量，将该数组分为左右两个部分，
//其中左半部分的元素值均小于等于A[n-1]，右半部分的元素值均大于A[n-1]，A[n-1]则位于这两部分之间。要求结果仍存放在数组A中。


//5. 设计一个算法，对给定的一个整型m*n矩阵A，统计这个矩阵中具有下列特征的元素个数并输出它们的坐标及数值：它们既是所在行中
//的最小值，又是所在列中的最小值；或者它们既是所在行中的最大值，又是所在列中的最大值。假设矩阵中元素各不相同，要求结果在
//处理过程中用输出语句输出
void pick(int A[][maxsize], int m, int n) {
	int i, j, k, z;
	int min, max;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			k = 0;
			z = 0;
			min = A[i][j];
			max = A[i][j];
			//先找最小值
			while (k < (m >  n ? m:n )) {
				if (k < m) {
					min = min < A[i][k] ? min : A[i][k];
				}
				if (k < n) {
					min = min < A[k][j] ? min : A[k][j];
				}
				k++;
			}
			//找最大值
			while (z < (m > n ? m : n)) {
				if (z < m) {
					max = max > A[i][z] ? max : A[i][z];
				}
				if (z < n) {
					max = max > A[z][j] ? max : A[z][j];
				}
				z++;
			}
		}
		printf("第%d行%d列的最小值是：%d，最大值是：%d \n", i, j, min, max);
	}
}


int main() {
	int A[3][5] = { 0,1,2,3,4, 5,6,7,8,9, 10,11,12,13,14 };
	int B[5][3] = { 0,1,2,3,4, 5,6,7,8,9, 10,11,12,13,14 };
	int C[3][3];
	int D[9] = { 8,1,3,7,6,8,11,9,17 };
	float sum = floatsum(D,0, 9);
	pick(A, 3, 5);
	//printf("sum = %f", sum);
}