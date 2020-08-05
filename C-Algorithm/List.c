#include <stdio.h>

#define maxsize 100
//顺序表的结构体定义
typedef struct {
	int data[maxsize];
	int length;
}Sqlist;

//单链表结点定义
typedef struct {
	int data;
	struct LNode* next;
}LNode;

//双链表结点定义
typedef struct {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;

//初始化顺序表 
void Sqlist_create(Sqlist* sq,int len) {
	int i;
	sq->length = len;
	for (i = 0; i < len; i++) { 
//		scanf("%d\n", &(sq->data[i]));
	}
}

//顺序表的查找
int Sqlist_find(Sqlist *sq,int x) {
	int i;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//顺序表的插入(x是插入值,k是插入位置)
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