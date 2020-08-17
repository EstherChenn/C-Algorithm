#include <stdio.h>

//1. 编写一个程序求三个整数的最大值
int c1(int a,int b,int c) {
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	return  max;
}

//2. 输入10个数，并输出最大的那一个数
int c2() {
	int a[10];
	int i,max;
	printf("please input 10 num:\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (i = 1; i < 10; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}

//3. 判断2000-2500年中的闰年，并输出
void c3() {
	int i;
	printf("run nian:");
	for (i = 2000; i <= 2500; i++) {
		if (i % 400 == 0) {
			printf("%d \n", i);
		}
	}
}

//4. 编写一个程序求1+2+3+...+100的值
void c4() {
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i;
	}
	printf("1+2+3+...+100 = %d \n", sum);
}

//5. 编写一个程序求（1）-（1/2）+（1/3）-...+（1/99）-（1/100）的值
void c5() {
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 2 == 0)
			sum -= (1 / i);
		else
			sum += (1 / i);
	}
	printf("1+2+3+...+100 = %d \n", sum);
}

//6. 判断一个数能否同时被3和5整除
void c6() {
	int a, i;
	printf("please input a number:\n");
	scanf("%d", &a);
	if (a % 3 == 0 && a % 5 == 0) {
		printf("%d能同时被3和5整除\n", a);
	}
	else {
		printf("%d不能同时被3和5整除\n", a);
	}
}

//7. 将具有n个元素的数组a中数按照从小到大排序并从大到小输出
void c7() {
	//快速排序
	int a[10];
	int i, b;
	printf("please input 10 num:\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {
			if(a[i]>)
		}
	}
}

//8. 编写一个程序将大写字母转换成小写字母
void c8() {
	char s, k;
	printf("please inout a daxiezimu:\n");
	scanf("%c", &s);
	if (s < 'A' || s>'Z') {
		printf("输入不为大写字母\n");
	}
	else {
		s = s + ('a' - 'A');
	}
	printf("%d de xiaoxiezimu : %d\n", s, k);
}

//9. 编写一个程序将小写字母转换成大写字母
void c9() {
	char s, k;
	printf("please inout a xiaoxiezimu:\n");
	scanf("%c", &s);
	if (s < 'a' || s>'z') {
		printf("输入不为小写字母\n");
	}
	else {
		s = s - ('a' - 'A');
	}
	printf("%d de daxiezimu : %d\n", s, k);
}

//10. 输入字符，最终按小写输出
void c10() {
	char ch;
	while (ch = getchar()) {
		if (ch < 'a' || ch > 'z') {
			printf("%c ", ch);
		}
		else {
			printf("%c", ch + 'a' - 'A');
		}
	}
}

int main() {

}