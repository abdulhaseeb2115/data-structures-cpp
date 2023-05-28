#include <iostream>
using namespace std;
struct Node
{
public:
    int roll;
    string name;
    int marks;
    Node *left;
    Node *right;
};
class BinarySearchTree
{
public:
    Node *root;
    int count = 0;
    double sum = 0;
    BinarySearchTree()
    {
        root = NULL;
    }
    /////////////////////////////////////////////////////
    //**********************INSERT*********************//
    /////////////////////////////////////////////////////
    void insertNode(int roll, string name, int marks)
    {
        Node *newNode = new Node();
        newNode->roll = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->left = newNode->right = NULL;
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *child = root;
            Node *par;

            while (child != NULL)
            {
                if (roll < child->roll)
                {
                    par = child;
                    child = child->left;
                }
                else if (roll > child->roll)
                {
                    par = child;
                    child = child->right;
                }
            }
            if (roll > par->roll)
            {
                par->right = newNode;
            }
            else if (roll < par->roll)
            {
                par->left = newNode;
            }
        }
    }

    ////////////////////////////////////////////////////////
    //******************GETsumANDcount********************//
    ////////////////////////////////////////////////////////
    void getSumAndCount(struct Node *node)
    {

        if (node == NULL)
        {
            return;
        }

        getSumAndCount(node->left);
        sum += node->marks;
        count++;
        getSumAndCount(node->right);
    }
    //////////////////////////////////////////////////
    /******************GET AVERAGE*******************/
    //////////////////////////////////////////////////
    int getAverage()
    {
        getSumAndCount(root->right);
        int avg = sum / count;
        return avg;
    }
    /////////////////////////////////////////////////
    /******************PRINT INORDER****************/
    /////////////////////////////////////////////////
    void printInorder(struct Node *node)
    {
        if (node == NULL)
            return;

        printInorder(node->left);

        cout << "->" << node->roll << " " << node->name << " " << node->marks << "\n";
        printInorder(node->right);
    }
    /////////////////////////////////////////////////
    //******************DELETE*********************//
    /////////////////////////////////////////////////
    void dellete(struct Node *node)
    {
        if (node == NULL)
            return;

        dellete(node->left);
        if (node->marks < getAverage())
        {
            delNum(node->roll);
        }
        dellete(node->right);
    }

    void delNum(int roll)
    {
        Node *parentNode = root;
        Node *temporary = root;
        while (temporary != NULL)
        {
            if (roll > temporary->roll)
            {
                parentNode = temporary;
                temporary = temporary->right;
            }
            else if (roll < temporary->roll)
            {
                parentNode = temporary;
                temporary = temporary->left;
            }
            else if (temporary->roll == roll)
            {
                break;
            }
        }
        if (temporary == NULL)
        {
            cout << "\n !! Not Present !!\n";
        }

        else if (temporary->roll == roll)
        {
            if (temporary->right == NULL && temporary->left == NULL)
            {
                if (parentNode->right == temporary)
                {
                    parentNode->right = NULL;
                    delete temporary;
                }
                else if (parentNode->left == temporary)
                {
                    parentNode->left = NULL;
                    delete temporary;
                }
                else if (parentNode == temporary)
                {
                    root = NULL;
                    delete temporary;
                }
            }
            else if (temporary->right == NULL && temporary->left != NULL)
            {
                if (parentNode->right == temporary)
                {
                    parentNode->right = temporary->left;
                    delete temporary;
                }

                else if (parentNode->left == temporary)
                {
                    parentNode->left = temporary->left;
                    delete temporary;
                }
                else if (parentNode == temporary)
                {
                    root = temporary->left;
                    delete temporary;
                }
            }
            else if (temporary->left == NULL && temporary->right != NULL)
            {
                if (parentNode->right == temporary)
                {
                    parentNode->right = temporary->right;
                    delete temporary;
                }
                else if (parentNode->left == temporary)
                {
                    parentNode->left = temporary->right;
                    delete temporary;
                }
                else if (parentNode == temporary)
                {
                    root = temporary->right;
                    delete temporary;
                }
            }
            else if (temporary->right != NULL && temporary->left != NULL)
            {
                parentNode = temporary;
                Node *temp = temporary->right;
                while (temp->left != NULL)
                {
                    parentNode = temp;
                    temp = temp->left;
                }
                temporary->roll = temp->roll;
                if (parentNode == temporary)
                {
                    parentNode->right = temp->right;
                }
                else
                {
                    parentNode->left = temp->right;
                }
                delete temp;
            }
        }
    }
};
////////////////////////////////////////////////
/*********************MAIN*********************/
////////////////////////////////////////////////
int main(int argc, char **argv)
{
    BinarySearchTree obj;
    cout << ">>>>============<<<<\n";

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "ENTER ROLL NO , NAME , MARKS:";
    //     int roll, marks;
    //     string name;
    //     cin >> roll >> name >> marks;
    //     obj.insertNode(roll, name, marks);
    // }

    obj.insertNode(10, "a", 10);
    obj.insertNode(20, "a", 22);
    obj.insertNode(30, "a", 24);
    obj.insertNode(9, "a", 9);
    obj.insertNode(8, "a", 8);

    cout<<"BEFORE DELETION\n";
    obj.printInorder(obj.root);
    cout << "\nAverage of Right Sub Tree: " << obj.getAverage() << "\n\n";
    obj.dellete(obj.root->left);
    cout<<"AFTER DELETION\n";
    obj.printInorder(obj.root);

    cout << "<<<<============>>>>";
    return 0;
}