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
	for (i = 0; sentence[i] != '\0'; i++) {
		push(s, sentence[i]);
	}

	isPalindrome(s);
	flipBetweenHashes(check);

	Queue* q = NULL;
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

	printf("Checing if the function rotateQueue working: ");
	rotateQueue(q);
	printList(q);


	printf("Checing if the function cutAndReplace working: ");
	cutAndReplace(q);
	printList(q);

	printf("Checing if the function sortKidsFirst working: ");
	sortKidsFirst(q);
	printList(q);
	destroyQueue(q);

}