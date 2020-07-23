#include <stdio.h>

/**
	第8章 图
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



int main() {
	int a[6] = { 1,4,7,9,11,14 };
	DirectInsertionSorting(a, 6,8);
	return 0;
}