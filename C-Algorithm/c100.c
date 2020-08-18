#include <stdio.h>
#include <math.h>

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
		scanf_s("%d", &(a[i]));
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
	scanf_s("%d", &a);
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
	int i, b, j;
	printf("please input 10 num:\n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {
			 
		}
	}
}

//8. 编写一个程序将大写字母转换成小写字母
void c8() {
	char s;
	printf("please inout a daxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'A' || s>'Z') {
		printf("输入不为大写字母\n");
	}
	else {
		s = s + ('a' - 'A');
	}
	printf("%c de xiaoxiezimu : %c\n", s,s);
}

//9. 编写一个程序将小写字母转换成大写字母
void c9() {
	char s, k;
	printf("please inout a xiaoxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'a' || s>'z') {
		printf("输入不为小写字母\n");
	}
	else {
		s = s - ('a' - 'A');
	}
	printf("%c de daxiezimu : %c\n", s, s);
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

//11. 给出三角形边长a,b,c计算出面积
void c11() {
	int i, p, area;
	int a, b, c;
	printf("请输入三角形的三条边：\n"); 
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if (((a + b) < c) || ((a + c) < b) || ((b + c) < a)) {
		printf("输入边不构成三角形\n");
	}
	else {
		p = (a + b + c) / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("area = %d\n", area);
	}
}

//12. 给出三角形三个点坐标计算出面积
typedef struct Point {
	int x;
	int y;
	int z;
}Point;
void c12() {
	struct Point p1;
	struct Point p2;
	struct Point p3;
	int area;
	area = abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y) / 2;
	printf("area = %d\n", area);
}

//13. 请编程序将“China”译成密码


//14. 给出一个百分制成绩，要求输出成绩等级A,B,C,D,E。90分以上为A，80-90分为B，70-79分为C，60-69分为D，60分以下为E

//15. 输出2的N次幂：1，2，4，8，..一直到2^N

//16. 编写程序判断一个数是否为素数

//17. 输出2-300间的素数

//18. 求2+22+222+2222+...，共5项

//19. 编程1！+2！+3！+4！+...的值

//20. 自然底数e=2.718281828...，现编程求e，e的计算公式为e=1+1/1！+1/2！+1/3！+...，要求当最后一项的值小于10^(-10)时结束


int main() { 
	struct Point p;
	pointInit(p);
	printf("%d\n", p.x);
}