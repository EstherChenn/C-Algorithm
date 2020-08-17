#include <stdio.h>

#define num 0
#define maxsize 100
//����������ʽ�洢�ṹ
typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//�������
void preorder(BTNode* p) {
	if (p == NULL) {
		printf("��������");
	}
	printf("p = %c \n", p->data);
	preorder(p->lchild);
	preorder(p->rchild);
}

//�������
void inorder(BTNode* p) {
	if (p == NULL) {
		printf("��������");
	}
	preorder(p->lchild);
	printf("p = %c \n", p->data);
	preorder(p->rchild);

}

//�������
void postorder(BTNode* p) {
	if (p == NULL) {
		printf("��������");
	}
	preorder(p->lchild);
	preorder(p->rchild);
	printf("p = %c \n", p->data);

}

//6-1 ���ʽ��a-(b+c))*(d/e)�洢��һ���Զ�������Ϊ�洢���Ķ������У����д���ñ��ʽ��ֵ
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
int comp(BTNode* p) {
	int A, B;
	if (p != NULL) {
		if (p->lchild != NULL && p->rchild != NULL) {
			A = comp(p->lchild);
			B = comp(p->rchild);
			return op(A, B, p->data);
		}
		else {
			//����ǰ��������������Ϊ�գ���Ϊ��ֵ
			return p->data - '0';
		}
	}
	else
		return 0;
}

//6-2 дһ���㷨��һ�ö���������ȣ��������Զ�������Ϊ�洢��ʽ
int getDepth(BTNode* p) {
	int LD, RD;
	if (p == NULL)
		return 0;
	else {
		LD = getDepth(p->lchild);
		RD = getDepth(p->rchild);
		return (LD > RD ? LD : RD) + 1;
	}
}

//6-3 ��һ���Զ�������Ϊ�洢�ṹ�Ķ������У�����data��ֵ����key�Ľ���Ƿ���ڣ�������ڣ���qָ��ý�㣬����q��ֵNULL������data��int��
void search(BTNode* p, BTNode* q,int key) {
	if (p != NULL) {
		if (p->data == key)
			q = p;
		else {
			search(p->lchild, q, key);
			if (q == NULL)
				//�������������û���ҵ��ŵ��������в���
				search(p->rchild, q, key);
		}
	}
}

//6-4 ������������ö�������洢�ṹ�洢����дһ�����������������е�K������ֵ������k�������ܵĽ����
void trave(BTNode* p, int k) {
	if (p != NULL) {
		num++;
		if (k == n) {
			printf("%d\n", p->data);
			return;
		}
		else {
			trave(p->lchild, k);
			trave(p->rchild, k);
		}
	}
}

//��α���
void level(BTNode* p) {
	int front, rear;
	//����һ��ѭ�����У����ڼ�¼��Ҫ���ʵĲ���ϵĽ��
	BTNode* que[maxsize];
	front = 0;
	rear = 0;
	BTNode* q;
	if (p != NULL) {
		rear = (rear + 1) % maxsize;
		que[rear] = p;
		while (front != rear) {
			front = (front + 1) % maxsize;
			q = que[front];
			visit(q);
			if (q->lchild != NULL) {
				rear = (rear + 1) % maxsize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {
				rear = (rear + 1) % maxsize;
				que[rear] = q->rchild;
			}
		}
	}
}



//6-5 ������������ö�������洢�ṹ�洢�����һ���㷨������ö������Ŀ�ȣ����н����������һ���ϵĽ�����


//������������ȱ����㷨(�Զ���ջ)-------��������ǵݹ��㷨
void preorderNonrecursion(BTNode* bt) {
	if (bt != NULL) {
		//�������ʼ��һ��ջ
		BTNode* stack[maxsize];
		int top = -1;
		BTNode* p;
		//�������ջ
		stack[++top] = bt;
		while (top != -1) {
			p = stack[top--];
			visit(p);
			if (p->rchild != NULL)
				stack[++top] = p->rchild;
			if (p->lchild != NULL)
				stack[++top] = p->lchild;
		}
	}
}

//������������ȱ����㷨(�Զ���ջ)-------��������ǵݹ��㷨
void inorderNonrecursion(BTNode* bt) {
	if (bt != NULL) {
		BTNode* stack[maxsize];
		int top = -1;
		BTNode* p;
		p = bt;
		while (top != -1 || p != NULL) {
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1) {
				p = stack[top--];
				visit(p);
				p = p->rchild;
			}
		}
	}
}

//������������ȱ����㷨(�Զ���ջ)-------��������ǵݹ��㷨
void postorderNonrecursion(BTNode* bt) {
	if (bt != NULL) {
		//��������ջ
		BTNode* stack1[maxsize];
		int top1 = -1;
		BTNode* stack2[maxsize];
		int top2 = -1;
		BTNode* p = NULL;
		stack1[++top1] = bt;
		while (top1 != -1) {
			p = stack1[top1--];
			stack2[++top2] = p;
			if (p->lchild != NULL)
				stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}
		while (top2 != -1) {
			p = stack2[top2--];
			visit(p);
		}
	}
}

//�����������Ľ�㶨��
typedef struct TBTNode {
	char data;
	int ltag, rtag;
	struct TBTNode* lchild;
	struct TBTNode* rchild;
}TBTNode;

//ͨ����������Զ������������ĵݹ��㷨
void InThread(TBTNode* p, TBTNode* pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		p = p->rchild;
		InThread(p, pre);
	}
}

//ͨ���������������������������
void createInThread(TBTNode* root) {
	TBTNode* pre = NULL;
	if (root != NULL) {
		InThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

//������������������
//����pΪ�������������������У����������µĵ�һ�������㷨
TBTNode* first(TBTNode* p) {
	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}
//�������������������У����p�������µĺ�̽����㷨
TBTNode* next(TBTNode* p) {
	if (p->rtag == 0)
		return first(p->rchild);
	else
		return p->rchild;
}
void Inorder(TBTNode* root) {
	for (TBTNode* p = first(root); p != NULL; p = next(p)) {
		visit(p);
	}
}

//ǰ������������

//����ǰ������������

//��������������

//1.2 ������������ö������洢�ṹ�����һ���㷨������һ�ø��������������н����
int n = 0;
int nodeNum(TBTNode* p) {
	if (p != NULL) {
		++n;
		nodeNum(p->lchild);
		nodeNum(p->rchild);
	}
}

//1.3 ������������ö������洢�ṹ�����һ���㷨������һ�ø���������������Ҷ�ӽ����
int n = 0;
int count(TBTNode* p) {
	int n1, n2;
	if (p == NULL) {
		return 0;
	}
	else if ((p->lchild == NULL) && (p->rchild == NULL)) {
		return 1;
	}
	else {
		n1 = count(p->lchild);
		n2 = count(p->rchild);
		return n1 + n2 + 1;
	}
}

//1.4 ������������ö������洢�ṹ�����һ���㷨�����ý����Һ���ָ��rchild��һ�ö�������Ҷ�ӽ�㰴�մ������ҵ�˳�򴮳�һ��������
//������Ŀ�ж�������ָ�룬head��tail������headָ���һ��Ҷ�ӽ�㣬head��ֵΪNULL��tailָ�����һ��Ҷ�ӽ��)



//1.5 �ڶ������Ķ������洢�ṹ�У�����һ��ָ��˫�׽���parentָ�룬���һ���㷨�������ָ�븳ֵ����������н�㵽������·��

//1.6 ������������b��������������Ѿ������������У����һ���㷨����ת��Ϊ�����������

//1.7 ������������ö������洢�ṹ�����һ���㷨���������b��ֵΪx�Ľ��Ĳ��

//1.8 �����ݼ���{2,5,7,9,13}ΪȨֵ����һ�úշ����������������Ȩ·������

//1.9 ��������˫�������ָ�����ڶ�������ÿһ�������˵���ȷ��������㣬�ٰ�˫�����������������Ȼ����һ�η��������㣬��������˫�����
//��������������д��ִ������˫��������㷨

//1.11 ����������������������ΪTBTNode* InThree
//1.11.1 ����㷨����һ������������������Ѱ�ҽ��t�������������µ����һ�����

//1.11.2 ����㷨����һ������������������Ѱ�ҽ��t�������µ�ǰ��

//1.11.3 ����㷨����һ������������������Ѱ�ҽ��t��ǰ���µĺ��


int main() {

}