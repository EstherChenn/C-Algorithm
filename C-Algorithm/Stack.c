#include <stdio.h>

#define maxsize 100

//˳��ջ����
typedef struct SqStack {
	int data[maxsize];
	int top;		//ջ��ָ��
}SqStack;

//��ջ��㶨��
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//��ʼ��˳��ջ
void SqStack_init(SqStack *st) {
	st->top = -1;  
}

void SqStack_init1(SqStack st) {
	st.top = -1;
}

//�ж�ջ��(����շ���1�����򷵻�0)
int SqStack_isEmpty(SqStack *st) {
	if (st->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//��ջ����
int SqStack_push(SqStack* st, int x) {
	//���ж��Ƿ�ջ��
	if (st->top == maxsize - 1) {
		printf("��ջ��\n");
		return 0;
	}
	else {
		++(st->top);
		st->data[st->top] = x;
		return 1;
	}
}

//��ջ����
int SqStack_pop(SqStack* st, int x) {
	//���ж��Ƿ�ջ��
	if (st->top == -1) {
		printf("��ջ��\n");
		return 0;
	}
	else {
		x = st->data[st->top];
		--(st->top);
		return 1;
	}
}

//˳��ջ�ĳ��ò���(����˳��ջ�Ƚϼ򵥣�����������һ�㲻���ã�һ��������²���)
void SqStack_main() {
	int x = 0;
	//ջ��ʼ��
	int stack[maxsize];
	int top = -1;
	//��ջ
	stack[top++] = x;
	//��ջ
	x = stack[top--];
}

//��ջ�ĳ�ʼ��
void LNode_init(LNode** lst) {
	*lst = (LNode*)malloc(sizeof(LNode));
	(*lst)->next = NULL;
}

//�ж�ջ��
int LNode_isEmpty(LNode* lst) {
	if (lst->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//��ջ����
void LNode_push(LNode* lst,int x ) {
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	//��ͷ����ͷ�巨
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}
 
//��ջ����
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

//3-1 ��д�㷨���ж�һ�����ʽ�е������Ƿ���ȷ��ԣ����ʽ�Ѵ����ַ���exp[]�У����ʽ�е��ַ�����Ϊn
int match(char exp[],int n) {
	//��ʼ��ջ�Ͷ���
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
//3-2 ��дһ�����������׺ʽ����ֵ�����к�׺ʽ����һ���ַ�����exp�У�exp�����һ���ַ�Ϊ��\0������Ϊ�����������Ҽ����׺ʽ�е����ֶ�ֻ��һλ
//���㺯�������a Op b������
int op(int a, char Op, int b) {
	if (Op == '+')
		return a + b;
	if (Op == '-')
		return a - b;
	if (Op == '*')
		return a * b;
	if (Op == '/') {
		if (b == 0)		//������Ϊ0
			return 0;
		else
			return a / b;
	}
}
int com(char exp[]) {
	char data[maxsize];
	int top = -1;
}

//3-3 �ò���ͷ���ĵ�����洢��ջ����Ƴ�ʼ��ջ,�ж�ջ�Ƿ�Ϊ�գ���ջ�ͳ�ջ����Ӧ���㷨



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