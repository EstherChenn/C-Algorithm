#include <stdio.h>

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
		scanf("%d", &a[i]);
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
	scanf("%d", &a);
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

//8. ��дһ�����򽫴�д��ĸת����Сд��ĸ
void c8() {
	char s, k;
	printf("please inout a daxiezimu:\n");
	scanf("%c", &s);
	if (s < 'A' || s>'Z') {
		printf("���벻Ϊ��д��ĸ\n");
	}
	else {
		s = s + ('a' - 'A');
	}
	printf("%d de xiaoxiezimu : %d\n", s, k);
}

//9. ��дһ������Сд��ĸת���ɴ�д��ĸ
void c9() {
	char s, k;
	printf("please inout a xiaoxiezimu:\n");
	scanf("%c", &s);
	if (s < 'a' || s>'z') {
		printf("���벻ΪСд��ĸ\n");
	}
	else {
		s = s - ('a' - 'A');
	}
	printf("%d de daxiezimu : %d\n", s, k);
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

int main() {

}