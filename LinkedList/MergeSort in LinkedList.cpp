//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node *mergeList(Node *a, Node *b)
{
    Node *mergedList = NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    if(a->data<=b->data)
    {
        mergedList = a;
        mergedList->next = mergeList(a->next,b);
    }

    else
    {
        mergedList = b;
        mergedList->next = mergeList(a,b->next);
    }
    return mergedList;
}

void partition(Node *head, Node **front, Node **back)
{
    Node *slow,*fast;
    if(head==NULL||head->next==NULL)
    {
        *front = head;
        *back = NULL;
    }
    else
    {
        slow = head;
        fast = head->next;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
    }

}

void mergeSort1(Node **head)
{
    Node *a = NULL;
    Node *b = NULL;
    Node *temp = *head;
    if(temp==NULL||temp->next==NULL)
        return ;

    partition(temp,&a,&b);
    mergeSort1(&a);
    mergeSort1(&b);
    *head = mergeList(a,b);
}

Node * mergeSort(Node *head)
{
    mergeSort1(&head);
    return head;
}




// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
