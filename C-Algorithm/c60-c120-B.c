#include <stdio.h>
#include <math.h>
#define maxsize 100

//61. 求两个数最大公约数和最小公倍数
int max(int n, int m) {
	int i, max = 1;
	int state = 1;
	while (state == 1) {
		state = 0;
		for (i = 2; i < n; i++) {
			if ((n % i == 0) && (m % i == 0)) {
				//若有公因子，令state=1
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
	printf("请输入a:\n");
	scanf_s("%d", &a);
	printf("请输入b:\n");
	scanf_s("%d", &b);
	//最大公约数
	m = max(a, b);
	//最小公倍数
	n = a * b / m;
	printf("最大公约数为： %d\n", m);
	printf("最小公倍数为： %d\n", n);
}

//62.在字符串中的所有数字字符前加一个$字符
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

//63. 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少
//【是否有其它解法】
void c63() {
	int n = 1, i, j;
	int state = 0;
	i = sqrt(n + 100);
	j = sqrt(n + 168);
	while (state != 1) {
		if ((i * i == n + 100) && (j * j == n + 168)) {
			state = 1;
			printf("该数是：%d\n", n);
		}
		else {
			n++;
			i = sqrt(n + 100);
			j = sqrt(n + 168);
		}
	}
}

//64. 质因数分解将一个正整数分解质因数（例如：输入90，打印出90=2*3*3*5）
void c64() {
	int n, j;
	printf("请输入一个正整数：\n");
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

//65. 自由落体求高度问题
void c65() {
	double height = 100, sumHeight = 0;
	int i, j;
	for (i = 1; i <= 10; i++) {
		sumHeight += height;
		height /= 2;
	}
	printf("第10次落地时，共经过%f米，第10次反弹%f米高\n", sumHeight, height);
}

//66. 求3000以内的亲密数（A的全部因子之和等于B，B同理）
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
		//求a的全部因子之和b
		b = yzsum(a);
		c = yzsum(b);
		if (b == c && a < b) {
			printf("%d 和 %d 是亲密数\n",a,b);
		}
	}
}

//67. 使用递归逆序输出输入的5个字符
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

//68. 猜年龄问题
void c68() {
	int age = 10, i;
	for (i = 1; i < 5; i++) {
		age += 2;
	}
	printf("第五个人 %d 岁\n", age);
}

//69. 写一个递归程序求具有n个元素的整型数组R的和
int sum = 0;
int c69(int *R,int n) {
	if (n == 0) {
		return R[0];
	}
	return (R[n-1] + c69(R, n - 1));
}

//70. 写一个递归程序求具有n个元素的整型数组R中最大值
double c70(double* R, int n) {
	double max;
	if (n == 0)
		return R[0];
	return (max = R[n - 1] > c70(R, n - 1) ? R[n - 1] : c70(R, n - 1));
}

//71. 写一个递归程序求具有n个元素的整型数组R的平均值
double c71(int *R,int n) {
	if (n == 1)
		return R[0] ; 
	return (R[n - 1] + c71(R, n - 1)) / 2.0;
}

//72. 给一个不多于5位的正整数，要求：一，求它是几位数，二，逆序打印出各位数字
void c72() {
	int n, i = 0, j;
	int a[5];
	printf("请输入一个不多于5位的正整数：\n");
	scanf_s("%d", &n);
	while (n != 0) {
		a[i] = n % 10; 
		n = n / 10;
		i++;
	} 
	printf("是%d位数！\n", i);
	for (j = 0; j < i; j++) {
		printf("%d", a[j]);

	} 
	printf("\n");
}
//73. 编写一个递归程序输入一个非负整数，返回组成它的数字之和
int c73(int a) {
	if (a == 0)
		return 0;
	return (a % 10) + c73(a / 10) ;
}

//74. 有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数
void c74() {
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int i, m = 3, index, j, k;
	for (i = 0, j = 9; i < 3; i++) {
		index = a[j]; 
		//前8位数后移1位
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

//75. 三天打鱼两天晒网问题
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
	//判断闰年
	if ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) {
		sum += 1;
	}
	sum += date1.day;
	int tag = sum % 5;
	if (tag >= 1 && tag <= 3) {
		printf("打鱼\n");
	}
	else {
		printf("晒网\n");
	}
}

//76. 编程实现八进制转换为十进制
void c76() {
	int a, i = 0, j = 0;
	printf("请输入一个八进制数：\n");
	scanf_s("%d", &a);
	while (a != 0) {
		j += ((a % 10) * pow(8, i));
		a = a / 10;
		i++;
	}
	printf("result : %d\n",j);

}

//77. 有两个磁盘文件A和B，各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排序），输出到一个新文件C中

//78. 结构体数据的文件写入问题

//79. 验证哥德巴赫猜想（2000以内的不小于4的正偶数都能够分解为两个素数之和）
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

//80. 用1，2，3，4共4个数字能组成多少个互不相同且无重复数字的三位数？都是多少？
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
	printf("总共有%d位数\n", count);
}

//81. 约瑟夫环问题
void c81() {
	int a[maxsize];
	int n, m, i, j, k, count;
	printf("请输入人数：\n");
	scanf_s("%d", &n);
	printf("请输入报数上限值：\n");
	scanf_s("%d", &m);
	//为所有数值赋值
	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	//令出列人数为n
	count = n;
	i = 1;
	while (count != 0) {
		k = m * i % n;
		if (a[k-1] != 0) {
			printf("编号为%d的人出列\n", a[k - 1]);
			a[k-1] = 0;
		}
		else {
			while (a[k - 1] == 0) {
				k = (k + 1) % n;
			}
			printf("编号为%d的人出列\n", a[k - 1]);
		}
		count--;
		i++;
		printf("目前剩下%d个人\n\n", count);
	}
}

//82.狼抓兔子问题
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
			printf("兔子可能在第%d个洞里\n", i + 1);
	}

}

//84. 马克思手稿中的数学题
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

//84.爱因斯坦台阶问题
void c84() {
	int N;
	int i, j;
	printf("请输入N;\n");
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++) {
		if ((i % 2 == 1) && (i % 3 == 2) && (i % 5 == 4) && (i % 6 == 5) && (i % 7 == 0))
			printf("%d\n", i);
	}
}

//85. 牛顿迭代法求方程根
void c85() {
	float a, b, c, d;
	float x0, x = 1.5, f, fd, h;
	printf("请输入a b c d：\n");
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

//86. 枚举排列组合
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

//87.乒乓球问题

//88. 换分币问题（将5元的人民币换成1元，5角和1角的硬币，共有多少种不同的兑换方法

//89. 百钱买百鸡问题（鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁，母，雏各几何？）



int main() {
	c86();
	return 0;
}