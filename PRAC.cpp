#include <iostream>
using namespace std;
struct node
{
	int info;
	node *link;
};

class LinkList
{
public:
	node *first, *last, *temp, *newNode, *previous, *current, *nxt;

	//__________________create
	LinkList()
	{
		first = NULL;
		last = NULL;
	}

	//_________________search node
	void search(int num)
	{
		node *temp = first;
		while (temp != NULL)
		{
			if (temp->info == num)
			{
				cout << "value is inside list";
				break;
			}
			else
				temp = temp->link;
			cout << "\nnot found";
			break;
		}
	}

	//__________________insert node at start

	void insertNode(int num)
	{
		newNode = new node;
		newNode->info = num;
		newNode->link = NULL;

		if (first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else if (first != NULL)
		{
			newNode->link = first;
			first = newNode;
		}
	}

	//__________________insert node at end
	void insertAtEnd(int num)
	{
		newNode = new node;
		newNode->info = num;
		newNode->link = NULL;

		if (first == NULL)
		{
			first = newNode;
		}
		else
		{
			temp = first;
			while (temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = newNode;
		}
	}

	//__________________insert node after some position
	void insertNodeAfter(int num, int position)
	{
		node *newNode, *temp;
		newNode = new node;
		newNode->info = num;
		newNode->link = NULL;

		temp = first;

		for (int i = 1; i < position; i++)
		{
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
	}

	//__________________insert node before some position
	void insertNodeBefore(int num, int position)
	{
		newNode = new node;
		newNode->info = num;
		temp = first;

		for (int i = 1; i < position; i++)
		{
			previous = temp;
			temp = temp->link;
		}
		previous->link = newNode;
		newNode->link = temp;
	}

	//__________________delete first node
	void deleteFirst()
	{
		if (first != NULL)
		{
			temp = first;
			first = first->link;
			delete temp;
		}
		else if (first == NULL)
		{
			first = NULL;
		}
	}

	//__________________delete last node
	void deleteLast()
	{
		if (first != NULL)
		{
			temp = first;
			while (temp->link != NULL)
			{
				previous = temp;
				temp = temp->link;
			}
			previous->link = NULL;
			delete temp;
		}
		else if (first == NULL)
		{
			first = NULL;
		}
	}

	//__________________delete from certain position/key
	void deleteFromPosition(int position)
	{
		temp = first;
		if (temp != NULL)
		{
			for (int i = 1; i < position; i++)
			{
				previous = temp;
				temp = temp->link;
			}
			previous->link = temp->link;
			delete temp;
		}
		else
		{
			cout << "\nList is empty\n";
		}
	}

	//__________________print list
	void print()
	{
		temp = first;
		while (temp != NULL)
		{
			cout << " " << temp->info;
			temp = temp->link;
		}
	}

	//__________________finde nodes/values
	void findNode(int n)
	{
		temp = first;
		while (temp != NULL)
		{
			if (temp->info == n)
			{
				cout << "found at: " << temp << endl;
				break;
			}
			else
			{
				cout << "not found\n";
				break;
			}
			temp = temp->link;
		}
	}

	//__________________delete whole list

	void deleteList()
	{

		while (first != NULL)
		{
			temp = first;
			first = first->link;
			delete temp;
		}

		cout << "\n\nList deleted\n";
	}

	//____________HOME ACTIVITIES_____________
	//____________print list in reverse
	void printReverse()
	{
		temp = first;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->link;
		}
		for (int i = count; i >= 0; i--)
		{
			temp = first;
			for (int j = 1; j <= i; j++)
			{
				if (i == j)
				{
					cout << " " << temp->info;
				}
				temp = temp->link;
			}
		}
	}

	//____________reverse list

	void reverse()
	{
		current = first;
		previous = NULL;
		nxt = NULL;

		while (current != NULL)
		{
			nxt = current->link;
			current->link = previous;

			previous = current;
			current = nxt;
		}

		first = previous;
	}

	//__________utility function for even/odd seperation that returns end node
	node *getTail(node *cur)
	{
		while (cur != NULL && cur->link != NULL)
		{
			cur = cur->link;
		}
		return cur;
	}

	//____________seperate even and odd
	void seperateEvenOdd()
	{
		current = first;
		node *tailNode = getTail(first);
		node *endNode = tailNode;
		node *newHead = NULL;
		previous = NULL;

		while (current != endNode)
		{
			if (current->info % 2 != 0)
			{
				if (previous)
					previous->link = current->link;

				temp = current->link;
				current->link = NULL;
				tailNode->link = current;
				tailNode = current;
				current = temp;
			}
			else
			{
				if (newHead == NULL)
					newHead = current;

				previous = current;
				current = current->link;
			}
		}
		first = newHead;
	}

	//____________swap nodes without swapping values
	void swapNodes(int x, int y)
	{
		if (x == y)
			return;
		node *Xprevious = NULL, *Xcurrent = first;
		node *Yprevious = NULL, *Ycurrent = first;

		//searching x
		while (Xcurrent != NULL && Xcurrent->info != x)
		{
			Xprevious = Xcurrent;
			Xcurrent = Xcurrent->link;
		}
		//searching y
		while (Ycurrent != NULL && Ycurrent->info != y)
		{
			Yprevious = Ycurrent;
			Ycurrent = Ycurrent->link;
		}
		//if none of them present, break
		if (Xcurrent == NULL || Ycurrent == NULL)
			return;

		//if x is not head of the list
		if (Xprevious != NULL)
			Xprevious->link = Ycurrent;
		else //If x is head make y as new head
			first = Ycurrent;

		//if y is not head of the list
		if (Yprevious != NULL)
			Yprevious->link = Xcurrent;
		else //If y is head make x as new head
			first = Xcurrent;

		// Swap next pointers
		node *swap = Ycurrent->link;
		Ycurrent->link = Xcurrent->link;
		Xcurrent->link = swap;
	}
};

int main(int argc, char **argv)
{
	LinkList L;

	L.insertNode(7);
	L.insertNode(67);
	L.insertNode(500);
	L.insertNode(45);
	L.insertNode(340);

	cout << "list was: ";
	L.print();

	cout << "\n\nswappig: ";
	L.swapNodes(67, 340);
	L.print();

	L.insertNodeAfter(66, 1);
	L.insertNodeAfter(77, 3);

	cout << "\n\nafter adding: ";
	L.print();

	cout << "\n\n";
	L.search(90);

	cout << "\n\nend-last del: ";
	L.deleteFirst();
	L.deleteLast();
	L.print();

	cout << "\n\ndelete from position: ";
	L.deleteFromPosition(3);
	L.print();

	cout << "\n\nprinting reverse... ";
	L.printReverse();

	cout << "\n\nafter reversing...";
	L.reverse();
	L.print();

	cout << "\n\nafter swapping....";
	L.swapNodes(7, 340);
	L.print();

	L.insertAtEnd(20);
	L.insertNode(35);

	cout << "\n\neven/odd arrnge: ";
	L.seperateEvenOdd();
	L.print();

	L.deleteList();
	L.print();
	return 0;
}
