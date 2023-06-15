//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
void sort(Node **head)
{
    // Node* n1=*head;
    // Node* n2=*head->next;
    
    // while(n2!=NULL){
    //     if(n1.data>n2.data){
    //         int t=n1.data;
            
    //     }
    // }
    
    Node *n1 = *head;
        Node *n2 = (*head)->next;
        while(n2!=NULL){
            if(n1->data>n2->data){
                int t=n1->data;
                n1->data=n2->data;
                n2->data=t;
            } 
                n2=n2->next;
        if(n2==NULL){
                n1=n1->next;
                n2=n1->next;
            }
        }
        // return head;
    

}