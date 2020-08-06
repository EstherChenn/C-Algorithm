#include <stdio.h>

#define maxsize 4
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
		scanf_s("%d", &(sq->data[i]));
		printf("%d = %d \n", i,sq->data[i]);
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
			++(sq->length);
			for (j = sq->length; j > i; j--) {
				sq->data[j] = sq->data[j - 1];
			}
			/*for (j = sq->length - 1; j > i; j--) {
				sq->data[j++] = sq->data[j ];
			}*/
			sq->data[i] = x;
		}
	} 
	/*for (i = 0; i < sq->length; i++) {
		printf("%d ", sq->data[i]);
	}
	printf("\n");*/
}

//顺序表的删除操作(删除下标为p的元素)
int Sqlist_delete(Sqlist* sq, int p) {
	int i;
	if (p > sq->length) {
		return 0;
	}
	for (i = 0; i < sq->length; i++) {
		if (i == p) {
			sq->data[i] = sq->data[i + 1];
		}
		(sq->length)--;
	}
}

//初始化单链表
void initList(LNode* C) {
	C = (LNode*)malloc(sizeof(LNode));
	if (C == NULL)
		printf("申请失败\n");
	C->data = NULL;
}

//头插法建立链表(将n个元素已经存储在数组a中，用尾插法建立单链表C)
void createlistF(LNode* C, int a[], int n) {
	LNode *s; 
	int i; 
	//头结点后的第一个结点
	C = (LNode*)malloc(sizeof(LNode));
	C->data = NULL;
	for (i = 0; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = C->next;
		C->next = s;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", C->data);
		C = C->next;
	}
}
//尾插法建立链表(将n个元素已经存储在数组a中，用尾插法建立单链表C)
void createlistR(LNode* C, int a[], int n) {
	//s用来指向新申请的结点，r用来指向C的终端结点
	LNode* s, * r;
	int i;
	r = (LNode*)malloc(sizeof(LNode));
	r->data = a[0];
	C->next = r;
	for (i = 1; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	for (i = 0; i < n; i++) {
		printf("%d ", C->data);
		C = C->next;
	}
}

//归并链表

//删除

//查找


int main() {
	LNode* C;
	int i;
	int a[4] = {1,2,3,4};
//	initList(&C);
	createlistF(&C, a, 4);
	return 0;
}