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

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
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

    // Display the postorder traversal
    cout << "Postorder Traversal:\n";
    postorder(root);

    return 0;
}
