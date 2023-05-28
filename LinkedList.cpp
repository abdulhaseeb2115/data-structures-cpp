#include <iostream>
#include <string>
using namespace std;
struct Node{
public:
string info;
Node *next;};
class LinkedList{
public:
    Node *head;
    LinkedList(){
    head=NULL;}
    
    bool isEmpty(){
         bool status;
     if (head==NULL){
     status=true;
     } 
     else{
         ;
     status=false;}
         return status;
     }
    
    void InsertAtStart(string info){
            
     Node *newNode= new Node();
       newNode->info=info;
       newNode->next=NULL;
       if (head==NULL){
       head=newNode;
       }
       else{
       Node *n=head;
       newNode->next=n;
       head=newNode;}
    
    }
    void insertAtEnd(string info){
       Node *newNode= new Node();
       newNode->info=info;
       newNode->next=NULL;
       if (head==NULL){
       head=newNode;
       }
       else{
       Node *n=head;
       while(n->next!=NULL){
       n=n->next;
       }
       n->next=newNode;
       
       }
    
    }
    void print(){
        Node *start=head;
        while(start!=NULL){
        cout<<start->info;
        start=start->next;}
        cout<<"\n";
    }
    void del(Node *d){
    Node *prev=head;
    if (d==head){
        head=prev->next;
        delete prev;
    }
    else { 
        while(prev->next!=NULL && prev->next!=d){
        prev=prev->next;}
        if(prev->next==NULL){ cout<<"Node not found";}
        else if(prev->next==d){
        
        prev->next=prev->next->next;
        free(d);}
    }
    }
    void printrev(){
    Node *current = head;
		int len = 0;
		while (current != NULL)
		{
			len++;
			current = current->next;
		}
		for (int x = len; x > 0; x--)
		{
			current = head;
			for (int y = 1; y <= x; y++)
			{
				if (x == y)
				{
					cout << current->info;
				}

				current = current->next;
			}
		}}
    
//   ========Function only for int============    
//    void oddfirst(){
//        Node *cur=head;
//        while(cur!=NULL){
//        if(cur->info%2==0){
//        cur=cur->next;
//        }
//        else if(cur->info%2!=0){
//        InsertAtStart(cur->info);
//        Node *temp=cur->next;
//        del(cur);
//        cur=temp;
//        }
//        }
//       
//        
//    }
 };

