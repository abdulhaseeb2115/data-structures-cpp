#include <iostream>
using namespace std;
struct NodeBST
{
public:
    int data;
    NodeBST *left;
    NodeBST *right;
};
class Bst
{
public:
    NodeBST *root;
    Bst()
    {
        root = NULL;
    }
    void insertNode(int data)
    {
        NodeBST *newNode = new NodeBST();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            NodeBST *child = root;
            NodeBST *par;
            while (child != NULL)
            {
                if (data < child->data)
                {
                    par = child;
                    child = child->left;
                }
                else if (data > child->data)
                {
                    par = child;
                    child = child->right;
                }
            }
            if (data > par->data)
            {
                par->right = newNode;
            }
            else if (data < par->data)
            {
                par->left = newNode;
            }
        }
    }

    void printInorder(struct NodeBST *node)
    {
        if (node == NULL)
            return;

        printInorder(node->left);

        cout << node->data << " ";
        printInorder(node->right);
    }
    void printPreorder(struct NodeBST *node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
    void printPostorder(struct NodeBST *node)
    {
        if (node == NULL)
            return;
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }
    //******************DELETE*********************//
    void del(int data)
    {
        NodeBST *parent = root;
        NodeBST *temp = root;
        while (temp != NULL)
        {
            if (data > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else if (data < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else if (temp->data == data)
            {
                break;
            }
        }
        if (temp == NULL)
        {
            cout << "\nNOT FOUND..!\n";
        }

        // temp = required node//
        else if (temp->data == data)
        {
            cout << temp->data;
            /* 1 */
            if (temp->right == NULL && temp->left == NULL)
            {
                cout << "--BOTH NULL--";
                parent->right = NULL;
                delete temp;
            }
            /* 2 */
            else if (temp->right == NULL && temp->left != NULL)
            {
                cout << "--RIGHT NULL--";
                parent->right = temp->left;
                delete temp;
            }
            /* 3 */
            else if (temp->left == NULL && temp->right != NULL)
            {
                cout << "--LEFT NULL--";
                parent->left = temp->right;
                delete temp;
            }
            /* 4 */
            else if (temp->right != NULL && temp->left != NULL)
            {
                cout << "--BOTH PRESENT--";
                parent = temp;
                NodeBST *current = temp->right;
                while (current && current->left != NULL)
                {
                    parent = current;
                    current = current->left;
                }
                temp->data = current->data;
                if (parent == temp)
                {
                    parent->right = NULL;
                }
                else
                {
                    parent->left = NULL;
                }
                delete current;
            }
        }
    }
};

int main(int argc, char **argv)
{
    Bst b;
    cout << ">>>>============<<<<\n";
    b.insertNode(10);
    b.insertNode(6);
    b.insertNode(20);
    b.insertNode(25);
    b.insertNode(12);
    b.insertNode(15);
    b.insertNode(7);
    b.insertNode(11);
    b.printInorder(b.root);
    cout << endl;
    b.del(10);
    cout << endl;
    b.printInorder(b.root);
    //    b.printPreorder(b.root);
    //    cout<<endl;
    //    b.printPostorder(b.root);

    cout << "\n<<<<============>>>>";
    return 0;
}