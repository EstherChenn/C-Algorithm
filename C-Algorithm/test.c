#include <stdio.h>
#include<math.h> 
#define maxsize 1000

//66. ��3000���ڵ���������A��ȫ������֮�͵���B��Bͬ��
int yzsum(int n) { 
	int sum = 1;
	int  j;  
	while (n != 0) {
		for (j = 2; j < n; j++) {
			if (n % j == 0) {
				n = n / j;
				printf("%d * ", j);
				break;
			}
		}
	}
	printf("\n");
	return sum;
}
void c66() {
	int a, b, c;
	int i, j;
	b = yzsum(90);
	b = yzsum(2);
	for (a = 2; a <= 5; a++) {
		//��a��ȫ������֮��b
		b = yzsum(a);
		c = yzsum(b);
	//	printf("b = %d ,c =  %d\n", b, c);
		if (b == c) {
			printf("%d �� %d ��������\n", a, b);
		}
	}
}


int main() {
	c66();
	return 0;
}