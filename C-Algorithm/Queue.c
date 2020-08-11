#include <stdio.h>

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

int main() {

}