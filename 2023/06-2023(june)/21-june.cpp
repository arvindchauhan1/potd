//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;

    // Function to calculate the sum of natural numbers up to 'n'
    int sumOfNaturals(int n)
    {
        long long sum = 0;

        // Calculate the sum using the formula: sum = (n*(n+1))/2
        sum = ((long long)n * (n + 1) / 2) % mod;

        return sum;
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
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends