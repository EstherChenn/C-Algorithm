#include <stdio.h>

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

int main() {

}