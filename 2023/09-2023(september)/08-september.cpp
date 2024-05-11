//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// } Driver Code Ends
// User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to perform an in-order traversal and collect nodes in a list
    void inOrderTraversal(Node *root, vector<Node *> &nodes)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left, nodes);
        nodes.push_back(root);
        inOrderTraversal(root->right, nodes);
    }

    // Function to convert a sorted array into a balanced BST
    Node *sortedArrayToBST(vector<Node *> &nodes, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Node *root = nodes[mid];

        root->left = sortedArrayToBST(nodes, start, mid - 1);
        root->right = sortedArrayToBST(nodes, mid + 1, end);

        return root;
    }

    // Wrapper function to convert a binary tree to a BST
    Node *binaryTreeToBST(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        // Step 1: Perform an in-order traversal and collect nodes in a list
        vector<Node *> nodes;
        inOrderTraversal(root, nodes);

        // Step 2: Sort the list to create a sorted array
        sort(nodes.begin(), nodes.end(), [](Node *a, Node *b)
             { return a->data < b->data; });

        // Step 3: Convert the sorted array into a balanced BST
        int start = 0;
        int end = nodes.size() - 1;
        return sortedArrayToBST(nodes, start, end);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST(root);
        printInorder(res);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends