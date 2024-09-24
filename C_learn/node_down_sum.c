// 将两个降序的链表合并之后依然是降序的

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} snode;

#define len_arr(arr_x) sizeof(arr_x)/sizeof(arr_x[0])
void array_to_list1(int *a, int n, snode **head)
{
    snode *p, *q;
    // q = *head;
    for (size_t i = 0; i < n; i++)
    {
        p = (snode *)malloc(sizeof(snode));
        p->data = a[i];
        p->next = NULL;
        if (*head == NULL)
        {
            *head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
}

void print_list(snode *head)
{
    snode *p;
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

snode* merge_list(snode* list1, snode* list2) {
    snode dummyHead;// 创建一个哑节点（dummyHead）作为新链表的头节点的前驱
    snode* tail = &dummyHead;
    snode* current1 = list1;
    snode* current2 = list2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data >= current2->data) {
            tail->next = current1;
            current1 = current1->next;
        } else {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
    }
    // 连接剩余的部分
    tail->next = current1 ? current1 : current2;
    return dummyHead.next;
}

void free_list(snode *head)
{
    snode *p, *q;
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}
int main()
{
    snode *head,*head1;
    head = NULL;
    head1 = NULL;
    int array[] = {5,3,1};
    int array1[] = {6,4,2};
    array_to_list1(array, len_arr(array), &head);
    array_to_list1(array1, len_arr(array1), &head1);
    print_list(head);
    print_list(head1);
    snode *sumsnode = merge_list(head, head1);
    print_list(sumsnode);
    return 0;
}
