#include <stdio.h>
#include <malloc.h>

#define maxsize 5

//顺序队列
typedef struct SqQueue {
	int data[maxsize];
	int front;	//队首指针
	int rear;	//队尾指针
}SqQueue;

//链队定义
//队结点
typedef struct QNode {
	int data;
	struct QNode* next;
}QNode;
//链队
typedef struct LiQueue {
	QNode* front;	//队头指针
	QNode* rear;	//队尾指针
}LiQueue;

//初始化队列
void SqQueue_init(SqQueue *sq) {
	sq->front = 0;
	sq->rear = 0;
}

//判断队空算法
int SqQueue_isEmpty(SqQueue* sq) {
	if (sq->rear == sq->front) {
		return 1;
	}
	else {
		return 0;
	}
}

//进队算法
int SqQueue_en(SqQueue** sq, int x) {
	//判断是否队满
	if ((*sq)->front == (*sq)->rear) {
		return 0;
	}
	(*sq)->rear = ((*sq)->rear + 1) % maxsize;
	(*sq)->data[(*sq)->rear] = x;
	return 1;
}

//出队算法
int SqQueue_out(SqQueue** sq) {
	int x;
	//判断是否队空
	if ((*sq)->front == (*sq)->rear)
		return 0;
	(*sq)->front = ((*sq)->front + 1) % maxsize;
	x = (*sq)->data[(*sq)->front];
	return 1;
}
 
//初始化链队
void LiQueue_init(LiQueue** lqu) {
	*lqu = (LiQueue*)malloc(sizeof(LiQueue));
	(*lqu)->front = NULL;
	(*lqu)->rear = NULL;
}

//判断队空算法
int LiQueue_isEmpty(LiQueue* lqu) {
	if ((lqu->rear == NULL) || (lqu->front == NULL)) {
		return 1;
	}
	else {
		return 0;
	}
}

//链队入队算法
int LiQueue_en(LiQueue** lqu, int x) {
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	//若队空，则新结点是队首结点，也是队尾结点
	if ((*lqu)->rear == NULL) {
		(*lqu)->front = p;
		(*lqu)->rear = p;
	}
	else {
		(*lqu)->rear->next = p;
		(*lqu)->rear = p;
	}
}


//链队出队算法
int LiQueue_out(LiQueue** lqu) {
	int x;
	QNode* p;
	//若队空
	if ((*lqu)->rear == NULL) {
		return 0;
	}
	else {
		p = (*lqu)->front;
	}
	//队中只有一个结点时需特殊处理
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