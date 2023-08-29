//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
private:
    Node *reverseLinkedList(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        while (current != NULL)
        {
            Node *t = current->next; // Store the next node
            current->next = prev;    // Reverse the pointer
            prev = current;
            current = t; // Move prev and current pointers forward
        }
        return prev;
    }

public:
    Node *compute(Node *head)
    {
        Node *t = reverseLinkedList(head);
        Node *res = t;
        while (t->next != NULL)
        {
            if (t->data > t->next->data)
            {
                t->next = t->next->next;
            }
            else
            {
                t = t->next;
            }
        }
        res = reverseLinkedList(res);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends