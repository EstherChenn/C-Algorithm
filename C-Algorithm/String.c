#include <stdio.h>

#define maxsize 5

//�������ݽṹ
//����˳��洢
typedef struct {
	char str[maxsize + 1];
	int length;
}Str1;
//�䳤����洢
typedef struct {
	char* ch;
	int length;
}Str2;

//��ֵ����(��һ�������ַ�����ֵ��str)
int strassign(Str2 *str,char *ch) {
	int i;
	int len = 0;
	//�ͷ�ԭ������
	/*if (str->ch)
		free(str->ch);*/
	//��ch�ĳ���
	while (*ch) {
		len++;
		ch++;
	} 
	//�ж�ch�Ƿ�Ϊ��
	if (len == 0) {
		str->ch = NULL;
		str->length = 0;
		return 1;
	}
	else {
		//ȡlen+1��Ŀ������Ϊ�˶����һ���ռ��š�/0���ַ�
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

//ȡ�����Ȳ���
int strlenth(Str2 *str) {
	return str->length;
}

//���Ƚϲ���(��S>T���򷵻�ֵ����0����S<T,�򷵻�ֵ<0����S=T���򷵻�ֵ=0)
int strcompare(Str2 *str1,Str2 *str2) {
	//1��str1>str2		2:str1<str2		0:str1=str2
	int i, j;
	int len1, len2;
	len1 = strlenth(&str1);
	len2 = strlenth(&str2);
		//��������ȣ���������ݱȽ�
		for (i = 0; i < len1 && i < len2; i++) {
			if (str1->ch[i] != str2->ch[i]) {
			//	printf("str1 - str2 = %d\n", str1->ch[i] - str2->ch[i]);
				return str1->ch[i] - str2->ch[i];
			}
		}
		 
}

//�����Ӳ���������������λ��ӣ�
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


//���Ӵ���������Ӹ������е�ĳһλ�õ�ĳһ����λ�õĴ���
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
	printf("����ǣ�\n");
	for (i = 0; i < len; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}


//����ղ���
void substring(Str2 *str) {
	if (str->ch) {
		free(str->ch);
		str->ch = NULL;
	}
	str->length = 0;
}

//��ģʽƥ���㷨
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
		//���ʣ��δƥ����ַ�������С��substr�ĳ��ȣ���ʧ��
		if (substr->length > (str->length - (i + 1))) {
			return 0;
		}
		while (str->ch[i] == substr->ch[j] && sublen != 0) {
			i++;
			j++;
			sublen--;
		}
		if (sublen == 0) {
			printf("ƥ��ɹ���\n");
			printf("ģʽ���������е�λ���ǣ�%d\n", index);
			return index;
		}
	} 
}

//KMP�㷨
//����F���飨[i]��ʾ����ǰi���ַ���ɵ�����Ӵ������ͬǰ׺��׺�ĳ��ȣ���
int F(Str2 *str) {
	int i,j; 
	int len;
	len = str->length;
	int f[len - 1], b[len - 1];
	//����ǰ׺
	for (i = 0; i < len - 1; i++) {
		for (j = len; j < i + 1; j--) {

		}
	}
}

//1.1 ����str������ֵΪch1���ַ�ת����ch2���ַ������strΪ�մ������ߴ��в���ֵΪch1���ַ�����ʲô������
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

//1.2 ʵ�ִ�str����ת���������strΪ�մ�����ʲô������
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

//1.3 ɾ��str��ֵΪch�������ַ������strΪ�մ������ߴ��в���ֵΪch���ַ�����ʲô������
int del(Str2* str, char ch) {
	int i,j; 
	if (str->length == 0) {
		return 0;
	}
	for (i = 0; i < str->length; i++) {
		if (str->ch[i] == ch) {
			//����һλ��
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

// 1.4 �Ӵ�str�е�posλ���������substr��ƥ����Ӵ���λ�ã����strΪ�մ������ߴ��в�����substrƥ����Ӵ����򷵻�-1�����
int pipei(Str2* str, Str2* substr, int pos) {
	int i,j ,k;
	if (str->length == 0) {
		return -1;
	}
	for (i = pos; i < str->length; i++) {
		//ͬ��ƥ���㷨
	}
	printf("slen = %d\n", str->length);
	for (i = 0; i < str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
	return 1;
}

//2. ���ö���˳��洢��ʾ������дһ��������ɾ�����д��±�i���±�j֮����ַ�������i��j����λ���ϵ��ַ�����str2���滻
void change(Str1 str, Str1 str2, int i, int j) {
	int k = 0;
	for (i; i <= j; i++) {
		str.str[i] = str2.str[k];
	}
}

//3. ����˳��洢��ʽ�洢������дһ������������str1�е��±�i���±�j֮����ַ�������i��j����λ���ϵ��ַ�����str2���滻


//4. ��дһ������������һ���Ӵ���һ�������г��ֵĴ�����������Ӵ������֣��򷵻�0�������ⲻ��Ҫ�����Ӵ��ص����磺����Ϊaaaa��
//�Ӵ�Ϊaaa,�����Ӵ��ص����Ϊ2���������Ӵ��ص����Ϊ1


//5. ���촮�����������ݽṹ��ÿ������ڴ洢һ���ַ�������дһ���������ҳ���str1�е�һ������str2�г��ֵ��ַ�




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