#include <stdio.h>
#include <math.h>
//#include <stdlib.h>

#define maxsize 100

//定义栈的结构体
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

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
	printf("run nian:\n");
	for (i = 2000; i <= 2500; i++) {
		if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
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
	int a;
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
	for (i = 9; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	for (j = 9; j >= 0; j--) {
		printf("%d ", a[j]);
	}
	printf("\n");
}

//8. 编写一个程序将大写字母转换成小写字母
void c8() {
	char s, s1;
	printf("please inout a daxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'A' || s>'Z') {
		printf("输入不为大写字母\n");
	}
	else {
		s1 = s + ('a' - 'A');
	}
	printf("%c de xiaoxiezimu : %c\n", s, s1);
}

//9. 编写一个程序将小写字母转换成大写字母
void c9() {
	char s, s1;
	printf("please inout a xiaoxiezimu:\n");
	scanf_s("%c", &s);
	if (s < 'a' || s>'z') {
		printf("输入不为小写字母\n");
	}
	else {
		s1 = s - ('a' - 'A');
	}
	printf("%c de daxiezimu : %c\n", s, s1);
}

//10. 输入字符，最终按小写输出 
void c10() {
	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch + ('a' - 'A');
			printf("%c", ch);
		}
		else {
			printf("%c", ch);
		}
		/*ch = (ch >= 'A' && ch <= 'Z') ? (ch + ('a' - 'A')) : ch;
		printf("%c", ch);*/
	}
}

//11. 给出三角形边长a,b,c计算出面积
void c11() {
	int a, b, c;
	float area, s;
	printf("请输入三角形的三条边：\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if (((a + b) < c) || ((a + c) < b) || ((b + c) < a)) {
		printf("输入边不构成三角形\n");
	}
	else {
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));;
		printf("area = %f\n", area);
	}
}

//12. 给出三角形三个点坐标计算出面积
typedef struct Point {
	int x;
	int y;
}Point;
void c12() {
	struct Point p0 = { 0,3 };
	struct Point p1 = { 0,0 };
	struct Point p2 = { 0,4 };
	double area = 0;
	area = abs(p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p0.x * p2.y - p1.x * p0.y - p2.x * p1.y);
	area = area / 2;
	printf("area = %f\n", area);
}

//13. 请编程序将“China”译成密码
void c13() {
	char c[] = { 'C','h','i','n','a' };
	int i;
	printf("putchar:\n");
	for (i = 0; i < 5; i++) {
		c[i] = c[i] + 4;
		putchar(c[i]);
	}
	printf("\n");
	printf("printf:\n");
	for (i = 0; i < 5; i++) {
		c[i] = c[i] - 4;
	}
	for (i = 0; i < 5; i++) {
		c[i] = c[i] + 4;
	};
	for (i = 0; i < 5; i++) {
		printf("%c", c[i]);
	}
	printf("\n");
}

//14. 给出一个百分制成绩，要求输出成绩等级A,B,C,D,E。90分以上为A，80-90分为B，70-79分为C，60-69分为D，60分以下为E
void c14(int grade) {
	int i;
	if (grade > 100 || grade < 0)
		printf("输入成绩格式错误\n");
	switch (grade / 10) {
	case(10):
		printf("成绩为A\n");
		break;
	case(9):
		printf("成绩为A\n");
		break;
	case(8):
		printf("成绩为B\n");
		break;
	case(7):
		printf("成绩为C\n");
		break;
	case(6):
		printf("成绩为D\n");
		break;
	default:
		printf("成绩为E\n");
		break;
	}
}

//15. 输出2的N次幂：1，2，4，8，..一直到2^N
void c15() {
	int N, sum, i, j;
	printf("请输入N：\n");
	scanf_s("%d", &N);
	sum = 0;
	j = 1;
	for (i = 0; i <= N; i++) {
		printf("2的%d次幂 = %d\n",i,j);
		j *= 2;
	}
}

//16. 编写程序判断一个数是否为素数
int c16(int a) {
	int i; 
	for (i = 2; i < a; i++) {
		if (a % i == 0) { 
			printf("%d不是素数\n",a);
			return 0;
		}			
	}
	printf("%d是素数\n", a);
	return 1;
}

//17. 输出2-300间的素数
void c17() {
	int i;
	for (i = 2; i <= 300; i++) {
		if (c16(i) == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//18. 求2+22+222+2222+...，共5项
void c18() {
	int i, sum = 0, s;
	s = 2;
	for (i = 1; i <= 5; i++) {
		sum += s;
		s = s * 10 + 2;
	}
	printf("2+22+222+2222+... = %d\n", sum);
}

//19. 编程1！+2！+3！+4！+...的值
float c19(int n) {
	int i, j, m;
	float  sum = 0;
	/*printf("请输入n：\n");
	scanf_s("%d", &n);*/
	m = 1;
	for (i = 1; i <= n; i++) {
		sum += m;
		m *= (i+1);
	}
	printf("1！+2！+3！+4！+...+%d！ = %f\n", n, sum);
	return sum;
}

//20. 自然底数e=2.718281828...，现编程求e，e的计算公式为e=1+1/1！+1/2！+1/3！+...，要求当最后一项的值小于10^(-10)时结束
void c20() {
	int i = 1;
	float e = 1;
	float n = 1, k = 1;
	while (1 / n > 1e-10) {
		e += (1 / n);
		i++;
		n *= i;
	}
	printf("e = %f\n", e);
}

//21. 求1000以内的所有回文素数(从左读与从右读相同）[可以用队列？]
void c21() {
	int n;
	int i;
	for (n = 10; n <= 1000; n++) { 
		//两位数
		if ((n % 10 == n / 10) && (n / 100 == 0))
			printf("%d \n", n);
		//三位数
		if ((n % 10 == n / 100) && (n / 100 != 0))
			printf("%d \n", n);
		
	}
}

//22. 在数组中插入元素（现有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中）
void c22() {
	int a[10] = { 1,4,5,6,8,10,14,16,20,23 };
	int n, i, index;
	printf("请输入一个数：\n");
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

//23. 求序列：2/1，3/2，5/3，8/5，13/8,21/13...的前20项之和
void c23() {
	int k;
	float i = 1, j = 2, sum = 0, n;
	for (k = 0; k < 20; k++) {
		n = j;
		j = i + j;
		i = n;
		sum += (j / i);
	}
	printf("sum = %f\n", sum);
}

//24. 使用二维数组将一个3*4的矩阵中所有元素的最大值及其下标获取----------------是否有更优解
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

//25. 编写程序实现矩阵转置
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

//26. 求3乘3矩阵对角线元素之和【已验证】
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

//27. 求水仙花数（153=1^3+5^3+3^3）【已验证】
void c27() {
	double sum = 0;
	int n, i = 0,  j;
	printf("请输入一个数：\n");
	scanf_s("%d", &n);
	int a = n % 10;
	int b = n / 10 % 10;
	int c = n / 100;
	//sum = a * a * a + b * b * b + c * c * c;
	sum = pow(n % 10, 3) + pow(n / 10 % 10, 3) + pow(n / 100, 3);
	if (n == sum) {
		printf("%d是水仙花数\n", n);
	}
	else {
		printf("%d不是水仙花数\n", n);
	}
}

//28. 求出前面20个Fibonacci数列F(n)=F(n-1)+F(n-2)（n>=2)【已验证】
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


//29. 生兔子问题【已验证】
void c29() {
	int n, i, j, k, sum = 0;
	int F[maxsize];
	F[0] = 0;
	F[1] = 1;
	printf("请输入月份：\n");
	scanf_s("%d", &n);
	for (k = 2; k <= n; k++) {
		F[k] = F[k - 1] + F[k - 2];
	}
	printf("all = %d\n", F[n]);
}

//30. 输入一行英文句子，统计单词数【已验证】
void c30() {
	int i = 0;
	char c;
	printf("请输入：\n");
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			i++;
		}
	}
	printf("共有%d个单词\n", i + 1);
}

//31. 加密解密（将字符串中每个字符偏移量 = ascii + 在字符串的位置 + 5）
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

//32. 逆序输出存储整数的数组(将一个从键盘输入的整数存于一个数组中，
//通过程序的运行按数组中的逆序输出该整数，利用递归的方法解决问题)
int i = 0;
int c32(char s[], int n) {
	int i;
	if ((i = n / 10) != 0)
		c32(s + 1, i);
	*s = n % 10 + '0';
	return 0;
}

//33. 将一个一维数组就地逆置
void c33() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int k, i;
	for (i = 0; i < 5; i++) {
		k = a[i];
		a[i] = a[9 - i];
		a[9 - i] = k;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//34. 数据加密（四位的整数，每位数字都加5，然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换）
void c34() {
	int a;
	int i, index;
	printf("请输入 一个四位数的整数：\n");
	scanf_s("%d", &a);
	index = ((a % 10 + 5) % 10 * 1000) + ((a / 10 % 10 + 5) % 10 * 100)
		+ ((a / 100 % 10 + 5) % 10 * 10) + ((a / 1000 + 5) % 10);
	printf("result : %d\n", index);
}

//35. 输出菱形
void c35() {
	int i, j, n;
	printf("请输入菱形的层数：\n");
	scanf_s("%d", &n);
	
}

//36. 求2-300范围内完数的个数(这个数巧合等于它的因子之和，除了本身外)
void c36() {
	int n, i, sum;
	printf("2-300范围内完数:\n");
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

//37. 求3-1000孪生素数（相邻的两个素数）
void c37() {
	int n, i, index;
	int a[maxsize], k = 0;
	for (n = 3; n <= 1000; n++) {
		index = 1;
		//判断素数
		for (i = 2; i < n; i++) {
			if (n % i == 0)
				index = 0;
		}
		if (index == 1) {
			a[k] = n;
			k++;
		}
	}
	printf("\nresult:\n");
	for (i = 0; i < k; i++) {
		if (a[i + 1] - a[i] == 2) {
			printf("%d 和 %d 是孪生素数\n", a[i], a[i + 1]);
		}
	}
}

//38. 求回文数
void c38() {
	int m[16], n, i, t, count = 0;
	long unsigned a, k;
	printf("No. number it's square(palindrome)\n");
	for (n = 1; n < 256; n++) {
		k = 0;
		t = 1;
		a = n * n;
		for (i = 0; a != 0; i++) {
			m[i] = a % 10;
			a /= 10;
		}
		for (; i > 0; i--) {
			k += m[i - 1] * t;
			t *= 10;
		}
		if (k == n * n)
			printf("%2d%10d%10d\n", ++count, n, n * n);
	}
}

//39. 判断一个五位数是否是回文数
void c39() {
	int n, i;
	printf("请输入一个五位数：\n");
	scanf_s("%d", &n); 
	if ((n % 10 == n / 10000) && (n / 10 % 10 == n / 1000 % 10)) {
		printf("%d 是回文数\n",n);
	}
}

//40. 求100以内的所有勾股数
void c40() {
	int i, j, k;
	int n, m;
	for (i = 1; i < 100; i++) {
		for (j = i; i < 100; i++) {
			n = i * i;
			m = j * j;
			k = (int)sqrt(n + m);
			if ((j + k < i) && (i + j < k) && (j + k < i) && k * k == i * i + j * j && k <= 100) {
				printf("%d %d %d是勾股数\n", i, j, k);
			}
		}
	}
}

//41. 输入一个字符串，判断其是否为回文
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
			printf("不是回文\n");
			break;
		}
	}
	if (index == 1) {
		printf("是回文\n");
	}
}

//42. 删除字符串中间的*号
void c42() {
	char ch[maxsize];
	char c;
	int i = 0, j, k;
	printf("请输入字符串：\n");
	while ((c = getchar()) != '\n') {
		ch[i] = c;
		i++;
	}
	int len = i;
	printf("\n");
	for (i = 0; i < len; i++)
		printf("%c", ch[i]);
	printf("\n");
	for (j = 1; j < i - 1; j++) {
		if (ch[j] == '*') {
			if (ch[j - 1] > 'A' && ch[j - 1] < 'Z') {
				if (ch[j + 1] > 'A' && ch[j + 1] < 'Z') {
					//左移
					for (k = j; k < len - 1; k++) {
						ch[k] = ch[k + 1];
					}
					len--;
				}
			}
		}
	}
	for (i = 0; i < len; i++)
		printf("%c", ch[i]);
	printf("\n");
}

//43. 实现函数strlen
int c43(char* string) {
	int i = 0;
	int length = 0;
	while (string[i] != '\0') {
		length += 1;
		printf("%c's length = %d\n", string[i], length);
		i++;
	}
	printf("length = %d\n", length);
	return length;
}

//44. 实现函数atoi
int c44(char* s) {
	int i = 1, n;
	while (s[i] != '/0') {
		n += (s[i] - '0') * i;
		i *= 10;
	}
	printf("result = %d \n", n);
	return n;
}

//45. 实现函数itoa
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

//46. 实现函数strcat
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

//47. 实现函数strncat
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

//48. 实现函数strcpy
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

//49. 实现函数strncpy
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

//50. 实现函数strcmp
int c50(const char* s, const char* t) {
	int i = 0, j = 0, k;
	while (s[i] != '/0' || t[j] != '/0') {
		if (s[i] != t[j]) {
			printf("两字符串不等\n");
			return 0;
		}
		i++;
		j++;
	}
	if (s[i] != '/0' || t[j] != '/0') {
		printf("两字符串不等\n");
		return 0;
	}
	printf("两字符串相等\n");
	return 1;
}

//51. 实现函数strncmp
int strncmp(const char* s, const char* t, int count) {
	int i = 0, j = 0, k;
	while ((s[i] != '/0' || t[j] != '/0') || count != 0) {
		if (s[i] != t[j]) {
			printf("两字符串不等\n");
			return 0;
		}
		i++;
		j++;
		count--;
	} 
	printf("两字符串相等\n");
	return 1;
}

//52. 利用梯形法计算定积分f(a->b)(x^3+3*x^2-x+2)dx
void c52(int a,int b) {
	float n, r;
	int i;
	n = (b - a) / ;
}

//53. 编程计算空间上任意两点之间的距离
void c53() {
	struct Point p1 = {1,2,3};
	struct Point p2 = { 3,4,5 };
	int dis;
	dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
	printf("distance = %d\n", dis);
}

//54. 日期运算问题
typedef struct date {
	int year;
	int month;
	int day;
};
void c54() {
	//计算某一天是对应年的第几天
	struct date date1 = { 2020,3,8 };
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0, i;
	for (i = 0; i < date1.month; i++) {
		sum += day[i];
		if (i == 2) {
			if (date1.year % 400 == 0 || (date1.year % 4 == 0 && date1.year % 100 != 0))
				//闰年
				sum += 1;
		}
	}
	sum += date1.day;
	printf("是对应年的第%d天\n", sum);
}

//55. 统计各字符个数（输入一行字符，分别统计其中，英文字母，空格，数字和其它字符的个数）
void c55() {
	char ch;
	int yw_num = 0, kg_num = 0, sz_num = 0, qt_num = 0;
	printf("请输入：\n");
	while ((ch = getchar() != '\n')) {
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			//英文字母
			yw_num++;
		}
		else if ((ch == ' ')) {
			//空格
			kg_num++;
		}
		else if ((ch >= '0') && (ch <= '9')) {
			//数字
			sz_num++;
		}
		else {
			//其它字符
			qt_num++;
		}
	}
	printf("英文：%d\n", yw_num);
	printf("空格：%d\n", kg_num);
	printf("数字：%d\n", sz_num);
	printf("其它字符：%d\n", qt_num);
}

//56. 统计文件的字符数,单词数以及总行数
void c56() {
	FILE* fp;
	char ch;
	int zf_num = 0, dc_num = 1, hang_num = 0;
	if (fp = fopen("E:\1.txt", 'r') == NULL) {
		printf("打开文件失败\n");
	}
	//while (ch = fgets(fp) != EOF) {
	//	if (ch >= 0 && ch <= 127)
	//		//字符
	//		zf_num++;
	//	if (ch == " ")
	//		//空格
	//		dc_num++;
	//	if (ch == '\n')
	//		//行数
	//		hang_num++;
	//}
	printf("字符：%d\n", zf_num);
	printf("空格：%d\n", dc_num);
	printf("行数：%d\n", hang_num);
}

//57. 统计英文字母，空格，数字和其它字符的数目
void c57() {
//	c55();
}

//58. 大小写转换并输入到文件保存
void c58() {
	FILE* fp;
	char ch;
	if (fp = fopen("", 'w') == NULL) {
		printf("文件打开失败\n");
	}
	else {
		printf("请输入内容：\n");
		/*while ((ch = getchar()) != '\n') {
			if ((ch > 'a') && (ch < 'z')) {
				ch = ch + 'A' - 'a';
			}
			if (ch > 'A' && ch < 'Z') {
				ch = ch - ('A' - 'a');
			}
			printf("%c ", ch);
			fscanf_s(fp, "%c", ch);
		}
		printf("\n");
		fscanf_s(fp, "%c", ' ');*/
	}
	fclose(fp);
}

//59. 利用递归方法求5！
int sum = 1;
int c59(int k) {
	if (k == 1)
		return 1;
	else {
		sum = sum * c59(k - 1);
	}
	printf("%d 时,sum = %d", k, sum);
}

//60. 输入三个字符串，将其按照从小到大排序并输出
void c60() {
	char ch1[maxsize], ch2[maxsize], ch3[maxsize];
	int i = 0, j = 0, k = 0;
	printf("请输入第一个字符串：\n");
	while (ch1[i] = getchar() != "\n") {
		i++;
	}
	printf("请输入第二个字符串：\n");
	while (ch2[j] = getchar() != "\n") {
		j++;
	}
	printf("请输入第三个字符串：\n");
	while (ch3[k] = getchar() != "\n") {
		k++;
	}


}


int main() { 
	printf("max = %d\n",c1(3,6,1));
	return 0;
}