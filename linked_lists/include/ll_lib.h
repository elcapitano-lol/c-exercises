#ifndef _LL_LIB_H_

	#define MAX_CHARACTERS 50

	typedef struct node {
		char * name;
		int age;
		struct node * next;	
	} node_t;

	// function to print all elements in the linked list which starts with node head
	void print_list(node_t * head);

	// add an element with name name and age age to the end of the linked list which starts with node head
	int add_end(node_t *head, char * name_n, int age_n);

	// push en element with name name and age age to the beginning of the list and change head to point to the new first element
	int push(node_t ** head, char * name_n, int age_n);

	// remove one item from the end of the list started by head
	int remove_end(node_t * head);

	// remove one item from the beginning of the list started by head
	int pop(node_t ** head);

#endif