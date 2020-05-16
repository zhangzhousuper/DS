// https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1


/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

// Function to delete the node at position x
void deleteNode(Node **head_ref, int x)
{
    Node* temp = *head_ref;
    Node* curr = NULL;
    if (x == 1)
    {
        *head_ref = temp->next;
        temp->next->prev = NULL;
        return;
    }
    while(--x && temp)
    {
        curr = temp;
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        free(temp);
        curr->next = NULL;
    }
    else
    {
        curr->next = temp->next;
        temp->next->prev = curr;
        free(temp);
    }
}
