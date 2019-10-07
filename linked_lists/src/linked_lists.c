#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ll_lib.h"


int main () {
	
	node_t * head;
	int status = 1;
	
	// allocate memory for the head node	
	head = (node_t *) malloc (sizeof(node_t));
	if (head==NULL) return 0;	

	// populate head with a name and age
	head->name = (char *) malloc (sizeof(char) * MAX_CHARACTERS);
	strncpy(head->name, "Pedro Dias", strlen("Pedro Dias"));
	head->name[strlen("Pedro Dias")] = '\0';
	head->age = 26;
	head->next = NULL;

	printf("\nInitial list:\n");
	print_list(head);

	// add new elements to the end of the list
	printf("\nAdding new elements to the end of the list...\n");
	status = add_end(head, "Jimmy Page", 65);
	if (!status) return 0;
	status = add_end(head, "John Bonham", 66);
	if (!status) return 0;
		
	// print new list
	printf ("New list is:\n");
	print_list(head);

	// add new elements to the start of the list (push)
	printf("\nAdding new elements to the beginning of the list... (with double pointer)\n");
	// pass the address of the head pointer (casted to a pointer of a pointer)
	status = push((node_t**) (&head), "Pete Townshend", 35);
	if (!status) return 0;
	status = push((node_t**) (&head), "Keith Moon", 31);
	if (!status) return 0;

	// print new list
	printf ("New list is:\n");
	print_list(head);

	// remove elements from end of the list
	printf("\nRemoving the last elements of this list...\n");
	status = remove_end(head);
	if (!status) return 0;
	status = remove_end(head);
	if (!status) return 0;

	// print new list
	printf ("New list is:\n");
	print_list(head);

	// remove elements from beginning of the list (poping)
	printf("\nPopping the first elements of the list...\n");
	status = pop(&head);
	if (!status) return 0;
	status = pop(&head);
	if (!status) return 0;

	// print new list
	printf ("New list is:\n");
	print_list(head);

	return 1;	
}
