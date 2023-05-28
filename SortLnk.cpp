#include <iostream>
using namespace std;

struct Node
{
	int rollno;
	string name;
	string classname;
	Node *next;
};

class LinkedList
{
public:
	Node *L1;
	Node *L2;
	LinkedList()
	{
		L1 = NULL;
		L2 = NULL;
	}

	void print(Node *L)
	{
		Node *current;
		current = L;
		while (current != NULL)
		{
			cout << "  " << current->rollno;
			current = current->next;
		}
	}
};

int main(int argc, char **argv)
{    
/////////////////////////////////////////////////////
//////////////////// LIST 01 ////////////////////////
	Node *L1;

	L1 = new Node;
	L1->rollno = 51;
	L1->name = "johar";
	L1->classname = "BSE-2B";

	L1->next = new Node;
	L1->next->rollno = 52;
	L1->next->name = "mohsin";
	L1->next->classname = "BSE-2B";

	L1->next->next = new Node;
	L1->next->next->rollno = 53;
	L1->next->next->name = "afaq";
	L1->next->next->classname = "BSE-2B";

	L1->next->next->next = new Node;
	L1->next->next->next->rollno = 54;
	L1->next->next->next->name = "moez";
	L1->next->next->next->classname = "BSE-2B";

	L1->next->next->next->next = new Node;
	L1->next->next->next->next->rollno = 55;
	L1->next->next->next->next->name = "abdullah";
	L1->next->next->next->next->classname = "BSE-2B";
	L1->next->next->next->next->next = NULL;


/////////////////////////////////////////////////////
//////////////////// LIST 02 ////////////////////////

	Node *L2;

	L2 = new Node;
	L2->rollno = 51;
	L2->name = "johar";
	L2->classname = "BSE-2B";

	L2->next = new Node;
	L2->next->rollno = 54;
	L2->next->name = "moez";
	L2->next->classname = "BSE-2B";

///////////////////////////////// //////////
///////////////////Object//////////////////
    LinkedList list;
	cout<<"Students that have not paid the Fee:";
    list.print(L2);
///////////////////////////////////////////////////////////
/////////////////////CHECK STUDENTS////////////////////////
    Node *current1 = L1;
	Node *current2 = L2;
	Node *prev;                       
	while (current2 != NULL)
	{
		current1 = L1;
		if (current2->rollno == current1->rollno)
		{
			L1 = current1->next;
			delete current1;
		}
        else
		{
		while (current1->next != NULL)
		{
			prev = current1;
			current1 = current1->next;
			if (current2->rollno == current1->rollno)
			{   
				prev->next = current1->next;
				delete current1;
			}
		}
		}
		current1 = L1;
		current2 = current2->next;
	}
	//////////////////////////////////////
	//////////////////////////////////////
cout<<"FINAL LIST:";
	list.print(L1);
}
