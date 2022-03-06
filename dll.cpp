// A complete working C++ program to demonstrate all insertion methods
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data ;
	Node* next;
	Node* prev;
};

//Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list
void push(Node** head_ref, int new_data)
{
	/* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head
    and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node as prev_node, insert
a new node after the given node */
void insertAfter(Node* prev_node, int new_data)
{
    //1. check if the given prev_node is NULL 
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
 
    // 2. allocate new node 
    Node* new_node = new Node();
 
    // 3. put in the data */
    new_node->data = new_data;
 
    // 4. Make next of new node as next of prev_node 
    new_node->next = prev_node->next;
 
    // 5. Make the next of prev_node as new_node 
    prev_node->next = new_node;
 
    // 6. Make prev_node as previous of new_node 
    new_node->prev = prev_node;
 
    // 7. Change previous of new_node's next node 
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head of a DLL and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
	// 1. allocate node 
	Node* new_node = new Node();

	Node* last = *head_ref; /* used in step 5*/

	// 2. put in the data 
	new_node->data = new_data;

	// 3. This new node is going to be the last node, so make next of it as NULL
	new_node->next = NULL;

	// 4. If the Linked List is empty, then make the new node as head 
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	// 5. Else traverse till the last node 
	while (last->next != NULL)
		last = last->next;

	// 6. Change the next of last node 
	last->next = new_node;

	// 7. Make last node as previous of new node 
	new_node->prev = last;

	return;
}

//Function to remove the first node of the linked list
void deleteFirst(Node **head)
{
    //1. Traverse to the second last element of the list
	Node *temp = *head;
    (*head) = temp->next;
    //2. Change the next of the second last node to null and delete the last node
	temp->next = NULL;
    (*head)->prev = NULL;
}

//Function to remove the last node of the linked list
void deleteLast(Node **head)
{
    //Find the node, delete the node and change next of the node
	Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
}

//Function to remove after node of the linked list
void deleteAfter(Node *prev_node)
{
    Node *temp = prev_node->next;
    prev_node->next = prev_node->next->next;
    prev_node->next->prev = prev_node;
    temp->next = NULL;
    temp->prev = NULL;
}

//This function to search the node on linked list
void searchNode(Node **head, int id)
{
    int currentID = 1;
    //1. create a temp node pointing to head
	Node *temp = *head;
    //2. if the temp node is not null check the node value with searchValue, if found 
  //   update variables and break the loop, else continue searching till temp node is not null 
	while (temp->next != 0 && currentID != id)
    {
        temp = temp->next;
        currentID++;
    }
    cout <<"\n" << temp->data << " is Found at " << currentID;
}

//This function prints contents of linked list
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

int main()
{
	Node* head = NULL;

	//inserting data to the list
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 12);
	append(&head, 4);
	insertAfter(head->next, 8);

	cout << "Created DLL is: ";
	printList(head);
	deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    
	cout << "\nDLL after deleted : ";
	printList(head);
	searchNode(&head, 3);
	return 0;
}
