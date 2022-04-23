#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	if (!q || !q->head){
		return;
	}
	intNode* current = q->head, *tmp =NULL;
	while (current->next) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = newNode(data);
	if (isEmptyQueue(q) == 1)
	{
		q->head = q->tail = temp;
		return;
	}
	q->tail->next = temp;
	q->tail = temp;
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q) == 1)
	{
		printf("the queue is empty");
		return -1;
	}
	intNode* temp = q->head;
	int data = temp->data;
	q->head = q->head->next;
	if (q->head == NULL)
		q->tail = NULL;
	free(temp);
	return data;
}

int isEmptyQueue(const Queue* q)
{
	if (!q->head) {
		return 1;
	}
	return 0;
}

void printList(Queue* q) {
	intNode* current = q->head;
	while (current) {
		printf(" %d", current->data);
		current = current->next;
	}
	printf("\n");
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	return;
}

void cutAndReplace(Queue* q)
{
	return;
}

void sortKidsFirst(Queue* q)
{
	int* tmp_arr = (int*)malloc(sizeof(int)); //creating dynamic array
	if (!tmp_arr) {
		printf("Allocation memory problem\n");
		exit(1);
	}
	if ((q->head == q->tail) && (q->head->next == NULL)) { 
		printf("The queue has only one element or the queue is empty\n"); //checking if the queue is empty or has one element
		return;
	}
	int min, place_saving; //creating to integers
	int counter = 1;
	tmp_arr[0] = dequeue(q);
	if (isEmptyQueue(q) == 1) {
		printf("Empty queue input\n");
		return;
	}
	for (int i = 1; isEmptyQueue(q) != 1; i++) { //isert the number's in the array
		tmp_arr = (int*)realloc(tmp_arr, sizeof(int) * (i + 1));
		if (!tmp_arr) {
			printf("Allocation memory problem\n");
			exit(1);
		}
		tmp_arr[i] = dequeue(q);
		counter = i;
	}
	for (int j = 0; j <= counter; j++) { //sets the queue by searching for the minimus value
		min = tmp_arr[j];
		for (int i = j + 1; i <= counter; i++) {
			if (min > tmp_arr[i]) {
				min = tmp_arr[i];
				place_saving = i; //saving the place of the minimum value
			}
		}
		tmp_arr[place_saving] = tmp_arr[j]; 
		tmp_arr[j] = min;
		enqueue(q, min); //set's the array
	}
	free(tmp_arr); //free the dynamic array
}

intNode* newNode(int k)
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	if (!temp) {
		printf("Allocation memory faild\n");
		exit(1);
	}
	temp->data = k;
	temp->next = NULL;
	return temp;
}
