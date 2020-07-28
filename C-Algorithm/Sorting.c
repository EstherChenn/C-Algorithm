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
/*
 * 将一个数组中的两个相邻有序区间合并成一个
 *
 * 参数说明：
 * a -- 包含两个有序区间的数组
 * start -- 第1个有序区间的起始地址。
 * mid   -- 第1个有序区间的结束地址。也是第2个有序区间的起始地址。
 * end   -- 第2个有序区间的结束地址。
 */
void MergeSort(int a[], int start,int mid,int end) {
	// tmp是汇总2个有序区的临时区域
	int* tmp = (int*)malloc((end - start + 1) * sizeof(int));
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			tmp[k++] = a[i++];
		}
		else {
			tmp[k++] = a[j++];
		}
	}
}


//基数排序
//获取数组内的最大值
int get_Max(int a[],int n) {
	int i, max = a[0];
	for (i = 1; i < n; i++)
		max = a[i] > max ? a[i] : max;
	return max;
}
/*
 * 对数组按照"某个位数"进行排序(桶排序)
 *
 * 参数说明：
 *     a -- 数组
 *     n -- 数组长度
 *     exp -- 指数。对数组a按照该指数进行排序。
 *
 * 例如，对于数组a={50, 3, 542, 745, 2014, 154, 63, 616}；
 *    (01) 当exp=1表示按照"个位"对数组a进行排序
 *    (02) 当exp=10表示按照"十位"对数组a进行排序
 *    (03) 当exp=100表示按照"百位"对数组a进行排序
 *    ...
 */
void count_sort(int a[], int n, int exp) {
	//存储"被排序数据"的临时数组
	int output[10];
	int i, buckets[10] = { 0 };
	//将数据出现的次数存储在buckets[]中
	for (i = 0; i < n; i++) {
		buckets[(a[i] / exp) % 10]++;
	}
	//更改buckets[i],目的是让更改后的buckets[i]的值，是该数据在output[]中的位置
	for (i = 1; i < 10; i++) {
		buckets[i] += buckets[i - 1];
	}
	//将数据存储到临时数组output[]中
	for (i = n - 1; i >= 0; i--) {
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}
	//将排序号的数据赋值给a[]
	for (i = 0; i < n; i++) {
		a[i] = output[i];
	}
}
void RadixSort(int a[], int n) {
	int exp;
	int max = get_Max(a, n);
	for (exp = 1; max / exp > 0; exp *= 10) {
		count_sort(a, n, exp);
	}
}

//课后题1-3  设计一个双向冒泡排序算法，即在排序过程中交替改变扫描方向
void BubbleSort_TwoWay(int a[], int n) {
	int i, j, k;
	int trem;
	for (i = 0; i < n / 2; i++) {
		//从前往后冒泡
		for (j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				trem = a[j];
				a[j] = a[j + 1];
				a[j + 1] = trem;
			}
		}
		//从后往前冒泡
		for (k = n - i - 2; k > i; k--) {
			if (a[k] < a[k - 1]) {
				trem = a[k];
				a[k] = a[k - 1];
				a[k - 1] = trem;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	int a[5] = { 10,56,78,5,6};
	//int length = sizeof(a) / sizeof(a[0]);
	//printf("length = %d \n "+ length);
	BubbleSort_TwoWay(a, 5);
	//return 0;
}