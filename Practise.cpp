#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class AList{
	public:
	int *A;
	int A_size; // this is the size of the array
	int max_index;
	AList();
	void addLast(int n);
	void deleteLast(int n);
	void updateSize(int init, int final_size);
	void print();
};

int main(int argc, char** argv) {





	AList L;
	for(int i=1;i<=4;i++)
	L.addLast(i);
	
	L.print();
	
	L.addLast(100);
	L.addLast(101);
	L.addLast(102);
	L.addLast(104);

	L.print();	
	
	L.addLast(200);
	L.print();
	return 0;
}

AList::AList()
{
	A_size=4;
	A=new int[A_size];
	max_index=-1;
}

void AList::addLast(int n)
{
	
	
	if(max_index>=A_size-1){
		cout<<"\n Memory limit reached";
		cout<<"\n Now I will double the array size .. to accomodate the new items";
		updateSize(A_size, 2*A_size);
	}
	
	max_index++;
	A[max_index]=n;
	
}

void AList::print(){
	cout<<"\n ****Printing***** \n";
	for(int i=0;i<=max_index;i++){
		cout<<"  "<<A[i];
	}
}

/////////////////////////////////////////////////////////////////////
//update size of array from init_size to final_size
// 1) create new array temp (dynamically) of size final_size
// 2) copy items from A[0.....max_size] into temp[0....max_index] 
// 3) free space of A
// 4) now point the pointer A to the newly created dynamic array
// 5) I update the A_size
///////////////////////////////////////////////////

void AList::updateSize(int init_size, int final_size)
{
	// 1) create new array temp (dynamically) of size final_size
	int *temp= new int[final_size];
	
// 2) copy items from A[0.....max_size] into temp[0....max_index] 
	for(int i=0;i<=max_index;i++)
	{
	temp[i]=A[i];	
	}	

// 3) free space of A
delete[] A;	

// 4) now point the pointer A to the newly created dynamic array
A=temp;

// 5) I update the A_size

A_size=final_size;

}


// delete last item
// 1) array is not  empty 
// delete last item--->max_index--
// if more than half the array is empty (max_index < A_size/2) --> make a smaller array of half size and copy all items to it
// I will again use update size updatesize( A_size, A_size/2)

