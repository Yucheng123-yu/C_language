#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} snode;

#define calc_arr_length(arr) (sizeof(arr)/sizeof(arr[0]))

void scanf_node(snode **head, int len)
{// Scanf the node
    snode *p, *q;
    for (int i = 0; i < len; i++)
    {
        p = (snode *)malloc(sizeof(snode));
        scanf("%d", &p->data);
        p->next = NULL;
        if (*head == NULL)
            *head = p;
        else
            q->next = p;
        q = p;
    }
}
void add_node(snode **head,int data)
{// Add node to the end
    snode *p, *q;
    if(*head == NULL)
    {
        p = (snode *)malloc(sizeof(snode));
        p->data = data;
        p->next = NULL;
        *head = p;
    }
    else{
        p = (snode *)malloc(sizeof(snode));
        p->data = data;
        p->next = NULL;
        q = *head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
void print_node(snode *head)
{// Print the node
    snode *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void insert_node(snode **head, int th, int data)
{// Insert node at th position
    if (*head == NULL || th < 1)
        return;

    snode *p, *q;
    if (th == 1)
    {
        p = (snode *)malloc(sizeof(snode));
        p->data = data;
        p->next = *head;
        *head = p;
        return;
    }
    p = *head;
    for (int i = 0; i < th - 1 && p != NULL; i++)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
        return;
    // printf("Out of range\n");
    // q->next = p->next;
    snode *new = (snode *)malloc(sizeof(snode));
    new->data = data;
    new->next = p;
    q->next = new;
}

void delete_node(snode **head, int th)
{// Delete node at th position
	if(*head == NULL || th < 1){
		return;
	}
	snode *p,*q;
	p = *head;
	if(th == 1){
		*head = p->next;
		free(p);
		return;
	}
	for(int i=1;i<=th;i++){
		q = p;
		p = p->next;
	}
	if(p==NULL){
		return;
	}
	q->next = p->next;
	free(p);
}

int  calc_nodelength(snode *head)
{// Calculate the length of the list
    snode *p;
    int len = 0;
    p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    // printf("Length of the list is %d\n", len);
    return len;
}

void array_to_nodelist(snode **head, int arr[], int len) {
    // Convert array to node list
	snode * p, *q;
	if(*head == NULL){
		for (int i = 0; i < len; i++) {
			p = (snode*)malloc(sizeof(snode));
			p->data = arr[i];
			p->next = NULL;
			if (*head == NULL) {
				*head = p;
			} else
				q->next = p;
			q = p;
		}
	}
	else{
		q = *head;
		while(q->next!=NULL){
			q = q->next;
		}
		for (int i = 0; i < len; i++) {
			p = (snode*)malloc(sizeof(snode));
			p->data = arr[i];
			p->next = NULL;
			q->next =p;
			q=p;
		}
	}	
}
void swapnode(snode *a, snode *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sort_nodelist(snode *low,snode *high)
{// Sort the node list
    if(low->next == NULL || low == NULL || low == high)
        return;
    int pvef = low->data;
    snode *i_pre = low;
    snode *i = low->next;
    snode *j = low->next;

    while(j != high->next)
    {
        if(j->data < pvef)
        {// '<'  or '>' can be changed direction
            swapnode(i, j);
            i_pre = i;
            i = i->next;
        }
        
        j= j->next;
    }
    swapnode(low, i_pre);
    sort_nodelist(low, i_pre);
    sort_nodelist(i, high);
}

int main()
{
    //    snode *head;
    //    head = NULL;
    //    int len;
    //    printf("Enter the length of the list: ");
    //    scanf("%d", &len);
    //    scanf_node(&head, len);
    //    print_node(head);

    snode *head1;
    head1 = NULL;
    int arr[] = {5, 2, 1, 4, 9, 6, 2, 8, 9};

    array_to_nodelist(&head1, arr, 9);
    print_node(head1);

    // add_node(&head1, 10);
    // print_node(head1);

    
    // calc_length(head1);
    // insert_node(&head1, 3, 99);
    // print_node(head1);
    // insert_node(&head1, 11, 99);
    // print_node(head1);

    int arr1[] = {51, 12, 33, 24, 55, 36, 76, 26, 96};
    int array[] = {15, 5, 2, 4, 8, 9, 12};
    array_to_nodelist(&head1, arr1, 9);
    array_to_nodelist(&head1, array, sizeof(array)/sizeof(array[0]));
    print_node(head1);

    printf("High is %d\n", head1->data);

    snode *head_high;
    head_high = head1;
    // int num = 0;
    while(head_high->next != NULL){
        head_high = head_high->next;
        // num++;
    }
    // printf("Num is %d\n", num);
    // printf("High is %d\n", head_high->data);
    sort_nodelist(head1, head_high);
    
    print_node(head1);

    return 0;
}
