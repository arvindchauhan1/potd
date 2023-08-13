//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int nthFibonacci(int n)
    {
        if (n == 1 || n == 2)
            return 1;
        long long int l = 1, r = 1;
        n = n - 2;
        while (n--)
        {
            int temp;
            temp = r;
            r = (r + l) % 1000000007;
            l = temp;
            // cout << r << " ";
        }
        // cout << "\n";
        return r;
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