#include <stdio.h>
#include <malloc.h>

#define maxsize 100

//顺序栈
typedef struct SqStack {
	int data[maxsize];
	int top;
}SqStack;

//链栈
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//顺序队
typedef struct SqQueue {
	int data[maxsize];
	int front;
	int rear;
}SqQueue;

//链队
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;
typedef struct LiQueue {
	QNode* Front;
	QNode* rear;
}LiQueue;

//C语言里算术表达式中的括号只有小括号。编写算法，判断一个表达式中的括号是否正确配对，表达式已经存入字符数组exp[]中，
//表达式中的字符个数为n
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
				printf("配对错误\n");
			}
			else {
				printf("第%d个小括号配对成功\n", k);
				k++;
				--(sq->top);
			}
		}
	}
	if(sq->top==-1)
		printf("\n表达式配对成功\n");
	else
		printf("\n表达式配对失败\n");
}

//3-2 编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组exp中，exp中最后一个字符为“\0”，作为结束符，
//并且假设后缀式中的数字都只有一位运算函数，完成a Op b的运算





int main() {
	c();
	return 0;
}