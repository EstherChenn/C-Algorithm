#include <stdio.h>

#define maxsize 100

//顺序栈定义
typedef struct SqStack {
	int data[maxsize];
	int top;		//栈顶指针
}SqStack;

//链栈结点定义
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//初始化顺序栈
void SqStack_init(SqStack *st) {
	st->top = -1;  
}

void SqStack_init1(SqStack st) {
	st.top = -1;
}

//判断栈空(如果空返回1，否则返回0)
int SqStack_isEmpty(SqStack *st) {
	if (st->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//进栈操作
int SqStack_push(SqStack* st, int x) {
	//先判断是否栈满
	if (st->top == maxsize - 1) {
		printf("已栈满\n");
		return 0;
	}
	else {
		++(st->top);
		st->data[st->top] = x;
		return 1;
	}
}

//出栈操作
int SqStack_pop(SqStack* st, int x) {
	//先判断是否栈空
	if (st->top == -1) {
		printf("已栈空\n");
		return 0;
	}
	else {
		x = st->data[st->top];
		--(st->top);
		return 1;
	}
}

//顺序栈的常用操作(由于顺序栈比较简单，故上述操作一般不采用，一般采用以下操作)
void SqStack_main() {
	int x = 0;
	//栈初始化
	int stack[maxsize];
	int top = -1;
	//进栈
	stack[top++] = x;
	//出栈
	x = stack[top--];
}

//链栈的初始化
void LNode_init(LNode** lst) {
	*lst = (LNode*)malloc(sizeof(LNode));
	(*lst)->next = NULL;
}

//判断栈空
int LNode_isEmpty(LNode* lst) {
	if (lst->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//进栈操作
void LNode_push(LNode* lst,int x ) {
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	//有头结点的头插法
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}
 
//出栈操作
int LNode_pop(LNode* lst) {
	int x;
	LNode* p;
	if (lst->next == NULL)
		return 0;
	p = lst->next;
	x = p->data;
	lst->next = p->next;
	free(p);
	return 1;
}

//3-1 编写算法，判断一个表达式中的括号是否正确配对，表达式已存入字符组exp[]中，表达式中的字符个数为n
int match(char exp[],int n) {
	//初始化栈和定义
	char stack[maxsize];
	int top = -1;
	int i;

	for (i = 0; i < n; i++) {
		if (exp[i] == '(') {
			stack[++top] = '(';
		}
		if (exp[i] == ')') {
			if (top == -1)
				return 0;
			else
				--top;
		}
	}
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}

}
//3-2 编写一个函数，求后缀式的数值，其中后缀式存于一个字符数组exp中，exp中最后一个字符为“\0”，作为结束符，并且假设后缀式中的数字都只有一位
//运算函数，完成a Op b的运算
int op(int a, char Op, int b) {
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0)		//除数不为0
			return 0;
		else
			return a / b;
	}
}
int com(char exp[]) {
	char data[maxsize];
	int top = -1;
}

//3-3 用不带头结点的单链表存储链栈，设计初始化栈,判断栈是否为空，进栈和出栈等相应的算法



int main() {
	struct LNode* st;
	LNode_init(&st);
	PushStack(&st, 4);
	PushStack(&st, 5);
	while (st != NULL) {
		printf("%d ", st->data);
	}
//	printf("result = %d\n", isEmpty(&st));
 /*	SqStack_init1(st1);*/
	printf("end____\n");
	return 0;
}