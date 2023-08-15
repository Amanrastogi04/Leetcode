//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    
    Node* s_ptr=new Node(0);
    Node* g_ptr=new Node(0);
    Node* equal=new Node(0);
    Node* curr=head;
    Node* s=s_ptr;
    Node* g=g_ptr;
    Node* e=equal;
    
    while(curr!=NULL){
        if(curr->data<x){
            s_ptr->next=curr;
            s_ptr=s_ptr->next;
        }
        else if(curr->data==x){
            equal->next=curr;
            equal=equal->next;
        }
        else{
            g_ptr->next=curr;
            g_ptr=g_ptr->next;
        }
        curr=curr->next;
    }
    
    g_ptr->next=NULL;
    if(e->next==NULL){
        s_ptr->next=g->next;
    }
    else{
    s_ptr->next=e->next;
    equal->next=g->next;
    }
    
    return s->next;
    
}