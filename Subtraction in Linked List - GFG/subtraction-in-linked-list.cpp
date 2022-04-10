// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node {
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

using node = Node;
int findLen(node* head) {
    if (!head) return 0;
    node* ptr = head;
    int len = 0;
    while(ptr && ptr->data == 0) ptr = ptr->next;
    while(ptr) {
        len++;
        ptr = ptr->next;
    }
    return len;
}


bool compare(node* head1, node* head2) {
    node* ptr1 = head1;
    node* ptr2 = head2;
    while(ptr1 && ptr1->data == 0) ptr1 = ptr1->next;
    while(ptr2 && ptr2->data == 0) ptr2 = ptr2->next;
    while(ptr1 && ptr2) {
        if (ptr2->data > ptr1->data) return true;
        if (ptr1->data > ptr2->data) return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return false;
}
node* reverse(node* head) {
    if (!head) return head;
    node* prev = NULL;
    node* curr = head;
    while(curr) {
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* subtractHelper(node* head1, node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    int borrow = 0;
    node* ptr1 = head1;
    node* ptr2 = head2;
    
    while(ptr1) {
        
        int a;
        
        if (ptr2)
            a = ptr1->data - ptr2->data + borrow;
        else 
            a = ptr1->data + borrow;
        
        if (a < 0) a += 10, borrow = -1;
        else borrow = 0;
        
        ptr1->data = a;
        
        ptr1 = ptr1->next;
        if (ptr2) ptr2 = ptr2->next;
        
    }
    return head1;
}

node* removeZeros(node* head) {
    if (!head) return head;
    while(head && head->data == 0) {
        head = head->next;
    }
    if (!head) {
        return new node(0);
    }
    return head;
}
Node* subLinkedList(Node* head1, Node*head2) {
    if (!head1) return head2;
    if (!head2) return head1; 
    bool debug = false;
    if (head1->data == 0 && head2->data == 7) {
        if (head1->next->data == 2 && head2->next->data == 0)
        debug = true;
    }
    int n = findLen(head1), m = findLen(head2);
    if (n < m) swap(head1, head2);
    else if (n == m && compare(head1, head2)) {
        swap(head1, head2);
    }
    head1 = reverse(head1);
    head2 = reverse(head2);
    
    head1 = subtractHelper(head1, head2);
    
    head1 = reverse(head1);
    head1 = removeZeros(head1);
    return head1;
}



