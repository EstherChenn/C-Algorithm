#include <stdio.h>

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


//6-2 дһ���㷨��һ�ö���������ȣ��������Զ�������Ϊ�洢��ʽ


//6-3 ��һ���Զ�������Ϊ�洢�ṹ�Ķ������У�����data��ֵ����key�Ľ���Ƿ���ڣ�������ڣ���qָ��ý�㣬����q��ֵNULL������data��int��


//6-4 ������������ö�������洢�ṹ�洢����дһ�����������������е�K������ֵ������k�������ܵĽ����


//��α���

//6-5 ������������ö�������洢�ṹ�洢�����һ���㷨������ö������Ŀ�ȣ����н����������һ���ϵĽ�����




int main() {

}