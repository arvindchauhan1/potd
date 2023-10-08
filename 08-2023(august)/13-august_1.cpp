//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int rec(int prev, int next, int count)
    {
        if (count == 0)
            return next;
        // cout << next << " ";
        return rec(next, (prev + next) % 1000000007, count - 1);
    }

    int nthFibonacci(int n)
    {
        return rec(1, 1, n - 2);
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
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends