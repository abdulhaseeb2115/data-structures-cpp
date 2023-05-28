/**** 
 * Lab Tasks: (Must be completed in Lab) (2 points for each task)
1 -> Create linked list       <>
2 -> Insertion in linked list <>
3 -> Deletion of a node       <>
4 -> Complete deletion of linked list   <> 
5 -> Traverse a linked list to print it <>

Home Tasks: (2.5 points for each task)
1 -> Write a function that prints all nodes of a linked list in the reverse order. <>
2 -> Write a function which reverses the order of the linked list.  <>
3 -> Write a function which rearranges the linked list by grouping nodes having even number values before nodes having odd number values **
4 -> Write a function which takes two values as input from the user and searches them in the   
list. If both the values are found, your task is to swap both the nodes in which these values are  
found. Note, that you are not supposed to swap values. <>
****/
#include <iostream>
using namespace std;

struct Node
{
	int n;
	Node *next;
};

class LinkedList
{
public:
	Node *L;
	LinkedList()
	{
		L = NULL;
	}
	//-------------------------------------------//
	//-----------------REVERSEPRINT----------------//
	//---------------------------------------------//
	void reversePrint()
	{

		Node *current = L;
		int len = 0;
		while (current != NULL)
		{
			len++;
			current = current->next;
		}
		for (int x = len; x > 0; x--)
		{
			current = L;
			for (int y = 1; y <= x; y++)
			{
				if (x == y)
				{
					cout << "  " << current->n;
				}

				current = current->next;
			}
		}
	}
	//---------------------------------------------//
	//-------------------SEARCH--------------------//
	//---------------------------------------------//
	void search(int num)
	{

		Node *current = L;
		bool x = false;
		while (current != NULL)
		{
			if (current->n == num)
			{
				cout << "\n>>--Found--";
				x = true;
				break;
			}
			current = current->next;
		}
		if (x == false)
		{
			cout << "\n>>--Not Found--";
		}
	}
	//---------------------------------------------//
	//--------------------SORT---------------------//
	//---------------------------------------------//
	void sort()
	{
		Node *current;
		current = L;
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
		cout << "\n>>--List Sorted--";
	}
	//---------------------------------------------//
	//---------------INSERTatSTART-----------------//
	//---------------------------------------------//
	void insertAtStart(int num)
	{

		Node *newNode = new Node;
		newNode->n = num;
		newNode->next = NULL;

		if (L == NULL)
		{
			L = newNode;
		}
		else if (L != NULL)
		{
			newNode->next = L;
			L = newNode;
		}
		cout << "\n>>--Inserted at START--";
	}
	//---------------------------------------------//
	//----------------INSERTatEND------------------//
	//---------------------------------------------//
	void insertAtEnd(int num)
	{
		Node *current = L;
		Node *newNode = new Node;
		newNode->n = num;
		newNode->next = NULL;
		if (L == NULL)
		{
			L = newNode;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
		cout << "\n>>--Inserted at END--";
	}
	//---------------------------------------------//
	//------------INSERTafterPOSITION--------------//
	//---------------------------------------------//
	void insertAfterPosition(int num, int pos)
	{
		Node *current = L;
		Node *newNode = new Node;
		newNode->n = num;
		newNode->next = NULL;
		for (int i = 1; i < pos; i++)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		cout << "\n>>--Inserted after given Position--";
	}
	//---------------------------------------------//
	//------------INSERTbeforePOSITION-------------//
	//---------------------------------------------//
	void insertBeforePosition(int num, int pos)
	{
		Node *current = L;
		Node *newNode = new Node;
		newNode->n = num;
		newNode->next = NULL;
		for (int i = 1; i < pos - 2; i++)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		cout << "\n>>--Inserted after given Position--";
	}
	//---------------------------------------------//
	//-----------------DELETEfront-----------------//
	//---------------------------------------------//
	void deleteFront()
	{
		Node *current = L;
		if (current == NULL)
		{
			cout << "\n>>--No List Found--";
		}
		else if (current != NULL)
		{
			L = L->next;
			delete current;
		}
		cout << "\n>>--Deleted from FRONT--";
	}

	//---------------------------------------------//
	//-----------------DELETElast------------------//
	//---------------------------------------------//
	void deleteLast()
	{
		Node *current = L;
		Node *last;
		if (current == NULL)
		{
			cout << "\n>>--No List Found--";
		}
		else if (current != NULL)
		{
			while (current->next != NULL)
			{
				last = current;
				current = current->next;
			}
			last->next = NULL;
			delete current;
		}
		cout << "\n>>--Deleted from LAST--";
	}
	//---------------------------------------------//
	//--------------DELETEatPosition---------------//
	//---------------------------------------------//
	void deleteAtPosition(int pos)
	{
		Node *current = L;
		Node *previous;
		int len = 0;
		while (current != NULL)
		{
			len++;
			current = current->next;
		}
		current = L;
		for (int i = 1; i < pos; i++)
		{
			if (i > len)
			{
				cout << "\n>>--Index Not Found--";
				break;
			}
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
		cout << "\n>>--Deleted from given Position--";
	}
	//---------------------------------------------//
	//--------------------PRINT--------------------//
	//---------------------------------------------//
	void print()
	{
		Node *current;
		current = L;
		cout << "\nPrinting-->";
		while (current != NULL)
		{
			cout << "  " << current->n;
			current = current->next;
		}
	}
	//---------------------------------------------//
	//-----------------ReverseList-----------------//
	//---------------------------------------------//
	void reverseList()
	{
		Node *forward = L;
		Node *reverse = L;
		int len = 0;
		while (forward != NULL)
		{
			len++;
			forward = forward->next;
		}
		int itr = 0;
		for (int x = len; x > 0; x--)
		{
			itr++;
			forward = L;
			reverse = L;
			for (int y = 1; y <= x; y++)
			{
				if (x == y)
				{
					for (int z = 1; z <= len / 2; z++)
					{
						if (z == itr)
						{
							int rev = reverse->n;
							reverse->n = forward->n;
							forward->n = rev;
						}
						forward = forward->next;
					}
				}
				reverse = reverse->next;
			}
		}
		cout << "\n>>--List Reversed--";
	}
	//---------------------------------------------//
	//-----------------DELETElist------------------//
	//---------------------------------------------//
	void deleteList()
	{
		Node *current = L;
		while (L != NULL)
		{
			current = L;
			L = L->next;
			delete current;
		}
		cout << "\n>>--List Deleted--";
	}
	//---------------------------------------------//
	//------------------SwapNodes------------------//
	//---------------------------------------------//
	void swapNodes(int x, int y)
	{

		if (x == y)
		{
			return;
		}
		Node *beforeX = NULL;
		Node *currentX = L;
		Node *beforeY = NULL;
		Node *currentY = L;

		while (currentX != NULL && currentX->n != x)
		{
			beforeX = currentX;
			currentX = currentX->next;
		}

		while (currentY != NULL && currentY->n != y)
		{
			beforeY = currentY;
			currentY = currentY->next;
		}

		if (currentX == NULL || currentY == NULL)
		{
			return;
		}
		if (beforeX != NULL)
		{
			beforeX->next = currentY;
		}
		else
		{
			L = currentY;
		}
		if (beforeY != NULL)
		{
			beforeY->next = currentX;
		}
		else
		{
			L = currentX;
		}

		Node *temp = currentY->next;
		currentY->next = currentX->next;
		currentX->next = temp;
		cout << "\n>>--Node Swapped--";
	}

	//---------------------------------------------//
	//-------------------EvenOdd-------------------//
	//---------------------------------------------//

	void evenOdd()
	{
		Node *tail = L;
		while (tail != NULL && tail->next != NULL)
		{
			tail = tail->next;
		}

		Node *current = L;
		Node *lastNode = tail;
		Node *endNode = lastNode;
		Node *newHead = NULL;
		Node *previous = NULL;

		while (current != endNode)
		{
			if (current->n % 2 != 0)
			{
				if (previous)
				{
					previous->next = current->next;
				}

				Node *temp = current->next;
				current->next = NULL;
				lastNode->next = current;
				lastNode = current;
				current = temp;
			}
			else
			{
				if (newHead == NULL)
				{
					newHead = current;
				}
				previous = current;
				current = current->next;
			}
		}
		L = newHead;
		cout << "\n>>--Even at First--";
	}
	//---------------------------------------------//
	//---------------------E N D-------------------//
	//---------------------------------------------//
};

int main(int argc, char **argv)
{
	LinkedList list;

	list.insertAtStart(11);
	list.insertAtStart(10);
	list.insertAtStart(9);
	list.insertAtStart(8);
	list.insertAtStart(7);
	list.insertAtStart(6);
	list.insertAtStart(5);
	list.insertAtStart(4);
	list.insertAtStart(3);
	list.insertAtStart(2);
	list.insertAtStart(1);
	cout << "\n<<<---------------------------------------------------->>>";
	cout << "\n****************************************************";
	list.print();
	cout << "\n****************************************************";

	list.search(6);
	cout << "\n****************************************************\n";

	list.reversePrint();
	cout << "\n****************************************************";

	list.sort();
	list.print();
	cout << "\n****************************************************";

	list.swapNodes(4, 5);
	list.print();
	cout << "\n****************************************************";

	list.deleteAtPosition(3);
	list.print();
	cout << "\n****************************************************";

	list.deleteFront();
	list.print();
	cout << "\n****************************************************";

	list.deleteLast();

	list.print();
	cout << "\n****************************************************";

	list.evenOdd();
	list.print();
	cout << "\n****************************************************";

	list.insertAfterPosition(2, 6);
	list.print();
	cout << "\n****************************************************";

	list.insertAtEnd(13);
	list.print();
	cout << "\n****************************************************";

	list.insertAtStart(23);
	list.print();
	cout << "\n****************************************************";

	list.insertBeforePosition(6, 3);
	list.print();
	cout << "\n****************************************************";

	list.deleteList();
	list.print();
	cout << "\n****************************************************";

	list.reverseList();
	list.print();
	cout << "\n****************************************************";
	cout << "\n<<<---------------------------------------------------->>>";
	return 0;
}
