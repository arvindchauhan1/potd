//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // solution 2 (passed)

        // A priority queue (pq) is declared using std::priority_queue with the element type int, internal container type vector<int>, and comparison function greater<int>. This sets up a min-heap, where the smallest element is always at the top of the queue.
        priority_queue<int, vector<int>> pq;

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = 0; i < k; i++)
        {
            // cout << pq.top() << " ";
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends