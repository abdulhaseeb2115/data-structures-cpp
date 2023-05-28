#include <iostream>
using namespace std;
//////////////////////////////////////////////////////
struct Node
{
    int registration;
    string name;
    string phone;
    double gpa;
    string add;
    Node *left;
    Node *right;
};

int registration;

//////////////////INSERT//////////////////
Node *insertRECORD( string name, string phone, double gpa, string add,Node *root)
{
//RANDOM REGISTRATION NUMBER//
    registration = rand() % 200 + 1;

    Node *newNode = new Node;
    newNode->registration = registration;
    newNode->name = name;
    newNode->phone = phone;
    newNode->gpa = gpa;
    newNode->add = add;
    newNode->left = NULL;
    newNode->right =NULL;
    Node *temp = root;
    Node *parentLoc = NULL;

    while (temp != NULL)
    {
        parentLoc = temp;
        if (registration < temp->registration)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (parentLoc == NULL)
    {
        parentLoc = newNode;
    }
    else if (registration < parentLoc->registration)
    {
        parentLoc->left = newNode;
    }
    else
    {
        parentLoc->right = newNode;
    }

    root = parentLoc;
    return root;
}

//////////////////FIND//////////////////
void find(Node *root, string name)
{
    if (root == NULL)
    {
        cout << "NOT FOUND";
    }
    else
    {
        while (root)
        {
            if (name == root->name)
            {
                cout << "FOUND: \n"
                     << root->registration << ", " << root->name << " , " << root->add << " , " << root->phone << " , " << root->gpa << "\n";
                break;
            }
            else if (registration > root->registration)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
    }
}

//////////////////findMAXgpa//////////////////
double findMax(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    double max = root->gpa;
    double leftMax = findMax(root->left);
    double rightMax = findMax(root->right);
    if (leftMax > max)
    {
        max = leftMax;
    }
    if (rightMax > max)
    {
        max = rightMax;
    }
    return max;
}

//////////////////HIGHgpa//////////////////
void highGPA(Node *root)
{
    if (root == NULL)
    {
        cout << "Not Found";
    }
    else
    {
        double max = findMax(root);
        while (root)
        {
            if (max == root->gpa)
            {
                cout << "Highest GPA: \n"
                     << root->registration << ", " << root->name << " , " << root->add
                     << " , " << root->phone << " , " << root->gpa << "\n";
                break;
            }
            else if (registration > root->registration)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
    }
}

//////////////////AVERAGEgpa//////////////////
double avgGPA(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->gpa + avgGPA(root->right) + avgGPA(root->left);
}
int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->right) + count(root->left);
}
double averageGPA(Node *root)
{
    return (double)avgGPA(root) / count(root);
}
//////////////////PRINT//////////////////
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        print(root->left);
        cout << root->registration << ", " << root->name << " , " << root->add << " , " << root->phone << " , " << root->gpa << "\n";
        print(root->right);
    }
}

//////////////////ASCENDINGprint//////////////////
void ascendingPRINT(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    ascendingPRINT(root->left);
    if (!(root == NULL))
    {
        cout << "ASCENDING!!";
        cout << root->registration << ", " << root->name << " , " << root->add << " , " << root->phone << " , " << root->gpa << "\n";
        ascendingPRINT(root->right);
    }
}
//////////////////MAIN//////////////////
int main(int argc, char **argv)
{
    Node *insertion = NULL;
    cout << "----------------------\n";
    insertion = insertRECORD("abc", "00", 4, "karachi",insertion);
                insertRECORD("def", "11", 3, "rawalpindi",insertion);
                insertRECORD("ghi", "22", 2, "jehlum",insertion);
    cout << "----------------------\n";
    print(insertion);
    cout << "----------------------\n";
    ascendingPRINT(insertion);
    cout << "----------------------\n";
    highGPA(insertion);
    cout << "----------------------\n";
    find(insertion, "def");
    cout << "----------------------\n";
    print(insertion);
    return 0;
}