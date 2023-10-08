//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPowerofTwo(long long n)
    {

        // Your code here
        int c = 0;
        while (n > 0)
        {
            if ((n & 1) == 1)
                c++;
            n /= 2;
        }
        return (c != 1) ? false : true;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++)
    {
        long long n; // input a number n
        cin >> n;

        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

// } Driver Code Ends