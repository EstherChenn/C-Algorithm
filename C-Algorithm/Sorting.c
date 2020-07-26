#include <stdio.h>


/**
	第8章 排序
*/

//直接插入排序
void DirectInsertionSorting(int R[],int length, int trem) {
	;
	int i,j,tag=0;
	printf("请输入插入的数值：");
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

//折半插入排序
void BinaryInsertionSort(int R[], int n,int trem) {
	int low,high,mid,m;
	int i; 
	low = 0;
	high = n - 1;
	mid = n / 2;
	//确定插入位置
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
	//将数值插入
	for (i = n; i > m; i--) {
		R[i] = R[i - 1];
	}
	R[m] = trem;
	for (i = 0; i <= n; i++) {
		printf("%d ", R[i]);
	}
	printf("\n");
}

//冒泡排序
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

//快速排序

//简单选择排序

//堆排序

//二路归并排序

//基数排序


int main() {
	int a[5] = { 10,56,78,5,6};
	//int length = sizeof(a) / sizeof(a[0]);
	//printf("length = %d \n "+ length);
	BubbleSort(a, 5);
	return 0;
}