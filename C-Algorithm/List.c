#include <stdio.h>

#define maxsize 4
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
		scanf_s("%d", &(sq->data[i]));
		printf("%d = %d \n", i,sq->data[i]);
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
}

//��ʼ��������
void initList(LNode* C) {
	C = (LNode*)malloc(sizeof(LNode));
	if (C == NULL)
		printf("����ʧ��\n");
	C->data = NULL;
}

//ͷ�巨��������(��n��Ԫ���Ѿ��洢������a�У���β�巨����������C)
void createlistF(LNode* C, int a[], int n) {
	LNode *s; 
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
	for (i = 0; i < n; i++) {
		printf("%d ", C->data);
		C = C->next;
	}
}
//β�巨��������(��n��Ԫ���Ѿ��洢������a�У���β�巨����������C)
void createlistR(LNode* C, int a[], int n) {
	//s����ָ��������Ľ�㣬r����ָ��C���ն˽��
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

//�鲢����

//ɾ��

//����


int main() {
	LNode* C;
	int i;
	int a[4] = {1,2,3,4};
//	initList(&C);
	createlistF(&C, a, 4);
	return 0;
}