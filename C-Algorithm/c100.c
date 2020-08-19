#include <stdio.h>
#include <math.h>

#define maxsize 100

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
	struct Point p1 = { 1,2,3 };
	struct Point p2 = { 1,2,3 };
	struct Point p3 = { 1,2,3 }; 
	int area;
	area = abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y) / 2;
	printf("area = %d\n", area);
}

//13. �����򽫡�China���������
void c13() {
	char c[] = { 'C','h','i','n','a' }; 
	int i;
	printf("putchar:\n");
	for (i = 0; i < 5; i++) {
		c[i] = c[i] + 4;
		putchar(c[i]);
	}
	printf("printf:\n");
	for (i = 0; i < 5; i++) {
		c[i] = c[i] + 4; 
	}
	printf("%s", c);
}

//14. ����һ���ٷ��Ƴɼ���Ҫ������ɼ��ȼ�A,B,C,D,E��90������ΪA��80-90��ΪB��70-79��ΪC��60-69��ΪD��60������ΪE
void c14(int grade) {
	int i;
	if (grade > 100 || grade < 0)
		printf("����ɼ���ʽ����\n");
	switch (grade / 10) {
	case(9):
		printf("�ɼ�ΪA\n");
		break;
	case(8):
		printf("�ɼ�ΪB\n");
		break;
	case(7):
		printf("�ɼ�ΪC\n");
		break;
	case(6):
		printf("�ɼ�ΪD\n");
		break;
	default:
		printf("�ɼ�ΪE\n");
		break;
	}
}

//15. ���2��N���ݣ�1��2��4��8��..һֱ��2^N
void c15() {
	int N, sum, i, j;
	printf("������N��\n");
	scanf_s("%d", &N);
	sum = 0;
	j = 1;
	for (i = 0; i <= N; i++) {
		printf("2��%d���� = %d\n",i,j);
		j *= 2;
	}
}

//16. ��д�����ж�һ�����Ƿ�Ϊ����
int c16(int a) {
	int i; 
	for (i = 2; i < a; i++) {
		if (a % i == 0) { 
			printf("%d��������\n",a);
			return 0;
		}			
	}
	printf("%d������\n", a);
	return 1;
}

//17. ���2-300�������
void c17() {
	int i;
	for (i = 2; i <= 300; i++) {
		if (c16(i) == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//18. ��2+22+222+2222+...����5��
void c18() {
	int i, sum = 0, s;
	s = 2;
	for (i = 1; i <= 5; i++) {
		sum += s;
		s = s * 10 + 2;
	}
	printf("2+22+222+2222+... = %d\n", sum);
}

//19. ���1��+2��+3��+4��+...��ֵ
float c19(int n) {
	int i, j, m;
	float  sum = 0;
	/*printf("������n��\n");
	scanf_s("%d", &n);*/
	m = 1;
	for (i = 1; i <= n; i++) {
		sum += m;
		m *= (i+1);
	}
	printf("1��+2��+3��+4��+...+%d�� = %f\n", n, sum);
	return sum;
}


//20. ��Ȼ����e=2.718281828...���ֱ����e��e�ļ��㹫ʽΪe=1+1/1��+1/2��+1/3��+...��Ҫ�����һ���ֵС��10^(-10)ʱ����
void c20() {
	int i = 1;
	float e = 1;
	float n = c19(i);
	while (n > pow(10, (-10))) {
		e += (1 / n);
		n = c19(i + 1);
	}
	printf("e = %f\n", e);
}

//21. ��1000���ڵ����л�������(���������Ҷ���ͬ��[�����ö��У�]
void c21() {
	int n;
	int i;
	for (n = 10; n <= 1000; n++) { 
		//��λ��
		if ((n % 10 == n / 10) && (n / 100 == 0))
			printf("%d \n", n);
		//��λ��
		if ((n % 10 == n / 100) && (n / 100 != 0))
			printf("%d \n", n);
		
	}
}

//22. �������в���Ԫ�أ�����һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ������������У�
void c22() {
	int a[10] = { 1,4,5,6,8,10,14,16,20,23 };
	int n, i, index;
	printf("������һ������\n");
	scanf_s("%d", &n);
	for (i = 0; i < 10; i++) {
		if (a[i] > n) {
			index = i;
			break;
		}
	}
	for (i = 10; i > index; i--) {
		a[i] = a[i - 1];
	}
	a[index] = n;
	for (i = 0; i < 11; i++) {
		printf("%d ", a[i]);
	}
}

//23. �����У�2/1��3/2��5/3��8/5��13/8/21/13...��ǰ20��֮��
void c23() {
	int i = 1, j = 2, k, n;
	float sum = j / i;
	for (k = 0; k < 20; k++) {
		n = j;
		j = i + j;
		i = n;
		sum += (j / i);
	}
	printf("sum = %f", sum);
}

//24. ʹ�ö�ά���齫һ��3*4�ľ���������Ԫ�ص����ֵ�����±��ȡ----------------�Ƿ��и��Ž�
void c24() {
	int a[3][4];
	int i, j, iindex, jindex, max;
	max = a[0][0];
	i = 0;
	j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) { 
			if (max < a[i][j]) {
				max = a[i][j];
				iindex = i;
				jindex = j;
			}
		}
	}
	printf("max = %d\n  i = %d\n   j=%d\n", max, iindex, jindex);
}

//25. ��д����ʵ�־���ת��
void c25() {
	int a[3][3];
	int b[3][3];
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			b[i][j] = a[j][i];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

//26. ��3��3����Խ���Ԫ��֮�͡�����֤��
void c26() {
	int sum, i, j;
	int a[3][3] = { 1,2,3, 4,5,6, 7,8,9 };
	sum = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((i == j) || (i + j == 2))
				sum += a[i][j];
		}
	}
	printf("sum = %d\n", sum);
}

//27. ��ˮ�ɻ�����153=1^3+5^3+3^3��������֤��
void c27() {
	double sum = 0;
	int n, i = 0,  j;
	printf("������һ������\n");
	scanf_s("%d", &n);
	int a = n % 10;
	int b = n / 10 % 10;
	int c = n / 100;
	//sum = a * a * a + b * b * b + c * c * c;
	sum = pow(n % 10, 3) + pow(n / 10 % 10, 3) + pow(n / 100, 3);
	if (n == sum) {
		printf("%d��ˮ�ɻ���\n", n);
	}
	else {
		printf("%d����ˮ�ɻ���\n", n);
	}
}

//28. ���ǰ��20��Fibonacci����F(n)=F(n-1)+F(n-2)��n>=2)������֤��
void c28() {
	int i, sum = 0;
	int F[20];
	F[0] = 0;
	F[1] = 1;
	for (i = 2; i < 20; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}
	for (i = 2; i < 20; i++) {
		printf("%d ", F[i]);
	}
	printf("\n");
}


//29. ���������⡾����֤��
void c29() {
	int n, i, j, k, sum = 0;
	int F[maxsize];
	F[0] = 0;
	F[1] = 1;
	printf("�������·ݣ�\n");
	scanf_s("%d", &n);
	for (k = 2; k <= n; k++) {
		F[k] = F[k - 1] + F[k - 2];
	}
	printf("all = %d\n", F[n]);
}

//30. ����һ��Ӣ�ľ��ӣ�ͳ�Ƶ�����������֤��
void c30() {
	int i = 0;
	char c;
	printf("�����룺\n");
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			i++;
		}
	}
	printf("����%d������\n", i + 1);
}

//31. ���ܽ��ܣ����ַ�����ÿ���ַ�ƫ���� = ascii + ���ַ�����λ�� + 5��
void c31() {
	int n, i, j;
	char a[maxsize];
	i = 0;
	while ((a[i] = getchar()) != '\n') {
		a[i] = a[i] + i + 5;
		i++;
	}
	for (j = 0; j <= i; j++) {
		printf("%c", a[j]);
	}
	printf("\n");
}

//32. ��������洢����������

//33. ��һ��һά����͵�����

//34. ���ݼ��ܣ���λ��������ÿλ���ֶ���5��Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������

//35. �������

//36. ��2-300��Χ�������ĸ���

//37. ���������������ڵ�����������

//38. �������

//39. �ж�һ����λ���Ƿ��ǻ�����

//40. ��100���ڵ����й�����

//41. ����һ���ַ������ж����Ƿ�Ϊ����

//42. ɾ���ַ����м��*��

//43. ʵ�ֺ���strlen

//44. ʵ�ֺ���atoi

//45. ʵ�ֺ���itoa

//46. ʵ�ֺ���strcat

//47. ʵ�ֺ���strncat

//48. ʵ�ֺ���strcpy

//49. ʵ�ֺ���strncpy

//50. ʵ�ֺ���strcmp

//51. ʵ�ֺ���strncmp


int main() { 
	c26();
	return 0;
}