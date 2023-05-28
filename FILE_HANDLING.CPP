#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
struct Node
{
	string movie;
	string director;
	string duration;
	string country;

	Node *next;
	Node *back;
};
class LinkedList
{
public:
	Node *L;
	Node *Z;
	LinkedList()
	{
		L = NULL;
		Z = NULL;
	}
	//------------------ENTERvaluesTOlist-------------------//
	void enterValuesToList(string movie, string director, string duration, string country)
	{
		Node *newNode = new Node;

		newNode->movie = movie;
		newNode->director = director;
		newNode->duration = duration;
		newNode->country = country;
		newNode->next = NULL;

		if (L == NULL)
		{
			L = newNode;
			Z = newNode;
			Z->next = NULL;
		}
		else if (L != NULL)
		{
			Z->next = newNode;
			newNode->back = Z;
			Z = newNode;
		}
	}
	//--------------------PRINT--------------------//
	void print()
	{
		Node *current;
		current = L;
		cout << "\n|||PRINTING FULL LIST|||\n=========================";
		while (current != NULL)
		{
			cout << "\nTITLE ==== " << current->movie;
			cout << "\nDIRECTOR = " << current->director;
			cout << "\nDURATION = " << current->duration;
			cout << "\nCOUNTRY == " << current->country;
			current = current->next;
			cout << "\n=========================";
		}
	}
	//-------------------PRINTcountry--------------------//
	void printCountry(string country)
	{
		Node *current;
		current = L;
		cout << "\n\n-----------PrintingCountry-----------\n";
		while (current != NULL)
		{

			if (current->country.compare(country) == false)
			{
				cout << "\nTITLE ==== " << current->movie;
				cout << "\nDIRECTOR = " << current->director;
				cout << "\nDURATION = " << current->duration;
				cout << "\nCOUNTRY == " << current->country;
				cout << "\n=========================";
			}
			current = current->next;
		}
	}
	//-------------------PRINTgreater------------------//
	void printGreater(int len)
	{
		Node *current;
		current = L;
		cout << "\n\n-----------PrintingGreater-----------\n";
		while (current != NULL)
		{
			int x;
			stringstream convert;
			convert << current->duration;
			convert >> x;

			if (x > len)
			{
				cout << "\nTITLE ==== " << current->movie;
				cout << "\nDIRECTOR = " << current->director;
				cout << "\nDURATION = " << current->duration;
				cout << "\nCOUNTRY == " << current->country;
				cout << "\n=========================";
			}
			current = current->next;
		}
	}
	//------------------DELETENODEcurrent-------------------//
	void deleteNode(int len)
	{
		Node *nxt;
		Node *current = L;
		Node *prev = L;

		while (nxt != NULL)
		{
			int x;
			stringstream convert;
			convert << current->duration;
			convert >> x;

			if (x < len)
			{
				nxt = current->next;
				prev->next = nxt;
				nxt->back = prev;
				delete current;
				current = current->next;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		cout << "\n>>--Deleted NODE--------------\n";
	}
	//------------------GETtotalLINES-------------------//
	int getTotalLines()
	{
		ifstream data("C:\\Users\\Hp\\Desktop\\New folder\\Assignment 2\\IMDB_5000.csv");
		int lines = 0;
		string s;
		while (getline(data, s))
		{
			lines++;
		}
		return lines;
	}
	//------------------GETvaluesFROMfile-------------------//
	void getValuesFromFile()
	{
		ifstream file("C:\\Users\\Hp\\Desktop\\New folder\\Assignment 2\\IMDB_5000.csv");
		string director;
		string duration;
		string title;
		string country;

		int lines = getTotalLines();
		for (int i = 0; i <= lines; i++)
		{
			string color;
			//////// 2 4 12 21
			for (int i = 1; i <= 28; i++)
			{
				getline(file, color, ',');

				if (i == 2)
				{
					director = color; //2
				}

				if (i == 4)
				{
					duration = color; //4
					if (duration.empty())
					{
						duration = "0";
					}
				}

				if (i == 12)
				{
					title = color; //12
				}

				if (i == 21)
				{
					country = color; //21
				}

				if (i == 28)
				{
					getline(file, color, '\n'); //Next Line
				}
			}
			enterValuesToList(title, director, duration, country);
		}
	}
};
//---------  ---------MAIN--------- ---------//
int main(int argc, char **argv)
{
	LinkedList list;
	list.getValuesFromFile();
	list.print();
	list.printCountry("USA");
	list.printGreater(100);
	list.deleteNode(45);
}