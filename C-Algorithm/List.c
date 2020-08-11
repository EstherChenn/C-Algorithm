#include <stdio.h>

#define maxsize 4
//˳���Ľṹ�嶨��
typedef struct Sqlist {
	int data[maxsize];
	int length;
}Sqlist;

//�������㶨��
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

//˫�����㶨��
typedef struct DLNode {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;

//��ʼ��˳���
void Sqlist_create(Sqlist* sq, int len) {
	int i;
	sq->length = len;
	for (i = 0; i < len; i++) {
		scanf_s("%d", &(sq->data[i]));
		//	printf("%d = %d \n", i,sq->data[i]);
	}
}

//˳���Ĳ���
int Sqlist_find(Sqlist* sq, int x) {
	int i;
	for (i = 0; i < sq->length; i++) {
		if (sq->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//˳���Ĳ���(x�ǲ���ֵ,k�ǲ���λ��)
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

//˳����ɾ������(ɾ���±�Ϊp��Ԫ��)
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

//��ʼ��������
void LNode_initList(LNode* C) {
	C = (LNode*)malloc(sizeof(LNode));
	if (C == NULL)
		printf("����ʧ��\n");
	C->next = NULL;
}

//ͷ�巨��������(��n��Ԫ���Ѿ��洢������a�У���ͷ�巨����������C)
void LNode_createlistF(LNode* C, int a[], int n) {
	LNode* s;
	int i;
	//ͷ����ĵ�һ�����
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
//β�巨��������(��n��Ԫ���Ѿ��洢������a�У���β�巨����������C)
void LNode_createlistR(LNode** C, int a[], int n) {
	//s����ָ��������Ľ�㣬r����ָ��C���ն˽��
	LNode* s, * r;
	int i;
	//C��ͷ�������ռ�
	*C = (LNode*)malloc(sizeof(LNode));
	//	C->data = NULL;
	(*C)->next = NULL;
	//rָ��ͷ���
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

//�鲢����A��B���ǰ�Ԫ�ص������򣬽�A��B�鲢��һ����Ԫ��ֵ�ǵݼ����������C,C��A��B�еĽ����ɣ�
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

//���Һ�ɾ��
int LNode_FindAndDelete(LNode* C, int x) {
	LNode* p, * q;
	p = C;
	while (p->next != NULL) {
		if (p->next->data == x)
			break;
		p = p->next;
	}
	if (p->next == NULL) {
		printf("����ʧ��\n");
		return 0;
	}
	else {
		q = p->next;
		p->next = p->next->next;
		//	free(q);
		return 1;
	}
}

//β�巨����˫����
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

//˫������ҽ��
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

//˫���������
void DLNode_insert(DLNode* C, DLNode* s) {
	DLNode* p = C->next;
	s->next = p->next;
	s->prior = p;
	p->next = s;
	s->next->prior = s;
}

//˫����ɾ�����
void DLNode_delete(DLNode* C, DLNode* p) {
	DLNode* q = p->next;
	p->next = q->next;
	q->next->prior = p;
	//	free(q);
}

//1.3 ���һ���㷨����˳����е�����Ԫ������
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

//1.4 ���һ���㷨����һ������˳���L��ɾ���±��i��j��i<=j,����i��j��������Ԫ�أ��ٶ�i,j���ǺϷ���
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

//1.5 ��һ��˳���L����Ԫ��Ϊ�������ݣ����һ���㷨����L������С�ڱ�ͷԪ�ص���������ǰ�벿�֣����ڱ�ͷԪ�ص��������ں�벿��
void Sqlist_biao(Sqlist* q) {
	int head, i, j, index;
	int ma = 0, mi = 0;
	head = q->data[0];
	for (i = 1; i < q->length; i++) {
		if (head > q->data[0]) {
			//mi-(i-1)��������һλ
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
//1.6 ��һ�������ǿյ��������һ���㷨ɾ��ֵ���ظ��Ľ�㡣����{1��1��2��3��3��3��4��5��7��7��7��9��9��9}����ɾ������{1��2��3��4��7��9}
void LNode_delNode(LNode** L) {
	int i;
	//*sָ��L�ĵ�ǰ��㣬*rָ����һ���
	LNode* s, * r;
	s = *L;
	r = s->next;
	while (r != NULL) {
		//�����ȣ���sָ��r����һָ�룬���ͷ�r
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

//1.7 ���һ���㷨ɾ��������L����ͷ��㣩�е�һ����Сֵ���
void LNode_delmin(LNode* L) {
	int min;
	//*sָ��ǰ���,*r��¼��Сֵ��,*aָ��ǰ����ǰһ��,*m��¼��Сֵ��ǰһ�����
	LNode* s, * r, * a, * m;
	a = L;
	m = L;
	r = L->next;
	s = L->next;
	//Ѱ�ҽ��
	while (s->next != NULL) {
		if (s->data < min) {
			min = s->data;
			r = s;
			m = a;
		}
		s = s->next;
		a = a->next;
	}
	//ɾ�����
	m->next = r->next;
	free(r);
}

//1.8 ��һ�����Ա�����ͷ���ĵ�����L���洢�����һ���㷨�������á�Ҫ���ܽ����½�㣬ֻ��ͨ���������н���������������
void LNode_invert(LNode* L) {
	//*sָ��ǰ���,*rָ��ǰ������һ��㣬*fָ��ǰ����ǰһ�����
	LNode* s, * r, * f;
	f = s;
	s = f->next;
	r = s->next;
	while (s->next != NULL) {
	}
}

//1.9 ���һ���㷨����һ��ͷ���ΪA�ĵ�������������Ϊ�������ֽ������������A��B��ʹ��A����ֻ����ԭ��������data��Ϊ�����Ľ�㣬��B������ֻ����ԭ������
//data��Ϊż���Ľ�㣬�ұ���ԭ�������˳��

//2.2 дһ�������������ӡ�������е����ݣ�����ָ��Lָ���˵�����Ŀ�ʼ���

//2.3 �Ա�дһ���������Բ�����3n/2��ƽ���Ƚϴ�������һ����n��������˳���A���ҳ����ֵ����Сֵ

int main() {
	/*LNode* A;
	LNode* A1;
	LNode* B;
	LNode* B1;
	LNode* C;
	int a[4] = { 4,5,7,8 };
	int b[6] = { 1,2,3,4,5,6 };
	printf("A��\n");
	LNode_createlistR(&A,a,4);
	A1 = A->next;
	printf("B��\n");
	LNode_createlistR(&B, b, 6);
	B1 = B->next;
	printf("C��\n");
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