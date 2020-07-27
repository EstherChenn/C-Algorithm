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
void QuickSort(int R[], int low,int high) {
	int i = low, j = high;
	int temp;
	if (low < high) {
		temp = R[low];
		while (i < j) {
			while (i < j && R[j] >= temp) {
				--j;
			}
			if (i < j) {
				R[i] = R[j];
				++i;
			}
			while (i < j && R[i] < temp) {
				++i;
			}
			if (i < j) {
				R[j] = R[i];
				--j;
			}
		}
		R[i] = temp;
		QuickSort(R, low, i - 1);
		QuickSort(R,i + 1, high);
	 }
}

//简单选择排序
void SelectSort(int R[], int n) {
	int i, j, s;
	int min, tag = 0;
	for (i = 0; i < n; i++) {
		min = R[i + 1];
		//找出i之后的最小值
		for (j = i + 1; j < n; j++) { 
			if (min > R[j]) {
				min = R[j];
				tag = j;
			}
		}
		//判断如果i之后的最小值小于R[i]，则交换
		if (R[i] > min) {
			s = R[i];
			R[i] = R[tag];
			R[tag] = s;
			tag = 0;
		}
	}
}

//堆排序


//二路归并排序


//基数排序



int main() {
	int a[5] = { 10,56,78,5,6};
	//int length = sizeof(a) / sizeof(a[0]);
	//printf("length = %d \n "+ length);
	SelectSort(a, 5);
	int k;
	for (k = 0; k < 5; k++) {
		printf("%d ", a[k]);
	}
	return 0;
}