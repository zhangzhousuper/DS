#include <stdio.h>
#include <stdlib.h>
 
/* a node of the doubly linked list */
struct node
{
  int data;
  struct node *next;
  struct node *prev;    
};
 struct node* newNode(struct node* head,int data){
	 struct node *p,*temp= (struct node*)malloc(sizeof(struct node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 if(head ==NULL)
	 return temp;
	 p=head;
	 while(p->next!=NULL){
	 p=p->next;}
	 p->next=temp;
	 temp->prev=p;
	 return head; 
	 }
void reverse(struct node **head_ref);
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
  printf("\n");
} 
 int main()
{
  int t,x,n,i;
  scanf("%d",&t);
  while(t--)
  {
  /* Start with the empty list */
  struct node *temp,*head = NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&x);
  head=newNode(head, x);
  }
  reverse(&head);  
  printList(head);
  while(head->next!=NULL)
  {
	  temp=head;
	  head=head->next;
	  free(temp);
	  }       
	}
	return 0;
}
// } Driver Code Ends
/* a node of the doubly linked list */
/*struct node
{
  int data;
  struct node *next;
  struct node *prev;    
};*/
void reverse(struct node **head_ref)
{
   struct node* temp = *head_ref;
   struct node* p = *head_ref;
   struct node* n = NULL;
   if(temp->next == NULL) return;
   while (temp)
   {
       p = temp->prev;
       temp->prev = temp->next;
       temp->next = p;
      
       temp = temp->prev;
       /*p = temp->prev;
       temp->prev = temp->next;
       temp->next = p;
       temp = temp->prev;*/
   }
   *head_ref = p->prev;
}
