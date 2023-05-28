#include <bits/stdc++.h>
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
	void addAtFront(int num)
	{
		if (L == NULL)
		{
			L = new Node;
			L->n = num;
			L->next = NULL;
		}
		else
		{
			Node *temp = new Node;
			temp->n = num;
			temp->next = L;
			L = temp;
		}
	}
	void print()
	{
		Node *temp;
		temp = L;
		while (temp != NULL)
		{
			cout << " [" << temp->n << "]";
			temp = temp->next;
		}
	}
};

class Graph
{
public:
	int inpVertices;
	LinkedList *list;
	Graph()
	{
		cout << "Enter Total Vertices: ";
		cin >> inpVertices;
		list = new LinkedList[inpVertices];
	}
	void addNewEdge(int x, int y)
	{
		list[x].addAtFront(y);
		list[y].addAtFront(x);
	}
	void print()
	{
		cout << "\n    Graph has " << inpVertices << " Vertices";
		cout << "\n    VERTICES->CONNECTED TO";
		for (int i = 0; i < inpVertices; i++)
		{
			cout << " \n\t" << i << "   -> ";
			list[i].print();
		}
	}
};

int main(int argc, char **argv)
{

	Graph obj;
	obj.addNewEdge(0, 2);
	obj.addNewEdge(2, 4);
	obj.addNewEdge(2, 3);
	obj.addNewEdge(1, 4);
	obj.addNewEdge(4, 3);
	obj.addNewEdge(2, 1);
	obj.addNewEdge(3, 0);
	obj.print();
	return 0;
}
