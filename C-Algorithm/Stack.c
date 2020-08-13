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
			return -1;
		else
			return a / b;
	}
}
int com(char exp[]) {
	//����ͳ�ʼ��ջ
	char data[maxsize];
	int top = -1;
	int i=0;
	int a, b, result;
	while (exp[i] != '\0') {
		//�ж�ֵΪ���ֻ��������
		if (exp[i] >= '0' && exp[i] <= '9') {
			data[++top] = exp[i];
		}
		else {
			//�ж��Ƿ�ջ�ջ���ջ��ֻ��һ������
			if ((top == -1) || (top == 0)) {
				printf("�����ʽ����");
				return 0;
			}
			//��ջ
			a = (int)data[top--];
			b = (int)data[top--];
			result = op(a, exp[i], b);
			//��������ȷ,������ջ
			if (result == -1)
				return 0;
			data[++top] = result;
		}
	}
	return data[top];
}

//3-3 �ò���ͷ���ĵ�����洢��ջ����Ƴ�ʼ��ջ,�ж�ջ�Ƿ�Ϊ�գ���ջ�ͳ�ջ����Ӧ���㷨
void LNode_ALL(LNode* lst, int x) {
	//��ʼ������ͷ������ջ
	lst = NULL;
	//�ж�ջ�Ƿ�Ϊ��
	if (lst== NULL) {
		printf("ջΪ��");
	}
	else {
		printf("ջ��Ϊ��");
	}
	//��ջ
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = x;
	p->next = NULL;
	p->next = lst;
	lst = p;
	//��ջ
	LNode* q = (LNode*)malloc(sizeof(LNode));
	if (lst == NULL) {
		printf("ջΪ�գ����ɳ�ջ");
	}
	else {
		p = lst;
		x = p->data;
		lst = p->next;
		free(p);
	}
}

//2.6 �����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���β��㣬������ͷָ�룬��д����Ӧ������кͳ������㷨

//2.7 ���������ѭ�����е����˶����Խ��в����ɾ��������Ҫ��
//1�� д��ѭ�����е����Ͷ���
//2�� �ֱ�д���Ӷ�βɾ���ʹӶ�ͷ������㷨


//2.8 ���һ��ѭ�����У���front ��rear�ֱ���Ϊ��ͷ�Ͷ�βָ�룬������һ����־tag��ʾ�����ǿջ��ǲ��գ�Լ����tagΪ0ʱ�ӿգ���tagΪ1ʱ�Ӳ��գ���tag
//Ϊ1ʱ�Ӳ��գ������Ϳ�����front==rear��Ϊ����������Ҫ����ƶ��еĽṹ����ػ��������㷨������Ԫ��Ϊint�ͣ�

//2.9 ��дһ���㷨����һ���Ǹ���ʮ��������Nת��Ϊһ����������

//2.10 �Ա�дһ���㷨�����һ�������еĻ����ţ������ź�Ը�����Ƿ���ԣ���ȫ����ԣ��򷵻�1�����򷵻�0.���ڳ����г��ֵ�һ�Ե����Ż�˫�����ڵ��ַ�
//������������Լ�顣39Ϊ�����ŵ�ASCIIֵ��34Ϊ˫���ŵ�ASCIIֵ�������ź�˫�������������سɶԳ��֡�
//����stack���Ѿ������˳��ջ�ṹ�塣����ֱ�ӵ��õ�Ԫ�ؽ�ջ/��ջ��ȡջ��Ԫ�أ��ж�ջ�յĺ����������£�
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