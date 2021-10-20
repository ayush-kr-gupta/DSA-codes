/* Program to insert in a sorted list */
#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
};


void sortedInsert(struct Node** head_ref,
				struct Node* new_node)
{
	struct Node* current;
	
	if (*head_ref == NULL
		|| (*head_ref)->data
			>= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		
		current = *head_ref;
		while (current->next != NULL
			&& current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}



/* A utility function to create a new node */
struct Node* newNode(int new_data)
{
	/* allocate node */
	struct Node* new_node
= (struct Node*)malloc(
sizeof(struct Node));


	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	
	struct Node* head = NULL;
	struct Node* new_node = newNode(45);
	sortedInsert(&head, new_node);
	new_node = newNode(104);
	sortedInsert(&head, new_node);
	new_node = newNode(76);
	sortedInsert(&head, new_node);
	new_node = newNode(33);
	sortedInsert(&head, new_node);
	new_node = newNode(13);
	sortedInsert(&head, new_node);
	new_node = newNode(95);
	sortedInsert(&head, new_node);
	printf("\n Created Linked List\n");
	printList(head);

	return 0;
}

