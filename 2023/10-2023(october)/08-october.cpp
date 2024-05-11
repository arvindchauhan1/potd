//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    // Should return head of the modified linked list
    Node *sortedInsert(Node *head, int data)
    {
        // Create a new node with the given data
        Node *newNode = new Node(data);

        // Step 1: Check if the list is empty or the new node should be the new head
        if (head == nullptr || head->data >= data)
        {
            // Insert the new node at the beginning
            newNode->next = head;
            return newNode;
        }

        // Step 2: Traverse the list to find the correct position for insertion
        Node *curr = head;
        while (curr->next != nullptr && curr->next->data < data)
            curr = curr->next;

        // Step 3: Insert the new node into the sorted position
        newNode->next = curr->next;
        curr->next = newNode;

        // Step 4: Return the updated head of the list
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;

        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        Solution obj;
        head = obj.sortedInsert(head, k);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends