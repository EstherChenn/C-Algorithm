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
			c[i][j] = a[i][j] + b[i][j];
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
				printf("%d֮���ֵ��Ϊ0\n", i);
				for (k = 0; k < n; k++) {
					printf("%d ", A[k]);
				}
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
		else {
			printf("max = %d\n", max);
			return max;
		}
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
	//tag�������Ĳ����־
	int i, j, tag = 0;
	int s;
	//�ж���λ
	if (A[0] / 2 != 0) {
		tag = 1;
	}
	else {
		tag = 0;
	}
	for (i = 1; i < n; i++) {
		//�ж��Ƿ�������
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

//4. ����һԪ��Ϊ���������Ա�L�������һά����A[0��...��n-1]�У����һ���㷨����A[n-1]Ϊ�ο��������������Ϊ�����������֣�
//������벿�ֵ�Ԫ��ֵ��С�ڵ���A[n-1]���Ұ벿�ֵ�Ԫ��ֵ������A[n-1]��A[n-1]��λ����������֮�䡣Ҫ�����Դ��������A�С�


//5. ���һ���㷨���Ը�����һ������m*n����A��ͳ����������о�������������Ԫ�ظ�����������ǵ����꼰��ֵ�����Ǽ�����������
//����Сֵ�������������е���Сֵ���������Ǽ����������е����ֵ�������������е����ֵ�����������Ԫ�ظ�����ͬ��Ҫ������
//��������������������
void pick(int A[][maxsize], int m, int n) {
	int i, j, k, z;
	int min, max;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			k = 0;
			z = 0;
			min = A[i][j];
			max = A[i][j];
			//������Сֵ
			while (k < (m >  n ? m:n )) {
				if (k < m) {
					min = min < A[i][k] ? min : A[i][k];
				}
				if (k < n) {
					min = min < A[k][j] ? min : A[k][j];
				}
				k++;
			}
			//�����ֵ
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
		printf("��%d��%d�е���Сֵ�ǣ�%d�����ֵ�ǣ�%d \n", i, j, min, max);
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