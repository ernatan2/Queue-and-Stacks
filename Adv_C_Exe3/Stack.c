#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* tmp;
	while (isEmptyStack(s) != 1) {
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
	return;
}


void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (!newnode) {
		printf("memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);
}

char pop(Stack* s)
{
	int res;
	res = s->head->data;
	removeItem(&(s->head));
	return (res);
}


int isEmptyStack(const Stack* s)
{
	if (!s->head) {
		return 1;
	}
	return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/


void flipBetweenHashes(const char* sentence)
{
	Stack* ptr_stk = NULL;
	ptr_stk = (Stack*)malloc(sizeof(Stack)); 
	charNode* tmp = NULL;
	int counter = 0;
	char* ptr_sentence = sentence;
	if (!ptr_stk) { //checking if memory allocation succedded
		printf("Memory allocation problem\n");
		exit(1);
	}
	if (!sentence) { // checking if sentence dousn't have a value
		return sentence;
	}
	
	while (*ptr_sentence != '\0') {
		if (*ptr_sentence == '#') {
			counter++;
		}
		ptr_sentence++;
	}
	if ((counter % 2) || !(counter)) { // checking if there is a even number of #
		printf("Odd number of '#'\n");
		return;
	}
	while (*sentence != '\0') {
		if (*sentence == '#') {
			sentence++;
			counter = 0;
			while (*sentence != '#') { 
				push(ptr_stk, *sentence); //sets the latters in the stack
				sentence++;
				counter++;
			}
	        tmp = ptr_stk->head;
			for (int i = 0; i < counter; i++) { // print's the stack
				printf("%c", tmp->data);
				tmp = tmp->next;
			}
			for (int i = 0; i < counter; i++) { //
				pop(ptr_stk);
				
			}
		}
		else {
			printf("%c", *sentence);
		}
		sentence++;
	}
	printf("\n");
}


int isPalindrome(Stack* s)
{
	char* sentence = NULL;
	Stack* c_s = NULL; // creating a new stack and sentence to compare
	int counter = 0;
	c_s = (Stack*)malloc(sizeof(Stack));
	if (!c_s) {
		printf("memory allocation problem\n");
		exit(1);
	}
	c_s->head = NULL; //set's the first value in the stack to NULL
	if (!s) {
		return;
	}
	sentence = (char*)malloc(sizeof(char));
	if (!sentence) {
		printf("memory allocation problem\n");
		exit(1);
	}
	while (isEmptyStack(s) == 1) { // input the varuble's from the stack that we got from the user into new stack and sentence
		*(sentence + counter) = pop(s);
		push(c_s, *(sentence + counter));
		counter++;
		sentence = realloc(sentence, counter + 1);
		if (!sentence) {
			printf("memory allocation problem\n");
			exit(1);
		}
	}
	for (int i = 0; i < counter; i++) { //checks if the sentence and the stack are equal
		if (pop(c_s) != *(sentence + i)) { // if the sentence and the stack aren't equal the 'if' statement will free the memory and return imidiatlly 0
			destroyStack(c_s);
			free(sentence);
			return 0;
		}


		free(sentence);
		return 1; // if the sentence and the stack are equal than the function willl free the memory and return 1
	}
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

charNode *addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}

void removeItem(charNode** head) {
	if (*head == NULL) {
		return; //If stack is empty
	}
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}