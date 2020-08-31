#include <stdio.h>
#include <malloc.h>

#define maxsize 100

//˳��ջ
typedef struct SqStack {
	int data[maxsize];
	int top;
}SqStack;

//��ջ
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//˳���
typedef struct SqQueue {
	int data[maxsize];
	int front;
	int rear;
}SqQueue;

//����
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;
typedef struct LiQueue {
	QNode* Front;
	QNode* rear;
}LiQueue;

//C�������������ʽ�е�����ֻ��С���š���д�㷨���ж�һ�����ʽ�е������Ƿ���ȷ��ԣ����ʽ�Ѿ������ַ�����exp[]�У�
//���ʽ�е��ַ�����Ϊn
void c() {
	char exp[10] = {"1","+", "(", "3", "*", "(", "4", "+", "1", ")", ")" }; 
	struct SqStack* sq;
	sq = (SqStack*)malloc(sizeof(SqStack));
	sq->data[maxsize] = NULL;
	sq->top = -1;
	int i = 0, k = 1;
	printf("start-----\n");
	while (exp[i] != NULL) {
		if (exp[i] == '(') {
			sq->data[sq->top++] = exp[i]; 
		}
		if (exp[i] == ')') {
			if (sq->top == -1) {
				printf("��Դ���\n");
			}
			else {
				printf("��%d��С������Գɹ�\n", k);
				k++;
				--(sq->top);
			}
		}
	}
	if(sq->top==-1)
		printf("\n���ʽ��Գɹ�\n");
	else
		printf("\n���ʽ���ʧ��\n");
}

//3-2 ��дһ�����������׺ʽ����ֵ�����к�׺ʽ����һ���ַ�����exp�У�exp�����һ���ַ�Ϊ��\0������Ϊ��������
//���Ҽ����׺ʽ�е����ֶ�ֻ��һλ���㺯�������a Op b������





int main() {
	c();
	return 0;
}