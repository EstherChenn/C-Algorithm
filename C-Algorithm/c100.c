#include <stdio.h>
#include <math.h>

//1. ��дһ���������������������ֵ
int c1(int a,int b,int c) {
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	return  max;
}

//2. ����10�����������������һ����
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

//3. �ж�2000-2500���е����꣬�����
void c3() {
	int i;
	printf("run nian:");
	for (i = 2000; i <= 2500; i++) {
		if (i % 400 == 0) {
			printf("%d \n", i);
		}
	}
}

//4. ��дһ��������1+2+3+...+100��ֵ
void c4() {
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		sum += i;
	}
	printf("1+2+3+...+100 = %d \n", sum);
}

//5. ��дһ��������1��-��1/2��+��1/3��-...+��1/99��-��1/100����ֵ
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

//6. �ж�һ�����ܷ�ͬʱ��3��5����
void c6() {
	int a, i;
	printf("please input a number:\n");
	scanf_s("%d", &a);
	if (a % 3 == 0 && a % 5 == 0) {
		printf("%d��ͬʱ��3��5����\n", a);
	}
	else {
		printf("%d����ͬʱ��3��5����\n", a);
	}
}

//7. ������n��Ԫ�ص�����a�������մ�С�������򲢴Ӵ�С���
void c7() {
	//��������
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

//8. ��дһ�����򽫴�д��ĸת����Сд��ĸ
void c8() {
	char s;
	printf("please inout a daxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'A' || s>'Z') {
		printf("���벻Ϊ��д��ĸ\n");
	}
	else {
		s = s + ('a' - 'A');
	}
	printf("%c de xiaoxiezimu : %c\n", s,s);
}

//9. ��дһ������Сд��ĸת���ɴ�д��ĸ
void c9() {
	char s, k;
	printf("please inout a xiaoxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'a' || s>'z') {
		printf("���벻ΪСд��ĸ\n");
	}
	else {
		s = s - ('a' - 'A');
	}
	printf("%c de daxiezimu : %c\n", s, s);
}

//10. �����ַ������հ�Сд���
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

//11. ���������α߳�a,b,c��������
void c11() {
	int i, p, area;
	int a, b, c;
	printf("�����������ε������ߣ�\n"); 
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if (((a + b) < c) || ((a + c) < b) || ((b + c) < a)) {
		printf("����߲�����������\n");
	}
	else {
		p = (a + b + c) / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("area = %d\n", area);
	}
}

//12. ���������������������������
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

//13. �����򽫡�China���������


//14. ����һ���ٷ��Ƴɼ���Ҫ������ɼ��ȼ�A,B,C,D,E��90������ΪA��80-90��ΪB��70-79��ΪC��60-69��ΪD��60������ΪE

//15. ���2��N���ݣ�1��2��4��8��..һֱ��2^N

//16. ��д�����ж�һ�����Ƿ�Ϊ����

//17. ���2-300�������

//18. ��2+22+222+2222+...����5��

//19. ���1��+2��+3��+4��+...��ֵ

//20. ��Ȼ����e=2.718281828...���ֱ����e��e�ļ��㹫ʽΪe=1+1/1��+1/2��+1/3��+...��Ҫ�����һ���ֵС��10^(-10)ʱ����


int main() { 
	struct Point p;
	pointInit(p);
	printf("%d\n", p.x);
}