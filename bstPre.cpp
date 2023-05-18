#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    int numberOfNodes, value;

    // Enter the number of nodes to insert
    cout << "Enter the number of nodes to insert: ";
    cin >> numberOfNodes;

    // Insert the nodes
    for (int i = 0; i < numberOfNodes; i++)
    {
        cout << "Enter the value of node " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    // Display the preorder traversal
    cout << "Preorder Traversal:\n";
    preorder(root);

    return 0;
}
