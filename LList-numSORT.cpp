#include <iostream>
using namespace std;

struct Node
{
	int n;
	Node *next;
};

////////////////////----------------------------////////////////////////////

class LinkedList
{
public:
	Node *L;				// start pointer
	LinkedList();			// constructor
	void addAtFront(int x); // it will add a new node at the front of the list
	void print(Node *x);	//prints all nodes in the linked list
	void sort(Node *x);
	//add function deleteFromFront()
};

//////////////////-----------------------------////////////////////////////

int main(int argc, char **argv)
{

	Node *L;
	L = new Node;
	L->n = 13;
	L->next = new Node;
	L->next->n = 11;
	L->next->next = new Node;
	L->next->next->n = 27;
	L->next->next->next = new Node;
	L->next->next->next->n = 6;
	L->next->next->next->next = new Node;
	L->next->next->next->next->n = 19;
	L->next->next->next->next->next = new Node;
	L->next->next->next->next->next->n = 49;
	L->next->next->next->next->next->next = NULL;
	//---------------------------------------------//
	LinkedList list;
	list.print(L);
	list.sort(L);
	list.print(L);
	return 0;
}

////////////////--------------///////////////////
////////////////--------------///////////////////
LinkedList::LinkedList()
{
	L = NULL;
}
/////////////////------------///////////////////
/////////////////------------///////////////////
//--------------------------------------------//
/////////////////------------///////////////////
/////////////////------------///////////////////

void LinkedList::sort(Node *L)
{
	Node *current;
	current = L;
	//3 6 11 19 27 49//
	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			int x = current->n;
			current->n = current->next->n;
			current->next->n = x;
			current = L;
		}
		else
		{
			current = current->next;
		}
	}
}

///////////////////////////------------//////////////////////////

void LinkedList::print(Node *L)
{
	Node *temp;
	temp = L;
	cout << "\n-->";
	while (temp != NULL)
	{
		cout << "  " << temp->n;
		temp = temp->next;
	}
}