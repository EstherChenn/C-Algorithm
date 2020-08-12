#include <stdio.h>
#include <malloc.h>

#define maxsize 5

//˳�����
typedef struct SqQueue {
	int data[maxsize];
	int front;	//����ָ��
	int rear;	//��βָ��
}SqQueue;

//���Ӷ���
//�ӽ��
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;
//����
typedef struct LiQueue {
	QNode* front;	//��ͷָ��
	QNode* rear;	//��βָ��
}LiQueue;

//��ʼ������
void SqQueue_init(SqQueue *sq) {
	sq->front = 0;
	sq->rear = 0;
}

//�ж϶ӿ��㷨
int SqQueue_isEmpty(SqQueue* sq) {
	if (sq->rear == sq->front) {
		return 1;
	}
	else {
		return 0;
	}
}

//�����㷨
int SqQueue_en(SqQueue** sq, int x) {
	//�ж��Ƿ����
	if ((*sq)->front == (*sq)->rear) {
		return 0;
	}
	(*sq)->rear = ((*sq)->rear + 1) % maxsize;
	(*sq)->data[(*sq)->rear] = x;
	return 1;
}

//�����㷨
int SqQueue_out(SqQueue** sq) {
	int x;
	//�ж��Ƿ�ӿ�
	if ((*sq)->front == (*sq)->rear)
		return 0;
	(*sq)->front = ((*sq)->front + 1) % maxsize;
	x = (*sq)->data[(*sq)->front];
	return 1;
}
 
//��ʼ������
void LiQueue_init(LiQueue** lqu) {
	*lqu = (LiQueue*)malloc(sizeof(LiQueue));
	(*lqu)->front = NULL;
	(*lqu)->rear = NULL;
}

//�ж϶ӿ��㷨
int LiQueue_isEmpty(LiQueue* lqu) {
	if ((lqu->rear == NULL) || (lqu->front == NULL)) {
		return 1;
	}
	else {
		return 0;
	}
}

//��������㷨
int LiQueue_en(LiQueue** lqu, int x) {
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	//���ӿգ����½���Ƕ��׽�㣬Ҳ�Ƕ�β���
	if ((*lqu)->rear == NULL) {
		(*lqu)->front = p;
		(*lqu)->rear = p;
	}
	else {
		(*lqu)->rear->next = p;
		(*lqu)->rear = p;
	}
}


//���ӳ����㷨
int LiQueue_out(LiQueue** lqu) {
	int x;
	QNode* p;
	//���ӿ�
	if ((*lqu)->rear == NULL) {
		return 0;
	}
	else {
		p = (*lqu)->front;
	}
	//����ֻ��һ�����ʱ�����⴦��
	if ((*lqu)->front == (*lqu)->rear) {
		(*lqu)->front = NULL;
		(*lqu)->rear = NULL;
	}
	else {
		(*lqu)->front = (*lqu)->front->next;
	}
	x = p->data;
	free(p);
	return 1;
}

int main() {

}