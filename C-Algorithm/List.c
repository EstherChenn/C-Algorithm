#include <stdio.h>

#define maxsize 100
//˳���Ľṹ�嶨��
typedef struct {
	int data[maxsize];
	int length;
}Sqlist;

//�������㶨��
typedef struct {
	int data;
	struct LNode* next;
}LNode;

//˫�����㶨��
typedef struct {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;

//��ʼ��˳��� 
void Sqlist_create(Sqlist* sq,int len) {
	int i;
	sq->length = len;
	for (i = 0; i < len; i++) { 
//		scanf("%d\n", &(sq->data[i]));
	}
}

//˳���Ĳ���
int Sqlist_find(Sqlist *sq,int x) {
	int i;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//˳���Ĳ���(x�ǲ���ֵ,k�ǲ���λ��)
void Sqlist_insert(Sqlist* sq, int x,int k) {
	int i, j;
	for (i = 0; i < sq->length; i++) {
		if (i == k) {
			for (j = sq->length; j > i; j--) {
				sq->data[j] = sq->data[j - 1];
			}
			sq->data[i] = x;
		}
	} 
}

int main() {
	Sqlist sq;
	int i;
//	Sqlist_create(&sq,6);
	sq.length = 6;
	//sq.data[] = {1,3,5,6,53,1 };
	//scanf("%d", &i);
	for (i = 0; i < 6; i++) {
		scanf_s("%d\n", &(sq.data[i]));
	}
	//Sqlist_insert(&sq, 2, 0);
	return 0;
}