#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack* s = NULL;
	const char check[27] = "Remem#reb# thi#carp s#tice";
	char sentence[5] = "noon";
	s = (Stack*)malloc(sizeof(Stack));
	if (!s) {
		printf("memory allocation problem\n");
		exit(1);
	}
	int i;
	s->head = NULL;
	push(s, '\0');
	for (i = 0; sentence[i] != '\0'; i++) {
		push(s, sentence[i]);
	}
	flipBetweenHashes(check);
	if(isPalindrome(s) == 1) {
		printf("The sentence is Palindrome\n");
	}
	else {
		printf("The sentence isn't Palindrome\n");
	}
	initStack(s);
	push(s, 'A');
	push(s, 'B');
	push(s, 'C');
	push(s, 'D');
	push(s, 'E');
	push(s, 'F');
	rotateStack(s, 3);
	printStack(s);
	destroyStack(s);

	/*Queue* q = NULL;
	q = (Queue*)malloc(sizeof(Queue));
	if (!q) {
		printf("Allocation memory problem\n");
		exit(1);
	}
	initQueue(q);
	int arr[6] = { 114, 159, 122, 121, 111, 186 };
	printf("The original queue is:");
	for (int i = 0; i < 6; i++) {
		enqueue(q, arr[i]);
		printf(" %d", arr[i]);
	}
	printf("\n");

	rotateQueue(q);
	printf("Check if the function rotateQueue is working:");
	printQueue(q);

	cutAndReplace(q);
	printf("Check if the function cutAndReplace is working:");
	printQueue(q);

	sortKidsFirst(q);
	printf("Check if the function sortKidsFirst is working:");
	printQueue(q);
	destroyQueue(q);*/

	Queue* q = NULL;
	q = (Queue*)malloc(sizeof(Queue));
	if (!q) {
		printf("Allocation memory problem\n");
		exit(1);
	}
	initQueue(q);
	enqueue(q, 6);
	enqueue(q, 1);
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 1);
	enqueue(q, 9);
	//cutAndReplace function cheack: //////
	printf("the current queue : ");
	printQueue(q);
	cutAndReplace(q);
	printf("\nthe queue after cutandreplace: ");
	printQueue(q);
	//rotateQueue function cheack: //////
	rotateQueue(q);
	printf("\nthe queue after rotate: ");
	printQueue(q);
}