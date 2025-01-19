 
#include<bits/stdc++.h>
#include<iosteam>
#include<stack>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    public : 
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};
 

// print list
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    void reassign(stack<int>& s, struct node *ptr) {
        
        while(!s.empty()) {
            
            ptr->data = s.top();
            s.pop();
            ptr = ptr->next;
        }
        
    }
    
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        
        if(head == NULL || k == 0)
            return head;
        
        struct node *headbackup = head;
        struct node *headtemp = head;
        
        stack<int> s;
        int t = k;
        
        while(head != NULL) { 
            
            if(t == 0) {
                reassign(s, headbackup);
                headbackup = head;
                t = k;
                continue;
            } else {
                
                s.push(head->data);
                t--;
                
            }
            
            head = head->next;
           
        }
        
        if(s.size() > 0) {
                reassign(s, headbackup);
        }
        
        
        return headtemp;
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends