#include <stdio.h>
#include <math.h>

#define maxsize 100

//����ջ�Ľṹ��
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

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

//32. ��������洢����������(��һ���Ӽ����������������һ�������У�ͨ����������а������е�������������������õݹ�ķ����������)
int i = 0;
int c32(int k) {
	int a[maxsize] ;  
	if ((a[k] = getchar()) == '\n') {
		return 0;
	}
	else {
		printf("%d\n", a[k]);
		c32(k - 1);
	}
}

//33. ��һ��һά����͵�����
void c33() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k, i;
	for (i = 0; i < 5; i++) {
		k = a[i];
		a[i] = a[10 - i];
		a[10 - i] = k;
	}
	for (i = 0; i < 10; j++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//34. ���ݼ��ܣ���λ��������ÿλ���ֶ���5��Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������
void c34() {
	int a;
	int i, index;
	printf("������ һ����λ����������\n");
	scanf_s("%d", &a);
	index = (a % 10 + 5) + (a / 10 % 10 + 5) + (a / 100 % 10 + 5) + (a / 1000 + 5);
	index = index % 10;
	index = (index % 10 * 1000) + (index / 1000) + (index / 10 % 10 * 100) + (index / 100 % 10 * 10);
	printf("result : %d\n", index);
}

//35. �������
void c35() {
	int i, j, n;
	printf("���������εĲ�����\n");
	scanf_s("%d", &n);
	int k = n / 2;
	for (i = 0; i < n / 2; i++) {
		for (j = 0; j < n; j++) {
			if()
		}
	}

}

//36. ��2-300��Χ�������ĸ���(������ɺϵ�����������֮�ͣ����˱�����)
void c36() {
	int n, i, sum;
	printf("2-300��Χ������:\n");
	for (n = 2; n <= 300; n++) {
		sum = 0;
		for (i = 1; i < n; i++) {
			if (n % i == 0)
				sum += i;
		}
		if (n == sum) {
			printf("%d ", n);
		}
	}
	printf("\n");
}

//37. ��3-1000�������������ڵ�����������
void c37() {
	int n, i, index;
	int a[maxsize], k = 0;
	for (n = 3; n <= 1000; n++) {
		index = 1;
		//�ж�����
		for (i = 2; i < n; i++) {
			if (n % i == 0)
				index = 0;
		}
		if (index == 1) {
			a[k] = n;
			k++;
		}
	}
	for (i = 0; i <= k; i++) {
		if (a[i] - a[i + 1] == 2) {
			printf("%d �� %d ����������\n", a[i], a[i + 1]);
		}
	}
}
//38. �������
void c38() {
	struct LNode* st;
	struct LNode* p;
	struct LNode* p1;
	st = (LNode*)malloc(sizeof(LNode));
	st->next = NULL;
	int n, i, m, j, x;
	int s = 0, state = 1;
	for (n = 0; n < 256; n++) {
		state = 1;
		m = n * n;
		//��ÿһλ������ջ�ڣ�����������Ǽ�λ��
		while ((m / 10 != 0) ) {
			p = (LNode*)malloc(sizeof(LNode));
			p->data = m % 10;
			p->next = st->next;
			st->next = p;
			m = m / 10;
			s++;
		}
		m = n * n;
		printf("%d �� %d λ��\n ", n, s);
		for (j = s; j > s / 2; j--) {
			//��ջ
			p = st->next;
			x = st->data;
			if (x != (m % 10)) {
				state = 0;
			}
			else {
				st->next = p->next;
				m = m / 10;
			}
		}
		if (state != 0)
			printf("%d \n", n);
	}
}

//39. �ж�һ����λ���Ƿ��ǻ�����
void c38() {
	int n, i;
	printf("������һ����λ����\n");
	scanf_s("%d", &n); 
	if ((n % 10 == n / 10000) && (n / 10 % 10 == n / 1000 % 10)) {
		printf("%d �ǻ�����\n",n);
	}
}

//40. ��100���ڵ����й�����
void c40() {
	int i, j, k;
	int n;
	for (i = 1; i < 100; i++) {
		for (j = i; i < 100; i++) {
			for (k = j; k < 100; k++) {
				if ((j + k < i) || (i+j < k) || (j + k < i)) {
					//����֮��С�ڵ�����
					break;
				}
				else {
					if (i * i == (j * j + k * k)) {
						printf("%d %d %d�ǹ�����\n", i, j, k);
					}
				}
			}
		}
	}
}

//41. ����һ���ַ������ж����Ƿ�Ϊ����
void c41() {
	char ch[maxsize];
	char c;
	int i, j, k, index = 1;
	k = 0;
	while ((c = getchar()) != '\n') {
		ch[k] = c;
		k++;
	}
	for (i = 0, j = (k - 1); i<k / 2, j>k / 2; i++, j--) {
		index = 1;
		if (ch[i] != ch[j]) {
			index = 0;
			printf("���ǻ���\n");
			break;
		}
	}
	if (index == 1) {
		printf("�ǻ���\n");
	}
}

//42. ɾ���ַ����м��*��
void c42() {
	char ch[maxsize];
	char c;
	int i = 0, j, k;
	printf("�������ַ�����\n");
	while ((c = getchar()) != '\n') {
		ch[i] = c;
		i++;
	}
	int len = i;
	for (j = 1; j < i - 1; j++) {
		if (ch[j] == '*') {
			if (ch[j - 1] > 'A' && ch[j - 1] < 'Z') {
				if (ch[j + 1] > 'A' && ch[j + 1] < 'Z') {
					//����
					for (k = j; k < i-1; k++) {
						ch[k] = ch[k + 1];
						len--;
					}
				}
			}
		}
	} 
	for (i = 0; i < len; i++)
		printf("%c ", ch[i]);
	printf("\n");
}

//43. ʵ�ֺ���strlen
int c43(char *string) {
	int i = 0;
	int length = 0;
	while (string[i] != '/0') {
		length++;
		i++;
	}
	return length;
}

//44. ʵ�ֺ���atoi
int c44(char* s) {
	int i = 1, n;
	while (s[i] != '/0') {
		n += (s[i] - '0') * i;
		i *= 10;
	}
	printf("result = %d \n", n);
	return n;
}

//45. ʵ�ֺ���itoa
void c45(int n, char* s) {
	int i = 0;
	int k = 1;
	while (n / 10 != 0) {
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	for (k = 0; k < i; k++) {
		printf("%c ", s[k]);
	}
	printf("\n");
}

//46. ʵ�ֺ���strcat
char* c46(char* strDes, const char* strSrc) {
	int i = 0, j = 0, k;
	while (strDes[i] != '/0')
		i++;
	while (strSrc[j] != '/0') {
		strDes[i] = strSrc[j];
		j++;
		i++;
	}
	for (k = 0; k < i; k++) {
		printf("%c ", strDes[k]);
	}
	printf("\n");
	return strDes;
}

//47. ʵ�ֺ���strncat
char* c47(char* strDes, const char* strSrc, int count) {
	int i = 0, j = 0, k;
	while (strDes[i] != '/0')
		i++;
	while (count != 0) {
		strDes[i] = strSrc[j];
		i++; 
		j++;
	}
	for (k = 0; k < i; k++) {
		printf("%c ", strDes[k]);
	}
	printf("\n");
	return strDes;
}

//48. ʵ�ֺ���strcpy
char* c48(char* strDes, const char* strSrc) {
	int i = 0, j = 0, k;
	while (strSrc[i] != '/0') {
		strDes[j] = strSrc[j];
		i++;
		j++;
	}
	for (k = 0; k < i; k++) {
		printf("%c ", strDes[k]);
	}
	printf("\n");
	return strDes;
}

//49. ʵ�ֺ���strncpy
char* c49(char* strDes, const char* strSrc, int count) {
	int i = 0, j = 0, k;
	while (count != 0) {
		strDes[i] = strSrc[j];
		i++;
		j++;
	}
	for (k = 0; k < i; k++) {
		printf("%c ", strDes[k]);
	}
	printf("\n");
	return strDes;
}

//50. ʵ�ֺ���strcmp
int c50(const char* s, const char* t) {
	int i = 0, j = 0, k;
	while (s[i] != '/0' || t[j] != '/0') {
		if (s[i] != t[j]) {
			printf("���ַ�������\n");
			return 0;
		}
		i++;
		j++;
	}
	if (s[i] != '/0' || t[j] != '/0') {
		printf("���ַ�������\n");
		return 0;
	}
	printf("���ַ������\n");
	return 1;
}

//51. ʵ�ֺ���strncmp
int strncmp(const char* s, const char* t, int count) {
	int i = 0, j = 0, k;
	while ((s[i] != '/0' || t[j] != '/0') || count != 0) {
		if (s[i] != t[j]) {
			printf("���ַ�������\n");
			return 0;
		}
		i++;
		j++;
		count--;
	} 
	printf("���ַ������\n");
	return 1;
}

//52. �������η����㶨����f(a->b)(x^3+3*x^2-x+2)dx
void c52(int a,int b) {
	float n, r;
	int i;
	n = (b - a) / ;
}

//53. ��̼���ռ�����������֮��ľ���
void c53() {
	struct Point p1 = {1,2,3};
	struct Point p2 = { 3,4,5 };
	int dis;
	dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
	printf("distance = %d\n", dis);
}

//54. ������������
typedef struct date {
	int year;
	int month;
	int day;
};
void c54() {
	//����ĳһ���Ƕ�Ӧ��ĵڼ���
	struct date date1 = {};
	int sum = 0;
	switch (date1.month) {
		case 1:
			sum = 0;
			break;
		case 2:
			sum += 31;
	}
}

//55. ͳ�Ƹ��ַ�����

//56. ͳ���ļ����ַ���,�������Լ�������

//57. ͳ��Ӣ����ĸ���ո����ֺ������ַ�����Ŀ

//58. ��Сдת�������뵽�ļ�����

//59. ���õݹ鷽����5��

//60. ���������ַ��������䰴�մ�С�����������



int main() { 
	c26();
	return 0;
}