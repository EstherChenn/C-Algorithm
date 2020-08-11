#include <stdio.h>

/**
	��8�� ����
*/

//ֱ�Ӳ�������
void DirectInsertionSorting(int R[], int length, int trem) {
	;
	int i, j, tag = 0;
	printf("������������ֵ��");
	//scanf( "%d", &trem);
	for (i = 0; i < length; i++) {
		if (trem < R[i]) {
			for (j = length; j > i; j--) {
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
void BinaryInsertionSort(int R[], int n, int trem) {
	int low, high, mid, m;
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
	m = mid;
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
void BubbleSort(int R[], int n) {
	int i, j, s;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (R[j] > R[j + 1]) {
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
void QuickSort(int R[], int low, int high) {
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
		QuickSort(R, i + 1, high);
	}
}

//��ѡ������
void SelectSort(int R[], int n) {
	int i, j, s, k;
	int min, tag;
	for (i = 0; i < n - 1; i++) {
		tag = i + 1;
		min = R[i + 1];
		//�ҳ�i֮�����Сֵ
		for (j = i + 1; j < n; j++) {
			if (R[j] < min) {
				min = R[j];
				tag = j;
			}
		}
		//�ж����i֮�����СֵС��R[i]���򽻻�
		if (min < R[i]) {
			s = R[i];
			R[i] = R[tag];
			R[tag] = s;
		}
	}
}

//������

//��·�鲢����(δ���)
/*
 * ��һ�������е�����������������ϲ���һ��
 *
 * ����˵����
 * a -- ���������������������
 * start -- ��1�������������ʼ��ַ��
 * mid   -- ��1����������Ľ�����ַ��Ҳ�ǵ�2�������������ʼ��ַ��
 * end   -- ��2����������Ľ�����ַ��
 */
void MergeSort(int a[], int start, int mid, int end) {
}

//��������
//��ȡ�����ڵ����ֵ
int get_Max(int a[], int n) {
	int i, max = a[0];
	for (i = 1; i < n; i++)
		max = a[i] > max ? a[i] : max;
	return max;
}
/*
 * �����鰴��"ĳ��λ��"��������(Ͱ����)
 *
 * ����˵����
 *     a -- ����
 *     n -- ���鳤��
 *     exp -- ָ����������a���ո�ָ����������
 *
 * ���磬��������a={50, 3, 542, 745, 2014, 154, 63, 616}��
 *    (01) ��exp=1��ʾ����"��λ"������a��������
 *    (02) ��exp=10��ʾ����"ʮλ"������a��������
 *    (03) ��exp=100��ʾ����"��λ"������a��������
 *    ...
 */
void count_sort(int a[], int n, int exp) {
	//�洢"����������"����ʱ����
	int output[10];
	int i, buckets[10] = { 0 };
	//�����ݳ��ֵĴ����洢��buckets[]��
	for (i = 0; i < n; i++) {
		buckets[(a[i] / exp) % 10]++;
	}
	//����buckets[i],Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ��
	for (i = 1; i < 10; i++) {
		buckets[i] += buckets[i - 1];
	}
	//�����ݴ洢����ʱ����output[]��
	for (i = n - 1; i >= 0; i--) {
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}
	//������ŵ����ݸ�ֵ��a[]
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

//�κ���1-3  ���һ��˫��ð�������㷨��������������н���ı�ɨ�跽��
void BubbleSort_TwoWay(int a[], int n) {
	int i, j, k;
	int trem;
	for (i = 0; i <= n / 2; i++) {
		//��ǰ����ð��
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				trem = a[j];
				a[j] = a[j + 1];
				a[j + 1] = trem;
			}
		}
		//�Ӻ���ǰð��
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

//�κ���1-5 �����и��������㷨�������� {29,18,25,47,58,12,51,10}
//�鲢����ÿ�鲢������дһ������

//��������ÿ����һ����дһ������

//�������Ƚ���һ���ѣ�д��һ�����У���Ȼ��ÿ�ӶѶ�ȡ��һ���ؼ��ֺ󣬽��ѵ���һ�Σ�ÿ�ζ�д��һ�����У���ֱ���������

//�κ���1-6 �����ؼ������У� 321, 156, 57, 46, 28, 7, 331, 33, 34, 63 ��,
//�������λ�����㷨������л�������,�г�ÿ�˷�����ռ��Ľ��

int main() {
	int k;
	int a[11] = { 10,56,78,5,5,3,2,1,0,3,6 };
	//int length = sizeof(a) / sizeof(a[0]);
	//printf("length = %d \n "+ length);

	BubbleSort_TwoWay(a, 11);

	return 0;
}