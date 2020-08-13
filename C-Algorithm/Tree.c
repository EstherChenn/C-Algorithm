#include <stdio.h>

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


//6-2 写一个算法求一棵二叉树的深度，二叉树以二叉链表为存储方式


//6-3 在一棵以二叉链表为存储结构的二叉树中，查找data域值等于key的结点是否存在，如果存在，则将q指向该结点，否则q赋值NULL，假设data是int型


//6-4 假设二叉树采用二叉链表存储结构存储，编写一个程序，输出先序遍历中第K个结点的值，假设k不大于总的结点数


//层次遍历

//6-5 假设二叉树采用二叉链表存储结构存储，设计一个算法，求出该二叉树的宽度（具有结点数最多的那一层上的结点个数




int main() {

}