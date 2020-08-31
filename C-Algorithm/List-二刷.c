#include <stdio.h>
#include <malloc.h>

#define maxsize 100

//顺序表
typedef struct Sqlist {
	char data[maxsize];
	int length;
}Sqlist;

//单链表
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//双链表
typedef struct DLNode{
	int data;
	struct DLNode* prior;
	struct DLNode* next;

}DLNode;

//单链表的尾插法
void createlistR(LNode* C, int a[], int n) {
	LNode* s, * r;
	int i;
	C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;
	r = C;
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

//单链表的头插法
void createlistF(LNode** C, int a[], int n) {
	LNode* s;
	int i;
	(*C) = (LNode*)malloc(sizeof(LNode));
	(*C)->next = NULL;
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = (*C)->next;
		(*C)->next = s;
	}
}

//双链表的尾插法
void createDlistR(DLNode** L,int a[], int n) {
	DLNode* s, * r;
	int i;
	(*L) = (DLNode*)malloc(sizeof(DLNode));
	(*L)->next = NULL;
	r = (*L);
	for (i = 0; i < n; i++) {
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

//真题1
void zt1() {
	int a[10] = { 1,3,5,7,9,2,2,6,8,10 };
	int m = 5, n = 5;
	int i, j, k, s;
	j = m;
	for (i = 0; i < 10; i++) {
		while (a[j] < a[i]) {
			s = a[j];
			//i-j之间的数字后移一位
			for (k = j; k >= i; k--) {
				a[k] = a[k - 1];
			}
			a[i] = s;
			j++;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//真题2
void zt2(LNode* l1, LNode*l2) { 
	LNode* p=l1->next, * q=l2->next;
	LNode* pre = l1,*r;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			pre = p;
			p = p->next;
		}
		else if (p->data > q->data)
			q = q->next;
		else {
			pre->next = p->next;
			r = p;
			p = p->next;
			free(r);
		}
	}
}

//1-3 设计一个算法，将顺序表中的所有元素逆置
void c3() {
	struct Sqlist *sq;  
	/*sq = NULL;
	sq->length = 0;*/
	sq = (Sqlist*)malloc(sizeof(Sqlist));
	sq->length = 0;
	int j,i = 0;
	char k;
	printf("请输入顺序表的值：\n");
	for(j=0;j<10;j++) {
		scanf_s("%d", &(sq->data[j]));
		sq->length++;
	}
	//printf("length = %d\n",sq->length);
	for (i = 0,j=(sq->length)-1; i < sq->length / 2; i++,j--) {
		k = sq->data[i];
		sq->data[i] = sq->data[j];
		sq->data[j] = k;
	//	printf("%d: sq->data[%d] : %d    sq->data[%d] : %d \n",i,i, sq->data[i], j,sq->data[j]);
	}
	printf("\n结果是：\n");
	for (i = 0; i < sq->length; i++) {
		printf("%d ", sq->data[i]);
	}
	printf("\n");
}

//1-4 设计一个算法，从一给定的顺序表L中输出下标i~j（i<=j）的所有元素，假定i,j都是合法的
void c4() {
	struct Sqlist* sq;
	int i, j, k;
	sq = (Sqlist*)malloc(sizeof(Sqlist));
	sq->length = 0;
	printf("请输入顺序表的值：\n");
	for (j = 0; j < 10; j++) {
		scanf_s("%d", &(sq->data[j]));
		sq->length++;
	}
	printf("请输入i和j\n");
	scanf_s("%d", &i);
	scanf_s("%d", &j);
	for (k = i; k <= j; k++) {
		printf("%d  ", sq->data[k]);
	}
	printf("\n");
}

//1-5 有一个顺序表L，其元素为整型数据，设计一个算法，将L中所有小于表头元素的整数放在前半部分，
//大于表头元素的放于后半部分
void c5(Sqlist* sq) { 
	int temp;
	int i = 0, j = sq->length - 1;
	temp = sq->data[i];
	while (i < j) {
		while (i<j && sq->data[j]>temp)
			--j;
		if (i < j) {
			sq->data[i] = sq->data[j];
			++i;
		}
		while (i < j && sq->data[i] < temp)
			++i;
		if (i < j) {
			sq->data[j] = sq->data[i];
			--j;
		}
	}
	sq->data[i]=temp;
	for (i = 0; i < sq->length; i++)
		printf("%d ", sq->data[i]);
	printf("\n");
}

//1-6 有一个递增非空单链表，设计一个算法删除值域重复的结点。例如，{ 1,1,2,3,3,3,4,4,7,7,7, 9,9,9}删除后变成{1,2,3,4,7,9}
void c6(LNode* L) {
	struct LNode* p = L->next, * q; 
	while (p->next != NULL) {
		if (p->data == p->next->data) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
}

//1-7 设计一个算法删除单链表L（有头结点）中的一个最小值结点
void c7(LNode* L) {
	struct LNode* min, * minpre, * s, * pre;
	pre = L;
	s = pre->next;
	min = s;
	minpre = pre;
	while (s != NULL) { 
		if (s->data < minpre->data) {
			min = s;
			minpre = pre;
		}
		pre = s;
		s = s->next;
	}
	//删除结点
	minpre->next = min->next;
	free(min);
}

//1-8 有一个线性表，采用带头结点的单链表L来存储。设计一个算法将其逆置。
//要求不能建立新结点，只能通过表中已有结点的重新组合来完成
void c8(LNode *L) {
	LNode* p=L->next,*q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next; 
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

//1-9 设计一个算法，将一个头结点为A的单链表分解成两个单链表A和B，使得A链表中只含有原来链表中data域为奇数的结点，
//而B链表只含有原链表中data域为偶数的结点，且保持原来的相对顺序
void c19(LNode *A,LNode *B) {
	LNode* r, * t, * s;
	B = (LNode*)malloc(sizeof(LNode));
	B->next = NULL;
	r = A;
	t = B;
	while (r->next != NULL) {
		if (r->next->data % 2 == 0) {
			t->next = r->next;
			t = t->next;
		}
		s = r->next;
		r->next = r->next->next;
		free(s);
	}
}


//2-1 有N个个位正整数存放在int型数组A[1,...,N-1]中，N为已定义的常量且N<=9，数组A[]的长度为N，另给一个int型变量i，
//要求只用上诉变量写一个算法，找出N个整数中的最小值，并不能破坏数组A[]的数据
void c21() {
	int A[9] = { 1,2,3,6,5,4,7,0,8 };
	int i,min;
	min = A[0];
	for (i = 1; i < 9; i++) {
		min = min < A[i] ? min : A[i];
	}
	printf("最小值是：%d\n",min);
}


//2-2 写一个函数，逆序打印单链表L中的数据
char c22(LNode *s) {
	if (s != NULL) {
		c22(s->next);
		printf("%d ", s->data);
	}
	printf("\n");
}


//2-3 试编写一个函数，以不多于3*n/2的平均比较次数，在一个有n个整数的顺序表A中找出最大值和最小值
void c23() {
	Sqlist* sq;
	sq = NULL;
	int i = 0, j, k;
	//sq->data[10] = { 1,3,4,6,7,31,4,5,67,3 };
	while ((sq->data[i] = getchar()) != "\n") {
		i++;
		(sq->length)++;
	}
	int max = sq->data[0];
	int min = sq->data[0];
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] > max) {
			max = sq->data[i];
		}
		else {
			if (sq->data[i] < min) {
				min = sq->data[i];
			}
		}
	}
	printf("max = %d\n min = %d\n", max, min);
}

//2-4 
void c24(Sqlist* A, Sqlist* B) {
	Sqlist* A1, * B1;
	A1 = NULL;
	A1->length = 0;
	B1 = NULL;
	B1->length = 0;
	int i, j = 0 , k;
	for (i = 0; i < A->length || i < B->length; i++) {
		if (A->data[i] != B->data[i]) {
			A1->data[j] = A->data[i];
			A1->length++;
			B1->data[j] = B->data[i];
			B1->length++;
			j++;
		}
	}
	if (A1->length == 0 && B1->length == 0) {
		printf("A = B\n");
	}
	else if ((A1->length == 0 && B1->length != 0) || (A1->data[0] < B1->data[0])) {
		printf("A < B\n");
	}
	else {
		printf("A > B\n");
	}
}

int main() {
	/*struct Sqlist* sq;
	sq = (Sqlist*)malloc(sizeof(Sqlist));
	sq->length = 0;
	int j;
	printf("请输入顺序表的值：\n");
	for (j = 0; j < 10; j++) {
		scanf_s("%d", &(sq->data[j]));
		sq->length++;
	}*/
	struct LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	L ->next = NULL;
	int a[10] = { 1,1,1,2,3,4,4,5,5,6 };
	createlistF(L, a, 10);
	c6(L);
	return 0;
}