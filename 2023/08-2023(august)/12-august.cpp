//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        vector<int> piles; // Piles to simulate the patience sorting
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(piles.begin(), piles.end(), a[i]); // Find the lower bound in piles
            if (it == piles.end())
            {
                piles.push_back(a[i]); // If no suitable pile found, create a new pile
            }
            else
            {
                *it = a[i]; // Replace the pile with the new card
            }
        }

        return piles.size(); // Return the number of piles as the length of the longest subsequence
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends