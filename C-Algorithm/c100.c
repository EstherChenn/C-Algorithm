#include <stdio.h>
#include <math.h>

#define maxsize 100

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
	struct Point p1 = { 1,2,3 };
	struct Point p2 = { 1,2,3 };
	struct Point p3 = { 1,2,3 }; 
	int area;
	area = abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y) / 2;
	printf("area = %d\n", area);
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
	printf("printf:\n");
	for (i = 0; i < 5; i++) {
		c[i] = c[i] + 4; 
	}
	printf("%s", c);
}

//14. 给出一个百分制成绩，要求输出成绩等级A,B,C,D,E。90分以上为A，80-90分为B，70-79分为C，60-69分为D，60分以下为E
void c14(int grade) {
	int i;
	if (grade > 100 || grade < 0)
		printf("输入成绩格式错误\n");
	switch (grade / 10) {
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
	float n = c19(i);
	while (n > pow(10, (-10))) {
		e += (1 / n);
		n = c19(i + 1);
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

//23. 求序列：2/1，3/2，5/3，8/5，13/8/21/13...的前20项之和
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

//32. 逆序输出存储整数的数组

//33. 将一个一维数组就地逆置

//34. 数据加密（四位的整数，每位数字都加5，然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换）

//35. 输出菱形

//36. 求2-300范围内完数的个数

//37. 求孪生素数（相邻的两个素数）

//38. 求回文数

//39. 判断一个五位数是否是回文数

//40. 求100以内的所有勾股数

//41. 输入一个字符串，判断其是否为回文

//42. 删除字符串中间的*号

//43. 实现函数strlen

//44. 实现函数atoi

//45. 实现函数itoa

//46. 实现函数strcat

//47. 实现函数strncat

//48. 实现函数strcpy

//49. 实现函数strncpy

//50. 实现函数strcmp

//51. 实现函数strncmp


int main() { 
	c26();
	return 0;
}