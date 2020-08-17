#include <stdio.h>

#define num 0
#define maxsize 100
//二叉树的链式存储结构
typedef struct BTNode {
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//先序遍历
void preorder(BTNode* p) {
	if (p == NULL) {
		printf("遍历结束");
	}
	printf("p = %c \n", p->data);
	preorder(p->lchild);
	preorder(p->rchild);
}

//中序遍历
void inorder(BTNode* p) {
	if (p == NULL) {
		printf("遍历结束");
	}
	preorder(p->lchild);
	printf("p = %c \n", p->data);
	preorder(p->rchild);

}

//后序遍历
void postorder(BTNode* p) {
	if (p == NULL) {
		printf("遍历结束");
	}
	preorder(p->lchild);
	preorder(p->rchild);
	printf("p = %c \n", p->data);

}

//6-1 表达式（a-(b+c))*(d/e)存储在一棵以二叉链表为存储表格的二叉树中，编程写出该表达式的值
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
int comp(BTNode* p) {
	int A, B;
	if (p != NULL) {
		if (p->lchild != NULL && p->rchild != NULL) {
			A = comp(p->lchild);
			B = comp(p->rchild);
			return op(A, B, p->data);
		}
		else {
			//若当前结点的左，右子树都为空，则为数值
			return p->data - '0';
		}
	}
	else
		return 0;
}

//6-2 写一个算法求一棵二叉树的深度，二叉树以二叉链表为存储方式
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

//6-3 在一棵以二叉链表为存储结构的二叉树中，查找data域值等于key的结点是否存在，如果存在，则将q指向该结点，否则q赋值NULL，假设data是int型
void search(BTNode* p, BTNode* q,int key) {
	if (p != NULL) {
		if (p->data == key)
			q = p;
		else {
			search(p->lchild, q, key);
			if (q == NULL)
				//如果在左子树中没有找到才到右子树中查找
				search(p->rchild, q, key);
		}
	}
}

//6-4 假设二叉树采用二叉链表存储结构存储，编写一个程序，输出先序遍历中第K个结点的值，假设k不大于总的结点数
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

//层次遍历
void level(BTNode* p) {
	int front, rear;
	//定义一个循环队列，用于记录将要访问的层次上的结点
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



//6-5 假设二叉树采用二叉链表存储结构存储，设计一个算法，求出该二叉树的宽度（具有结点数最多的那一层上的结点个数


//二叉树深度优先遍历算法(自定义栈)-------先序遍历非递归算法
void preorderNonrecursion(BTNode* bt) {
	if (bt != NULL) {
		//定义个初始化一个栈
		BTNode* stack[maxsize];
		int top = -1;
		BTNode* p;
		//根结点入栈
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

//二叉树深度优先遍历算法(自定义栈)-------中序遍历非递归算法
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

//二叉树深度优先遍历算法(自定义栈)-------后序遍历非递归算法
void postorderNonrecursion(BTNode* bt) {
	if (bt != NULL) {
		//定义两个栈
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

//线索二叉树的结点定义
typedef struct TBTNode {
	char data;
	int ltag, rtag;
	struct TBTNode* lchild;
	struct TBTNode* rchild;
}TBTNode;

//通过中序遍历对二叉树线索化的递归算法
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

//通过中序遍历建立中序线索二叉树
void createInThread(TBTNode* root) {
	TBTNode* pre = NULL;
	if (root != NULL) {
		InThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

//遍历中序线索二叉树
//求以p为根的中序线索二叉树中，中序序列下的第一个结点的算法
TBTNode* first(TBTNode* p) {
	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}
//求在中序线索二叉树中，结点p在中序下的后继结点的算法
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

//前序搜索二叉树

//遍历前序搜索二叉树

//后序搜索二叉树

//1.2 假设二叉树采用二叉链存储结构，设计一个算法，计算一棵给定二叉树的所有结点数
int n = 0;
int nodeNum(TBTNode* p) {
	if (p != NULL) {
		++n;
		nodeNum(p->lchild);
		nodeNum(p->rchild);
	}
}

//1.3 假设二叉树采用二叉链存储结构，设计一个算法，计算一棵给定二叉树的所有叶子结点数
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

//1.4 假设二叉树采用二叉链存储结构，设计一个算法，利用结点的右孩子指针rchild将一棵二叉树的叶子结点按照从左往右的顺序串成一个单链表
//（在题目中定义两个指针，head和tail，其中head指向第一个叶子结点，head初值为NULL，tail指向最后一个叶子结点)



//1.5 在二叉树的二叉链存储结构中，增加一个指向双亲结点的parent指针，设计一个算法，给这个指针赋值，并输出所有结点到根结点的路径

//1.6 假设满二叉树b的先序遍历序列已经存在于数组中，设计一个算法将其转换为后序遍历序列

//1.7 假设二叉树采用二叉链存储结构，设计一个算法，求二叉树b中值为x的结点的层号

//1.8 以数据集合{2,5,7,9,13}为权值构造一棵赫夫曼树，并计算其带权路径长度

//1.9 二叉树的双序遍历是指：对于二叉树的每一个结点来说，先访问这个结点，再按双序遍历它的左子树，然后再一次访问这个结点，接下来按双序遍历
//它的右子树。试写出执行这种双序遍历的算法

//1.11 设中序线索二叉树的类型为TBTNode* InThree
//1.11.1 设计算法，在一棵中序线索二叉树中寻找结点t的子树上中序下的最后一个结点

//1.11.2 设计算法，在一棵中序线索二叉树中寻找结点t的中序下的前驱

//1.11.3 设计算法，在一棵中序线索二叉树中寻找结点t的前序下的后继


int main() {

}