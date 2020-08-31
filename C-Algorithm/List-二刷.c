#include <stdio.h>
#include <malloc.h>

#define maxsize 100

//˳���
typedef struct Sqlist {
	char data[maxsize];
	int length;
}Sqlist;

//������
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//˫����
typedef struct DLNode{
	int data;
	struct DLNode* prior;
	struct DLNode* next;

}DLNode;

//�������β�巨
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

//�������ͷ�巨
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

//˫�����β�巨
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

//����1
void zt1() {
	int a[10] = { 1,3,5,7,9,2,2,6,8,10 };
	int m = 5, n = 5;
	int i, j, k, s;
	j = m;
	for (i = 0; i < 10; i++) {
		while (a[j] < a[i]) {
			s = a[j];
			//i-j֮������ֺ���һλ
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

//����2
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

//1-3 ���һ���㷨����˳����е�����Ԫ������
void c3() {
	struct Sqlist *sq;  
	/*sq = NULL;
	sq->length = 0;*/
	sq = (Sqlist*)malloc(sizeof(Sqlist));
	sq->length = 0;
	int j,i = 0;
	char k;
	printf("������˳����ֵ��\n");
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
	printf("\n����ǣ�\n");
	for (i = 0; i < sq->length; i++) {
		printf("%d ", sq->data[i]);
	}
	printf("\n");
}

//1-4 ���һ���㷨����һ������˳���L������±�i~j��i<=j��������Ԫ�أ��ٶ�i,j���ǺϷ���
void c4() {
	struct Sqlist* sq;
	int i, j, k;
	sq = (Sqlist*)malloc(sizeof(Sqlist));
	sq->length = 0;
	printf("������˳����ֵ��\n");
	for (j = 0; j < 10; j++) {
		scanf_s("%d", &(sq->data[j]));
		sq->length++;
	}
	printf("������i��j\n");
	scanf_s("%d", &i);
	scanf_s("%d", &j);
	for (k = i; k <= j; k++) {
		printf("%d  ", sq->data[k]);
	}
	printf("\n");
}

//1-5 ��һ��˳���L����Ԫ��Ϊ�������ݣ����һ���㷨����L������С�ڱ�ͷԪ�ص���������ǰ�벿�֣�
//���ڱ�ͷԪ�صķ��ں�벿��
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

//1-6 ��һ�������ǿյ��������һ���㷨ɾ��ֵ���ظ��Ľ�㡣���磬{ 1,1,2,3,3,3,4,4,7,7,7, 9,9,9}ɾ������{1,2,3,4,7,9}
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

//1-7 ���һ���㷨ɾ��������L����ͷ��㣩�е�һ����Сֵ���
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
	//ɾ�����
	minpre->next = min->next;
	free(min);
}

//1-8 ��һ�����Ա����ô�ͷ���ĵ�����L���洢�����һ���㷨�������á�
//Ҫ���ܽ����½�㣬ֻ��ͨ���������н���������������
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

//1-9 ���һ���㷨����һ��ͷ���ΪA�ĵ�����ֽ������������A��B��ʹ��A������ֻ����ԭ��������data��Ϊ�����Ľ�㣬
//��B����ֻ����ԭ������data��Ϊż���Ľ�㣬�ұ���ԭ�������˳��
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


//2-1 ��N����λ�����������int������A[1,...,N-1]�У�NΪ�Ѷ���ĳ�����N<=9������A[]�ĳ���ΪN�����һ��int�ͱ���i��
//Ҫ��ֻ�����߱���дһ���㷨���ҳ�N�������е���Сֵ���������ƻ�����A[]������
void c21() {
	int A[9] = { 1,2,3,6,5,4,7,0,8 };
	int i,min;
	min = A[0];
	for (i = 1; i < 9; i++) {
		min = min < A[i] ? min : A[i];
	}
	printf("��Сֵ�ǣ�%d\n",min);
}


//2-2 дһ�������������ӡ������L�е�����
char c22(LNode *s) {
	if (s != NULL) {
		c22(s->next);
		printf("%d ", s->data);
	}
	printf("\n");
}


//2-3 �Ա�дһ���������Բ�����3*n/2��ƽ���Ƚϴ�������һ����n��������˳���A���ҳ����ֵ����Сֵ
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
	printf("������˳����ֵ��\n");
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