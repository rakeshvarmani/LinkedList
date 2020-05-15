#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};
 
/*Print the linked list*/
void print_list(struct node *head)
{
    printf("H->");
 
    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
 
    printf("|||\n");
}
 
/*Insert an element at the front of the list*/
void insert_front(struct node **head, int value)
{
    struct node * new_node = NULL;
 
    /*Allocating memory for the new node*/
    new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }
 
    new_node->val = value;
 
    /*Pointing the new node to where head is currently pointing to*/
    new_node->next = *head;
 
    /*Pointing head to new node.*/
    *head = new_node;
}

void insert_rear(struct node **head, int value)
{
    struct node * new_node = NULL;
    struct node *temp_node = *head; 
    /*Allocating memory for the new node*/
    new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }
 
    new_node->val = value;
    new_node->next = NULL;
    if(*head == NULL)
        *head = new_node;
    else
    {
        while(temp_node->next != NULL)
        {
            temp_node = temp_node->next;
        }
            temp_node->next = new_node;
    }
}
 
void main()
{
    int count = 0, i, val;
    struct node * head = NULL;
 
    printf("Enter number of elements: ");
    scanf("%d", &count);
 
    for (i = 0; i < count; i++)
    {
        //printf("Enter %dth element: ", i);
        //scanf("%d", &val);
       // insert_front(&head, i);
            insert_rear(&head, i);
    }
 
    printf("Linked List: ");
    print_list(head);
}
