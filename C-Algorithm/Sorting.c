#include <stdio.h>


/**
	��8�� ����
*/

//ֱ�Ӳ�������
void DirectInsertionSorting(int R[],int length, int trem) {
	;
	int i,j,tag=0;
	printf("������������ֵ��");
	//scanf( "%d", &trem);
	for (i = 0; i < length; i++) {
		if (trem < R[i]) {
			for (j = length; j >i; j--) {
				R[j] = R[j - 1];
			}
			R[i] = trem;
			tag = 1;
			break;
		}
	}
	if (tag == 0) {
		R[length] = trem;
	}
	for (i = 0; i <= length; i++) {
		printf("%d ", R[i]);
	}
}

//�۰��������
void BinaryInsertionSort(int R[], int n,int trem) {
	int low,high,mid,m;
	int i; 
	low = 0;
	high = n - 1;
	mid = n / 2;
	//ȷ������λ��
	while (low <= high) {
		printf("mid = %d \n", mid);
		if (trem > R[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	m = mid ;
	//����ֵ����
	for (i = n; i > m; i--) {
		R[i] = R[i - 1];
	}
	R[m] = trem;
	for (i = 0; i <= n; i++) {
		printf("%d ", R[i]);
	}
	printf("\n");
}

//ð������
void BubbleSort(int R[],int n) {
	int i,j, s;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n-i; j++) {
			if (R[j] > R[j+1]) {
				s = R[j];
				R[j] = R[j + 1];
				R[j + 1] = s;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", R[i]);
	}
}

//��������

//��ѡ������

//������

//��·�鲢����

//��������


int main() {
	int a[5] = { 10,56,78,5,6};
	//int length = sizeof(a) / sizeof(a[0]);
	//printf("length = %d \n "+ length);
	BubbleSort(a, 5);
	return 0;
}