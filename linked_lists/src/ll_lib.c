#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll_lib.h"


// function to print all elements in the linked list which starts with node head
void print_list(node_t * head)
{
	node_t * current = head;

	while (current != NULL)
	{
		printf("- Name: %s \tAge: %d \tNext: %p \t(add=%p)\n", current->name, current->age, (void *)(current->next), (void *)(current));
		current = current->next;
	}
}

// add an element with name name and age age to the end of the linked list which starts with node head
int add_end(node_t *head, char * name_n, int age_n)
{
	node_t * current = head;

	// cycle through list until next is null
	while (current->next != NULL)
	{
		current = current->next;
	}

	// add new element
	current->next = malloc (sizeof(node_t));
    if ((current->next) == NULL) return 0;

    current->next->age = age_n;
	
	current->next->name = (char*) malloc (sizeof(char) * MAX_CHARACTERS);
	strncpy (current->next->name, name_n, strlen(name_n)); 
	current->next->name[strlen(name_n)] = '\0';

	current->next->next = NULL;

	return 1;
}

// push en element with name name and age age to the beginning of the list and change head to point to the new first element
int push(node_t ** head, char * name_n, int age_n) 
{
	node_t * new;

	new = (node_t *) malloc (sizeof(node_t));
	if (new == NULL) return 0;

	new->name = (char *) malloc (sizeof(char) * MAX_CHARACTERS);
	if (new->name == NULL) return 0;
	strncpy(new->name, name_n, strlen(name_n));
	new->name[strlen(name_n)] = '\0';

	new->age = age_n;

	// new is the new head, head becomes second element
	//printf("head: %p new: %p new->next: %p\n", *head, new, new->next);
	new->next = *head;
	*head = new;
	//printf("head: %p new: %p new->next: %p\n", *head, new, new->next);

	return 1;
}

// remove one item from the end of the list started by head
int remove_end(node_t * head)
{
	node_t * current;
	current = head;
	if (current == NULL) return 0;

	if (current->next == NULL) 
	{
		free(head->name);
		free(head);
		return 1;
	}

	// find the element before the last
	while (current->next->next != NULL)
	{
		current = current->next;
	}

	free(current->next->name);
	free(current->next);
	current->next = NULL;

	return 1;

}

// remove one item from the beginning of the list started by head
int pop(node_t ** head)
{
	node_t * to_pop = *head;

	if ((*head)->next == NULL) {
		free((*head)->name);
		free(*head);
		return 1;
	}

	*head = (*head)->next;
	free(to_pop->name);
	free(to_pop);

	return 1;
}
