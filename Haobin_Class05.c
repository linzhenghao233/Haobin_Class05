#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 6

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}Queue, * pQueue;

void Queue_Init(pQueue pQ);
bool Queue_Entry(pQueue pQ, int val);
void Queue_Traverse(pQueue pQ);
bool Queu_Out(pQueue pQ, int* val);

int main(void) {
	Queue Q;
	int val;

	Queue_Init(&Q);
	Queue_Entry(&Q, 1);
	Queue_Entry(&Q, 2);
	Queue_Entry(&Q, 3);
	Queue_Entry(&Q, 4);
	Queue_Entry(&Q, 5);
	Queue_Entry(&Q, 6);
	Queue_Entry(&Q, 7);
	Queue_Traverse(&Q);

	if (Queu_Out(&Q, &val))
		printf("出队的值是%d\n", val);
	Queue_Traverse(&Q);

	exit(0);
}

void Queue_Init(pQueue pQ) {
	pQ->pBase = (int*)malloc(LEN * sizeof(int));
	pQ->front = 0;
	pQ->rear = 0;
}

bool Queue_Entry(pQueue pQ, int val) {
	if ((pQ->rear + 1) % LEN == pQ->front) {
		printf("入队失败，队列已满！\n");
		return false;
	}
	pQ->pBase[pQ->rear] = val;
	pQ->rear = (pQ->rear + 1) % LEN;
	return true;
}

void Queue_Traverse(pQueue pQ) {
	for (int i = pQ->front; i < pQ->rear; i = (i + 1) % LEN) {
		printf("%d ", pQ->pBase[i]);
	}
	printf("\n");
}

bool Queu_Out(pQueue pQ, int* val) {
	if (pQ->front == pQ->rear) {
		printf("出队失败，队列为空！\n");
		return false;
	}
	*val = pQ->pBase[pQ->front];
	pQ->front = (pQ->front + 1) % LEN;
}
