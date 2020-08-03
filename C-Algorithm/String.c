#include <stdio.h>

#define maxsize 5

//串的数据结构
//定长顺序存储
typedef struct {
	char str[maxsize + 1];
	int length;
}Str1;
//变长分配存储
typedef struct {
	char* ch;
	int length;
}Str2;

//赋值操作(将一个常量字符串赋值给str)
int strassign(Str2 *str,char *ch) {
	int i;
	int len = 0;
	//释放原串长度
	/*if (str->ch)
		free(str->ch);*/
	//求ch的长度
	while (*ch) {
		len++;
		ch++;
	} 
	//判断ch是否为空
	if (len == 0) {
		str->ch = NULL;
		str->length = 0;
		return 1;
	}
	else {
		//取len+1的目的在于为了多分配一个空间存放‘/0’字符
		str->ch = (char*)malloc(sizeof(char) * (len + 1));
		if (str->ch == NULL)
			return 0;
		else {
			//c = ch;
			for (i = 0; i <= len; i++) {
				str->ch[i] = *ch;
				ch++; 
			}
			str->length = len;
			/*for (i = 0; i <= len; i++) {
				printf("str = %c \n", str->ch[i]);
			}*/
			return 1;
		}
	}
}

//取串长度操作
int strlenth(Str2 *str) {
	return str->length;
}

//串比较操作(若S>T，则返回值大于0；若S<T,则返回值<0；若S=T，则返回值=0)
int strcompare(Str2 *str1,Str2 *str2) {
	//1：str1>str2		2:str1<str2		0:str1=str2
	int i, j;
	int len1, len2;
	len1 = strlenth(&str1);
	len2 = strlenth(&str2);
		//若长度相等，则进行内容比较
		for (i = 0; i < len1 && i < len2; i++) {
			if (str1->ch[i] != str2->ch[i]) {
			//	printf("str1 - str2 = %d\n", str1->ch[i] - str2->ch[i]);
				return str1->ch[i] - str2->ch[i];
			}
		}
		 
}

//串连接操作（将两个串首位相接）
int contact(Str2* str1, Str2* str2,Str2 *str) {
	int len1, len2, i, j;
	len1 = str1->length;
	len2 = strlenth(str2); 
	str->ch = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	str->length = len1+len2;
	if (str->ch == NULL)
		return 0;
	for (i = 0; i < len1; i++) {
		str->ch[i] = str1->ch[i]; 
	}
	for (i = len1,j=0; i <= len1 + len2; i++,j++) {
		str->ch[i] = str2->ch[j]; 
	}
	for (i = 0; i <= str->length; i++) {
		printf("%c ", str->ch[i]);
	} 
	printf("len1 = %d", str->length);
}


//求子串操作（求从给定串中的某一位置到某一结束位置的串）
int concat(Str2 *str,Str2 *substr,int pos,int len) {
	int i,j;
	if (str->ch == NULL || pos<0 || len<=0 || pos>str->length || len>str->length - pos) {
		return 0;
	}
	substr->ch = (char*)malloc(sizeof(char) * (len + 1)); 
	for (i = pos,j = 0; i < len; i++,j++) {
		substr->ch[j] = str->ch[i];
	}
	substr->ch[len + 1] = '\0';
	substr->length = len;
	printf("结果是：\n");
	for (i = 0; i < len; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}


//串清空操作
void substring(Str2 *str) {
	if (str->ch) {
		free(str->ch);
		str->ch = NULL;
	}
	str->length = 0;
}

//简单模式匹配算法
int index(Str2 *str, Str2 *substr) {
	int i, j; 
	int index;
	int sublen;
	if (str->ch == NULL)
		return 0;   
	for (i = 0; i < str->length; i++) { 
		j = 0;
		sublen = substr->length;
		index = i;
		//如果剩下未匹配的字符串长度小于substr的长度，则失败
		if (substr->length > (str->length - (i + 1))) {
			return 0;
		}
		while (str->ch[i] == substr->ch[j] && sublen != 0) {
			i++;
			j++;
			sublen--;
		}
		if (sublen == 0) {
			printf("匹配成功！\n");
			printf("模式串在主串中的位置是：%d\n", index);
			return index;
		}
	} 
}

//KMP算法
//计算F数组（[i]表示的是前i的字符组成的这个子串最长的相同前缀后缀的长度！）
int F(Str2 *str) {
	int i,j; 
	int len;
	len = str->length;
	int f[len - 1], b[len - 1];
	//计算前缀
	for (i = 0; i < len - 1; i++) {
		for (j = len; j < i + 1; j--) {

		}
	}
}

//1.1 将串str中所有值为ch1的字符转换成ch2的字符，如果str为空串，或者串中不含值为ch1的字符，则什么都不做
int exchange(Str2 *str, char ch1, char ch2) {
	int i;
	if (str->length == 0) {
		return 0;
	}
	for (i = 0; i < str->length; i++) {
		if (str->ch[i] == ch1) {
			str->ch[i] = ch2;
		}
	}
	for (i = 0; i < str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}

//1.2 实现串str的逆转函数，如果str为空串，则什么都不做
int vert(Str2* str) {
	int i,j;
	char tag;
	if (str->length == 0) {
		return 0;
	}
	for (i = 0, j = str->length-1; i < str->length / 2; i++,j-- ) {
		tag = str->ch[i];
		str->ch[i] = str->ch[j];
		str->ch[j] = tag;
	}
	for (i = 0; i < str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}

//1.3 删除str中值为ch的所有字符，如果str为空串，或者串中不含值为ch的字符，则什么都不做
int del(Str2* str, char ch) {
	int i,j; 
	if (str->length == 0) {
		return 0;
	}
	for (i = 0; i < str->length; i++) {
		if (str->ch[i] == ch) {
			//左移一位数
			for (j = i; j < str->length - 1; j++) {
				str->ch[j] = str->ch[j + 1];
				str->length -= 1;
			}
		}
	}
	printf("slen = %d\n", str->length);
	for (i = 0; i < str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}

// 1.4 从串str中的pos位置起，求出与substr串匹配的子串的位置，如果str为空串，或者串中不含与substr匹配的子串，则返回-1做标记
int pipei(Str2* str, Str2* substr, int pos) {
	int i,j ,k;
	if (str->length == 0) {
		return -1;
	}
	for (i = pos; i < str->length; i++) {
		//同简单匹配算法
	}
	printf("slen = %d\n", str->length);
	for (i = 0; i < str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}

//2. 采用定长顺序存储表示串，编写一个函数，删除串中从下标i到下标j之间的字符（包括i和j两个位置上的字符）用str2串替换
void change(Str1 str, Str1 str2, int i, int j) {
	int k = 0;
	for (i; i <= j; i++) {
		str.str[i] = str2.str[k];
	}
}

//3. 采用顺序存储方式存储串，编写一个函数，将串str1中的下标i到下标j之间的字符（包括i和j两个位置上的字符）用str2串替换


//4. 编写一个函数，计算一个子串在一个主串中出现的次数，如果该子串不出现，则返回0。（本题不需要考虑子串重叠，如：主串为aaaa，
//子串为aaa,考虑子串重叠结果为2，不考虑子串重叠结果为1


//5. 构造串的链表结点数据结构（每个结点内存储一个字符），编写一个函数，找出串str1中第一个不在str2中出现的字符




int main() {
	Str2 str;
	Str2 str1;
	Str2 str2;
	str1.ch = "abceff";
	str2.ch = "bce";
	str1.length = 6;
	str2.length = 3;
	int i,j;
	//strassign(&str1, "abceff");
	//strassign(&str2, "abce");
	printf("result = %d \n", index(&str1, &str2));
	return 0;
}