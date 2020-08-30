#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxsize 100

//61. �����������Լ������С������
int max(int n, int m) {
	int i, max = 1;
	int state = 1;
	while (state == 1) {
		state = 0;
		for (i = 2; i < n; i++) {
			if ((n % i == 0) && (m % i == 0)) {
				//���й����ӣ���state=1
				state = 1;
				max *= i;
				n = n / i;
				m = m / i;
				break;
			}
		}
	}
	max *= (m * n);
	return max;
}
void c61() {
	int a, b;
	int m, n;
	printf("������a:\n");
	scanf_s("%d", &a);
	printf("������b:\n");
	scanf_s("%d", &b);
	//���Լ��
	m = max(a, b);
	//��С������
	n = a * b / m;
	printf("���Լ��Ϊ�� %d\n", m);
	printf("��С������Ϊ�� %d\n", n);
}

//62.���ַ����е����������ַ�ǰ��һ��$�ַ�
void c62() {
	char ch;
	while ((ch = getchar()) != "\n") {
		if (ch >= '0' && ch <= '9') {
			printf("$");
		}
		printf("%c", ch);
	}
	printf("\n");
}

//63. һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ���
//���Ƿ��������ⷨ��
void c63() {
	int n = 1, i, j;
	int state = 0;
	i = sqrt(n + 100);
	j = sqrt(n + 168);
	while (state != 1) {
		if ((i * i == n + 100) && (j * j == n + 168)) {
			state = 1;
			printf("�����ǣ�%d\n", n);
		}
		else {
			n++;
			i = sqrt(n + 100);
			j = sqrt(n + 168);
		}
	}
}

//64. �������ֽ⽫һ���������ֽ������������磺����90����ӡ��90=2*3*3*5��
void c64() {
	int n, j;
	printf("������һ����������\n");
	scanf_s("%d", &n);
	printf("%d = ", n);
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
}

//65. ����������߶�����
void c65() {
	double height = 100, sumHeight = 0;
	int i, j;
	for (i = 1; i <= 10; i++) {
		sumHeight += height;
		height /= 2;
	}
	printf("��10�����ʱ��������%f�ף���10�η���%f�׸�\n", sumHeight, height);
}

//66. ��3000���ڵ���������A��ȫ������֮�͵���B��Bͬ��
int yzsum(int x) {
	int i, sum = 0;
	for (i = 1; i < x; i++) {
		if (x % i == 0) {
			sum += (x / i); 
		}
	}
	return sum;
}
void c66() {
	int a, b, c;
	int i, j;
	for (a = 1; a <= 20; a++) {
		//��a��ȫ������֮��b
		b = yzsum(a);
		c = yzsum(b);
		if (b == c && a < b) {
			printf("%d �� %d ��������\n",a,b);
		}
	}
}

//67. ʹ�õݹ�������������5���ַ�
void c67(int n) { 
	char ch;
	if (n <= 1) {
		ch = getchar();
		putchar(ch);
	}
	else {
		ch = getchar();
		c67(n - 1);
		putchar(ch);
	} 
}

//68. ����������
void c68() {
	int age = 10, i;
	for (i = 1; i < 5; i++) {
		age += 2;
	}
	printf("������� %d ��\n", age);
}

//69. дһ���ݹ���������n��Ԫ�ص���������R�ĺ�
int sum = 0;
int c69(int *R,int n) {
	if (n == 0) {
		return R[0];
	}
	return (R[n-1] + c69(R, n - 1));
}

//70. дһ���ݹ���������n��Ԫ�ص���������R�����ֵ
double c70(double* R, int n) {
	double max;
	if (n == 0)
		return R[0];
	return (max = R[n - 1] > c70(R, n - 1) ? R[n - 1] : c70(R, n - 1));
}

//71. дһ���ݹ���������n��Ԫ�ص���������R��ƽ��ֵ
double c71(int *R,int n) {
	if (n == 1)
		return R[0] ; 
	return (R[n - 1] + c71(R, n - 1)) / 2.0;
}

//72. ��һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ����
void c72() {
	int n, i = 0, j;
	int a[5];
	printf("������һ��������5λ����������\n");
	scanf_s("%d", &n);
	while (n != 0) {
		a[i] = n % 10; 
		n = n / 10;
		i++;
	} 
	printf("��%dλ����\n", i);
	for (j = 0; j < i; j++) {
		printf("%d", a[j]);

	} 
	printf("\n");
}
//73. ��дһ���ݹ��������һ���Ǹ����������������������֮��
int c73(int a) {
	if (a == 0)
		return 0;
	return (a % 10) + c73(a / 10) ;
}

//74. ��n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m����
void c74() {
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int i, m = 3, index, j, k;
	for (i = 0, j = 9; i < 3; i++) {
		index = a[j]; 
		//ǰ8λ������1λ
		for (k = 9; k > 0; k--) { 
			a[k] = a[k-1]; 
		}
		a[0] = index;  
	}
	printf("result:\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//75. �����������ɹ������
typedef struct date {
	int year;
	int month;
	int day;
}date;
void c75() {
	struct date date1 = {2024,5,6};
	int rn_tag, sum, i;
	int monthd[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	rn_tag = (date1.year - 2019) / 4;
	sum = (date1.year - 2019 - rn_tag) * 365 + rn_tag * 366;
	for (i = 0; i < date1.month; i++) {
		sum += monthd[i];
	}
	//�ж�����
	if ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) {
		sum += 1;
	}
	sum += date1.day;
	int tag = sum % 5;
	if (tag >= 1 && tag <= 3) {
		printf("����\n");
	}
	else {
		printf("ɹ��\n");
	}
}

//76. ���ʵ�ְ˽���ת��Ϊʮ����
void c76() {
	int a, i = 0, j = 0;
	printf("������һ���˽�������\n");
	scanf_s("%d", &a);
	while (a != 0) {
		j += ((a % 10) * pow(8, i));
		a = a / 10;
		i++;
	}
	printf("result : %d\n",j);

}

//77. �����������ļ�A��B�������һ����ĸ��Ҫ����������ļ��е���Ϣ�ϲ�������ĸ˳�����򣩣������һ�����ļ�C��

//78. �ṹ�����ݵ��ļ�д������

//79. ��֤��°ͺղ��루2000���ڵĲ�С��4����ż�����ܹ��ֽ�Ϊ��������֮�ͣ�
int su(int n) {
	int j;
	int state = 1;
	for (j = 2; j < n; j++) {
		if (n % j == 0)
			return 0;
	}
	if (state == 1) { 
		return 1;
	}
}
void c79() {
	int n, i, ok;
	while (scanf_s("%d", &n) != EOF) {
		ok = 0;
		for (i = 2; i <= n / 2; i++) {
			if (su(i)) {
				if (su(n - i)) {
					printf("%d %d\n", i, n - i);
					ok = 1;
				}
			}
			if (i != 2)
				i++;
			if (ok)
				break;
		}
	} 
}

//80. ��1��2��3��4��4����������ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
void c80() {
	int a[4] = { 1,2,3,4 };
	int i, j, k, num, count = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if (i != j && i != k && j != k) {
					num = a[i] * 100 + a[j] * 10 + a[k];
					count++;
					printf("%d\n", num);
				}
			}
		}
	}
	printf("�ܹ���%dλ��\n", count);
}

//81. Լɪ������
void c81() {
	int a[maxsize];
	int n, m, i, j, k, count;
	printf("������������\n");
	scanf_s("%d", &n);
	printf("�����뱨������ֵ��\n");
	scanf_s("%d", &m);
	//Ϊ������ֵ��ֵ
	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	//���������Ϊn
	count = n;
	i = 1;
	while (count != 0) {
		k = m * i % n;
		if (a[k-1] != 0) {
			printf("���Ϊ%d���˳���\n", a[k - 1]);
			a[k-1] = 0;
		}
		else {
			while (a[k - 1] == 0) {
				k = (k + 1) % n;
			}
			printf("���Ϊ%d���˳���\n", a[k - 1]);
		}
		count--;
		i++;
		printf("Ŀǰʣ��%d����\n\n", count);
	}
}

//82.��ץ��������
void c82() {
	int i, j;
	int pos[10] = { 0 };
	int lang = 0;
	for (i = 0, j = 2; i < 10; i++, j++) {
		pos[lang] = 1;
		//printf("lang = %d\n", lang);
		lang += j;
		lang = lang%10;
	}
	for (i = 0; i < 10; i++) {
		if (pos[i] == 0)
			printf("���ӿ����ڵ�%d������\n", i + 1);
	}

}

//84. ���˼�ָ��е���ѧ��
void c83() {
	int i, j, k;
	int sum;
	for (i = 1; i < 28; i++) {
		for (j = 1; j < 28; j++) {
			for (k = 1; k < 28; k++) {
				if ((i + j + k) == 30) {
					if (3 * i + 2 * j + k == 50)
						printf("i = %d\n j = %d\n k = %d\n\n",i,j,k);
				}
			}
		}
	}
}

//84.����˹̨̹������
void c84() {
	int N;
	int i, j;
	printf("������N;\n");
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++) {
		if ((i % 2 == 1) && (i % 3 == 2) && (i % 5 == 4) && (i % 6 == 5) && (i % 7 == 0))
			printf("%d\n", i);
	}
}

//85. ţ�ٵ������󷽳̸�
void c85() {
	float a, b, c, d;
	float x0, x = 1.5, f, fd, h;
	printf("������a b c d��\n");
	scanf_s("%f %f %f %f", &a, &b, &c, &d);
	do {
		x0 = x;
		f = a * x0 * x0 * x0 + b * x0 * x0 + c * x0 + d;
		fd = 3 * a * x0 * x0 + 2 * b * x0 + c;
		h = f / fd;
		x = x0 - h;
	} while (fabs(x - x0) >= 1e-5);
	printf("x = %f", x);
}

//86. ö���������
void c86() {
	char str[] = { 'a','b','c' ,'d' ,'e' ,'f','g' };
	int n, i, j, k;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			for (k = 0; k < 7; k++) {
				if ((i != j) && (i != k) && (j != k)) {
					printf("%c %c %c\n", str[i], str[k], str[k]);
				}
			}
		}
	}
}

//87.ƹ��������
void c87() {
	char jia[3] = { 'a','b','c' };
	char yi[3] = { 'x','y','z' };
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((jia[i] == 'a' && yi[j] == 'x') || (jia[i] == 'c' && yi[j] == 'x') || (jia[i] == 'c' && yi[j] == 'z')) {
				
			}
			else {
				printf("%c VS %c\n", jia[i], yi[j]);
			}
		}
	}
}

//88. ���ֱ����⣨��5Ԫ������һ���1Ԫ��5�Ǻ�1�ǵ�Ӳ�ң����ж����ֲ�ͬ�Ķһ�����
void c88() {
	int i, j, k;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 10; j++) {
			for (k = 1; k < 50; k++) {
				if (i + 0.5 * j + 0.1 * k == 5) {
					printf("%d %d %d\n", i, j, k);
				}
			}
		}
	}
}

//89. ��Ǯ��ټ����⣨����һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̣�ĸ���������Σ���
void c89() {
	int x, y, z;
	for (x = 1; x <= 100; x++) {
		for (y = 1; y <= 100; y++) {
			for (z = 1; z <= 100; z++) {
				if ((5 * x + 3 * y + z / 3 == 100) && (z % 3 == 0) && (x + y + z == 100)) {
					printf("%d %d %d\n", x, y, z);
				}
			}
		}
	}
}

//90. ��д����ʵ�����±���ʾ��5-ħ���� ��δ��֤��
void c90() {
	int a[5][5];
	int i = 0, j = 2, k, b;
	a[0][2] = 1;
	k = 2;
	for (k = 2; k < 25; k++) {
		if (i == 0) {
			i = 4;
			j = j + 1;
			a[i][j] = k;
			printf("a[%d][%d] = %d\n", i, j, k);
		}
		else if (j + 1 > 4) {
			i = i - 1;
			j = 0;
			a[i][j] = k;
			printf("a[%d][%d] = %d\n", i, j, k);
		}
		else if ((k-1) % 5 == 0) {
			i = i + 1;
			j = j;
			a[i][j] = k;
			printf("a[%d][%d] = %d\n", i, j, k);
		}
		else{
			i = i - 1;
			j = j + 1;
			a[i][j] = k;
			printf("a[%d][%d] = %d\n", i, j, k);
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

//91. ��0-7��������ɵ���������
void c91() {
	int sum = 4, s = 4;
	int j;
	for (j = 2; j <= 8; j++) {
		printf("\n%d", sum);
		if (j <= 2)
			s *= 7;
		else
			s *= 8;
		sum += s;
	}
	printf("\nsum=%d", sum);
}

//92. ��������
void c92() {
	char color[] = { 'R','W', 'B', 'W', 'W', 'B', 'R', 'B', 'W', 'R', '\0' };
	char temp;
	int w = 0, b = 0;
	int r = strlen(color) - 1;
	printf("strlen(color) = %d\n\n", strlen(color));
	int i;
	for (i = 0; i < strlen(color); i++)
		printf("%c ", color[i]);
	printf("\n\n");
	while (w <= r) {
		if (color[w] == 'W')
			w++;
		else {
			if (color[w] == 'B') {
				temp = color[b];
				color[b] = color[w];
				color[w] = temp;
				b++;
				w++;
			}
			else {
				//�Ӻ���ǰ�ҵ���һ�����Ǻ����λ��
				while (w < r && color[r] == 'R') {
					r--;
				}
				temp = color[r];
				color[r] = color[w];
				color[w] = temp;
				r--;
			}
		}
		printf("b = %d | w = %d | r = %d\n", b, w, r);
		for (i = 0; i < strlen(color); i++)
			printf("%c ", color[i]);
		printf("\n");
	}
	printf("\nResult:\n");
	for (i = 0; i < strlen(color); i++)
		printf("%c ", color[i]);
	printf("\n");
}

//93. ���ӳ�������
void c93() {
	int x1,x2 = 1, i;
	for (i = 0; i < 9; i++) {
		x1 = (x2 + 1) * 2;
		x2 = x1;
	}
	printf("sum = %d\n", x1);
}

//94. ��ڶ���
int maxof3(int a) {
	int i = 0 , j, max,min, s[maxsize];
	int max_tag, min_tag, mid_tag;
	while (a != 0) {
		s[i] = a % 10;
		a = a / 10;
		i++;
	}
	max = s[0];
	min = s[0];
	max_tag = 0;
	min_tag = 0;
	for (j = 0; j < 3; j++) {
		if (max < s[j]) {
			max = s[j];
			max_tag = j;
		}
		if (min > s[j]) {
			min = s[j];
			min_tag = j;
		}
	}
	for (j = 0; j < 3; j++) {
		if (j != max_tag && j != min_tag)
			mid_tag = j;
	}
	max = s[max_tag] * 100 + s[mid_tag] * 10 + s[min_tag];
	printf("max = %d\n", max);
	return max;
}
int minof3(int a) {
	int i = 0, j, max, min, s[maxsize];
	int max_tag, min_tag, mid_tag;
	while (a != 0) {
		s[i] = a % 10;
		a = a / 10;
		i++;
	}
	max = s[0];
	min = s[0];
	max_tag = 0;
	min_tag = 0;
	for (j = 0; j < 3; j++) {
		if (max < s[j]) {
			max = s[j];
			max_tag = j;
		}
		if (min > s[j]) {
			min = s[j];
			min_tag = j;
		}
	}
	for (j = 0; j < 3; j++) {
		if (j != max_tag && j != min_tag)
			mid_tag = j;
	}
	min = s[min_tag] * 100 + s[mid_tag] * 10 + s[max_tag];
	printf("min = %d\n\n", min);
	return min;
}
void c94() {
	int a, m,n,max,min;
	printf("������һ����λ����\n");
	scanf_s("%d", &a);
	max = maxof3(a);
	min = minof3(a);
	m = max - min; 
	max = maxof3(m);
	min = minof3(m);
	n = max - min; 
	while (m != n) {
		m = n;
		max = maxof3(m);
		min = minof3(m);
		n = max - min;
	}
	if (m == n)
		printf("�ڶ���Ϊ��%d\n", m);
}

//95. ��������1
int fish(int n, int x) {
	if ((x - 1) % 5 == 0) {
		if (n == 1)
			return 1;
		else
			return fish(n - 1, (x - 1) / 5 * 4);
	}
	return 0;
}
void c95() {
	int i = 0, flag = 0, x;
	do {
		i = i + 1;
		x = i * 5 + 1;
		if (fish(5, x)) {
			flag = 1;
			printf("����˺ϻﲶ����������Ϊ%d\n", x);
		}
	} while (!flag);
}

//96. ��������2


//97. ������˳�������г����з�ĸΪ40������С��40��������
void c97() {
	int i, j, num;
	int state;
	for (i = 1; i < 40; i++) {
		state = 1;
		//��ĸ������Ƿ��й�Լ��
		for (j = 2; j <= i; j++) {
			if (i % j == 0 && 40 % j == 0) {
				//�й�Լ��
				state = 0;
				break;
			}
		}
		if (state == 1) {
			printf("%d / 40\n", i);
		}
	}
}

//98. ������ת���⣨��дһ��4*4�����������ʱ����ת90�Ⱥ����
void c98() {
	int a[4][4] = { 1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4 };
	int b[4][4];
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			b[3 - j][i] = a[i][j];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}


//99. ��ɫ��ץȡ����
void c99() {
	int a, b, c;
	int count = 0;
	printf("�� �� ��\n");
	for (a = 1; a <= 4; a++) {
		for (b = 1; b <= 2; b++) {
			for (c = 1; c <= 6; c++) {
				if (a + b + c == 8) {
					//��������
					printf("%d  %d  %d\n", a, b, c);
					count++;
				}
			}
		}
	}
	printf("����%d�ֿ��ܵ���ɫ����\n",count);
}

//100. ������ֽ�Ϊ��������
void c100() {
	int a, b, i, j;
	printf("�����������\n");
	scanf_s("%d/%d", &a, &b);
	//���ĸ��

}

//101. �ݹ���쳲���������n��
int c101(int n) {
	if (n < 2)
		return 1;
	return (c101(n - 1) + c101(n - 2));
}

//102. ����һ������ֵ�����ַ�����ʹ�õݹ����ת��Ϊ�ַ�����ӡ��
char c102() {

}

//103. ������ܶ���ʽ
int c103(int n,int x) {
	if (n <= 0)
		return 1;
	else if (n == 1)
		return 2 * x;
	else
		return (2 * x * c103(n - 1, x) - 2 * (n - 1) * c103(n - 2, x));
}

int main() {
	//c99();
	printf("%d\n", c103(3,2));
	return 0;
}