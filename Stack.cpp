#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int top;
    int arr[10];
    bool empty;
    bool full;
public:
    //---------------------------------------//
    //-----------------STACK-----------------//
    //---------------------------------------//

    Stack()
    {
        top = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
        cout << "\n>>-------------------------------<<\n";
        cout << ">----------STACK CREATED----------<\n";
        cout << ">>-------------------------------<<\n\n";
    }

    //---------------------------------------//
    //--------------EMPTYorFULL--------------//
    //---------------------------------------//

    void EMPTYorFULL()
    {
        if (top == -1)
        {
            cout << ">>STACK_EMPTY<<\n";
        }
        else if (top == 9)
        {
            cout << ">>STACK_FULL<<\n";
        }
        else
        {
            cout << ">>STACK_HAS_" << top + 1 << "_ELEMENTS<<\n";
        }
    }

    //---------------------------------------//
    //-----------------STATUS----------------//
    //---------------------------------------//

    void Status()
    {
        if (top == -1)
        {
            empty=true;
            full=false;
        }
        else if (top == 9)
        {
            empty=false;
            full=true;
        }
        else
        {
            empty=true;
            full=true;
        }
        
    }

    //---------------------------------------//
    //----------------DISPLAY----------------//
    //---------------------------------------//

    void display()
    {
        cout << "\n------------------------------------\n STACK->>";
        for (int i = 0; i <= 9; i++)
        {
            cout << " [" << arr[i] << "]";
        }
        cout << "\n------------------------------------\n";
    }

    //---------------------------------------//
    //-----------------PUSH------------------//
    //---------------------------------------//

    void push(int n)
    {  
        Status();
        if (empty==true)
        {
            top++;
            arr[top] = n;
            cout << "-->[" << n << "] added to STACK..\n";
        }
        else
        {
            cout << "--> '" << n << "' cannot be added to STACK.\n";
        }
    }

    //---------------------------------------//
    //------------------POP------------------//
    //---------------------------------------//

    int pop()
    {
        Status();
        if (full==true)
        {
            int n = arr[top];
            arr[top] = 0;
            top--;
            cout<<"--> POPPED..!";
            return n;
        }
        else
        {
            cout << "--> Cannot be popped out.\n";
            return 0;
        }
    }

    //---------------------------------------//
    //------------------PEEK-----------------//
    //---------------------------------------//

    int peek(int pos){
        Status();
        if(full==true){
         int n=arr[pos-1];
         cout << "--> PEEK>> [";
         return n;  
        }
        else
        {
            cout << "--> Cannot be peeked at.\n";
            return 0;
        }
        
    }
};
int main(int argc, char **argv)
{
    Stack s;
    s.EMPTYorFULL();
    s.push(10);
    s.push(20);
    s.push(30);
    s.EMPTYorFULL();
    s.push(40);
    s.push(50);
    s.EMPTYorFULL();
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.EMPTYorFULL();
    s.push(110);
    s.display();
    cout<<s.peek(2)<<"]\n";
    s.pop();
    s.display();

    return 0;
}
