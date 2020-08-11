#include <stdio.h>

#define maxsize 4
//顺序表的结构体定义
typedef struct Sqlist {
	int data[maxsize];
	int length;
}Sqlist;

//单链表结点定义
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//双链表结点定义
typedef struct DLNode {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;

//初始化顺序表
void Sqlist_create(Sqlist* sq, int len) {
	int i;
	sq->length = len;
	for (i = 0; i < len; i++) {
		scanf_s("%d", &(sq->data[i]));
		//	printf("%d = %d \n", i,sq->data[i]);
	}
}

//顺序表的查找
int Sqlist_find(Sqlist* sq, int x) {
	int i;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//顺序表的插入(x是插入值,k是插入位置)
void Sqlist_insert(Sqlist* sq, int x, int k) {
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
	return 1;
}

//初始化单链表
void LNode_initList(LNode* C) {
	C = (LNode*)malloc(sizeof(LNode));
	if (C == NULL)
		printf("申请失败\n");
	C->next = NULL;
}

//头插法建立链表(将n个元素已经存储在数组a中，用头插法建立单链表C)
void LNode_createlistF(LNode* C, int a[], int n) {
	LNode* s;
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
	while (C != NULL) {
		printf("%d ", C->data);
		C = C->next;
	}
	printf("\n");
}
//尾插法建立链表(将n个元素已经存储在数组a中，用尾插法建立单链表C)
void LNode_createlistR(LNode** C, int a[], int n) {
	//s用来指向新申请的结点，r用来指向C的终端结点
	LNode* s, * r;
	int i;
	//C的头结点申请空间
	*C = (LNode*)malloc(sizeof(LNode));
	//	C->data = NULL;
	(*C)->next = NULL;
	//r指向头结点
	r = *C;
	for (i = 0; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
	while (*C != NULL) {
		printf("%d ", (*C)->data);
		(*C) = (*C)->next;
	}
	printf("\n");
}

//归并链表（A和B都是按元素递增排序，将A和B归并成一个按元素值非递减有序的链表C,C由A和B中的结点组成）
void LNode_merge(LNode* A, LNode* B, LNode** C) {
	LNode* p = A->next;
	LNode* q = B->next;
	LNode* r;
	*C = A;
	//C->next = NULL;
	//free(B);
	r = C;
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if (p != NULL)
		r->next = p;
	if (q != NULL)
		r->next = q;
	/*while (C != NULL) {
		printf("%d ", C->data);
		C = C->next;
	}*/
	printf("\n");
}

//查找和删除
int LNode_FindAndDelete(LNode* C, int x) {
	LNode* p, * q;
	p = C;
	while (p->next != NULL) {
		if (p->next->data == x)
			break;
		p = p->next;
	}
	if (p->next == NULL) {
		printf("查找失败\n");
		return 0;
	}
	else {
		q = p->next;
		p->next = p->next->next;
		//	free(q);
		return 1;
	}
}

//尾插法建立双链表
void DLNode_createDlistR(DLNode* L, int a[], int n) {
	DLNode* s, * r;
	int i;
	L = (DLNode*)malloc(sizeof(DLNode));
	L->prior = NULL;
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++) {
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

//双链表查找结点
DLNode* DLNode_find(DLNode* C, int x) {
	DLNode* p = C->next;
	while (p != NULL) {
		if (p->data == x) {
			break;
		}
		p = p->next;
	}
	return p;
}

//双链表插入结点
void DLNode_insert(DLNode* C, DLNode* s) {
	DLNode* p = C->next;
	s->next = p->next;
	s->prior = p;
	p->next = s;
	s->next->prior = s;
}

//双链表删除结点
void DLNode_delete(DLNode* C, DLNode* p) {
	DLNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	//	free(q);
}

//1.3 设计一个算法，将顺序表中的所有元素逆置
void Sqlist_trans(Sqlist* s) {
	int i, j, index;
	int len = s->length;
	for (i = 0, j = len - 1; i < len / 2; i++, j--) {
		index = s->data[i];
		s->data[i] = s->data[j];
		s->data[j] = index;
	}
	for (i = 0; i < len; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

//1.4 设计一个算法，从一给定的顺序表L中删除下标从i到j（i<=j,包括i和j）的所有元素，假定i,j都是合法的
void Sqlist_delij(Sqlist* s, int i, int j) {
	int n;
	int k = i;
	for (n = j + 1, k = i; n < s->length; n++, k++) {
		if (s->data[n] != NULL && k <= j) {
			s->data[k] = s->data[n];
			(s->length)--;
		}
	}
	while (k < j) {
		s->data[k] = NULL;
	}
	for (i = 0; i < s->length; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

//1.5 有一个顺序表L，其元素为整型数据，设计一个算法，将L中所有小于表头元素的整数放在前半部分，大于表头元素的整数放在后半部分
void Sqlist_biao(Sqlist* q) {
	int head, i, j, index;
	int ma = 0, mi = 0;
	head = q->data[0];
	for (i = 1; i < q->length; i++) {
		if (head > q->data[0]) {
			//mi-(i-1)数都后移一位
			for (j = i - 1; j >= mi; j--) {
				index = q->data[i];
				q->data[j + 1] = q->data[j];
			}
			q->data[mi] = index;
			mi++;
		}
		else {
			ma++;
		}
	}
	for (i = 0; i < q->length; i++) {
		printf("%d ", q->data[i]);
	}
}
//1.6 有一个递增非空单链表，设计一个算法删除值域重复的结点。例如{1，1，2，3，3，3，4，5，7，7，7，9，9，9}经过删除后变成{1，2，3，4，7，9}
void LNode_delNode(LNode** L) {
	int i;
	//*s指向L的当前结点，*r指向下一结点
	LNode* s, * r;
	s = *L;
	r = s->next;
	while (r != NULL) {
		//如果相等，则s指向r的下一指针，并释放r
		if (s->data == r->data) {
			free(r);
			s = s->next->next;
			r = s->next;
		}
		else {
			s = s->next;
			r = s->next;
		}
	}
}

//1.7 设计一个算法删除单链表L（有头结点）中的一个最小值结点
void LNode_delmin(LNode* L) {
	int min;
	//*s指向当前结点,*r记录最小值点,*a指向当前结点的前一个,*m记录最小值的前一个结点
	LNode* s, * r, * a, * m;
	a = L;
	m = L;
	r = L->next;
	s = L->next;
	//寻找结点
	while (s->next != NULL) {
		if (s->data < min) {
			min = s->data;
			r = s;
			m = a;
		}
		s = s->next;
		a = a->next;
	}
	//删除结点
	m->next = r->next;
	free(r);
}

//1.8 有一个线性表，采用头结点的单链表L来存储。设计一个算法将其逆置。要求不能建立新结点，只能通过表中已有结点的重新组合来完成
void LNode_invert(LNode* L) {
	//*s指向当前结点,*r指向当前结点的下一结点，*f指向当前结点的前一个结点
	LNode* s, * r, * f;
	f = s;
	s = f->next;
	r = s->next;
	while (s->next != NULL) {
	}
}

//1.9 设计一个算法，将一个头结点为A的单链表（其数据域为整数）分解成两个单链表A和B，使得A链表只含有原来链表中data域为奇数的结点，而B链表中只含有原链表中
//data域为偶数的结点，且保持原来的相对顺序

//2.2 写一个函数，逆序打印单链表中的数据，假设指针L指向了单链表的开始结点

//2.3 试编写一个函数，以不多于3n/2的平均比较次数，在一个有n个整数的顺序表A中找出最大值和最小值

int main() {
	/*LNode* A;
	LNode* A1;
	LNode* B;
	LNode* B1;
	LNode* C;
	int a[4] = { 4,5,7,8 };
	int b[6] = { 1,2,3,4,5,6 };
	printf("A：\n");
	LNode_createlistR(&A,a,4);
	A1 = A->next;
	printf("B：\n");
	LNode_createlistR(&B, b, 6);
	B1 = B->next;
	printf("C：\n");
	LNode_merge(&A1, &B1, &C);
	while (C != NULL) {
		printf("%d ", C->data);
		C = C->next;
	}
	printf("\n");  */
	Sqlist s;
	Sqlist_create(&s, 10);
	Sqlist_biao(&s);
	return 0;
}