#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* list;
typedef struct node* position;
list l;position p,head;
struct node *head = NULL;
void insertatfirst(list l, int data)
{
    p=l->next;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = p;
    p = new;
}
void printList()
{
    p=l->next;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
void create(list l)
{
    int n;
    printf("Enter of number of elements:--");
    scanf("%d", &n);
    struct node *new = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; i < n; i++)
    {
        printf("Enter Value:--");
        scanf("%d", &new->data);
        p=l->next;
        new->next = NULL;
        if (p == NULL)
        {
            p = new;
            return;
        }
        else{   
            while (p->next != NULL)
                p = p->next;
            p->next = new;
            return;
        }
    }
}
int main()
{
    list l = (struct node *)malloc(sizeof(struct node));
    int choice, ele;
start:
    printf("1.Create a linked list\n2.Insert a node at first position\n3.Display the linked List\n4.Exit\n");
    printf("Enter your choice:--");
    scanf("%d", &choice);
    switch (choice)
    {
    case (1):
        create(l);
        printf("Linked List After Creation:--\n");
        printList();
        goto start;
    case (2):
        printf("Enter the value of element:--");
        scanf("%d", &ele);
        insertatfirst(l, ele);
        printf("Linked List After Insertation:--\n");
        printList();
        goto start;
    case (3):
        printList();
        goto start;
    case (4):
        printf("Program is exiting normally\n");
        exit(0);

    default:
        goto start;
    }
    return 0;
}
