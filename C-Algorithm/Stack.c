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
			return -1;
		else
			return a / b;
	}
}
int com(char exp[]) {
	//定义和初始化栈
	char data[maxsize];
	int top = -1;
	int i=0;
	int a, b, result;
	while (exp[i] != '\0') {
		//判断值为数字还是运算符
		if (exp[i] >= '0' && exp[i] <= '9') {
			data[++top] = exp[i];
		}
		else {
			//判断是否栈空或者栈里只有一个数字
			if ((top == -1) || (top == 0)) {
				printf("输入格式错误");
				return 0;
			}
			//出栈
			a = (int)data[top--];
			b = (int)data[top--];
			result = op(a, exp[i], b);
			//如果输出正确,则结果入栈
			if (result == -1)
				return 0;
			data[++top] = result;
		}
	}
	return data[top];
}

//3-3 用不带头结点的单链表存储链栈，设计初始化栈,判断栈是否为空，进栈和出栈等相应的算法
void LNode_ALL(LNode* lst, int x) {
	//初始化不带头结点的链栈
	lst = NULL;
	//判断栈是否为空
	if (lst== NULL) {
		printf("栈为空");
	}
	else {
		printf("栈不为空");
	}
	//进栈
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = x;
	p->next = NULL;
	p->next = lst;
	lst = p;
	//出栈
	LNode* q = (LNode*)malloc(sizeof(LNode));
	if (lst == NULL) {
		printf("栈为空，不可出栈");
	}
	else {
		p = lst;
		x = p->data;
		lst = p->next;
		free(p);
	}
}

//2.6 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头指针，请写出相应的入队列和出队列算法

//2.7 如果允许在循环队列的两端都可以进行插入和删除操作，要求：
//1） 写出循环队列的类型定义
//2） 分别写出从队尾删除和从队头插入的算法


//2.8 设计一个循环队列，用front 和rear分别作为队头和队尾指针，另外用一个标志tag表示队列是空还是不空，约定当tag为0时队空，当tag为1时队不空，当tag
//为1时队不空，这样就可以用front==rear作为队满的条件要求，设计队列的结构和相关基本运算算法（队列元素为int型）

//2.9 编写一个算法，将一个非负的十进制整数N转换为一个二进制数

//2.10 试编写一个算法，检查一个程序中的花括号，方括号和愿括号是否配对，若全部配对，则返回1，否则返回0.对于程序中出现的一对单引号或双引号内的字符
//不进行括号配对检查。39为单引号的ASCII值，34为双引号的ASCII值，单引号和双引号如果出现则必成对出现。
//假设stack试已经定义的顺序栈结构体。可以直接调用的元素进栈/出栈，取栈顶元素，判断栈空的函数定义如下：
void push(stack* S, char ch) {

}
void pop(stack* S, char ch) {

}
void getTop(stack S, char ch) {

}
int isEmpty(stack s) {

}









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