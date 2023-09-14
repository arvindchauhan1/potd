//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int mod = pow(10, 9) + 7;
    int dp[1001][1001];

    // Recursive function 'solver' to find the number of ways to form the 'target' sum
    // using elements from the 'arr' array, starting from 'index' up to 'size'.
    int solver(int arr[], int index, int size, int target)
    {
        // Base case 1: If 'target' becomes negative, it's impossible to form the sum.
        if (target < 0)
            return 0;

        // Base case 2: If we have processed all elements in the array and 'target' becomes 0,
        // it means we have found a valid way to form the 'sum', so return 1.
        if (index >= size)
        {
            if (target == 0)
            {
                return 1;
            }
            return 0;
        }

        // If the result for the current 'index' and 'target' has been computed before,
        // return it from the 'dp' array to avoid redundant calculations.
        if (dp[index][target] != -1)
            return dp[index][target];

        // Calculate the number of ways to form 'target' by either excluding or including
        // the current element 'arr[index]' in the sum.
        int ans = (solver(arr, index + 1, size, target) % mod + solver(arr, index + 1, size, target - arr[index]) % mod) % mod;

        // Store the computed result in the 'dp' array to avoid recalculating it.
        dp[index][target] = ans;

        // Return the number of ways to form 'target'.
        return dp[index][target];
    }

    int perfectSum(int arr[], int n, int sum)
    {
        // Initialize the 'dp' array with -1 to mark that no results have been computed yet.
        memset(dp, -1, sizeof(dp));

        // Call the 'solver' function to find the number of ways to obtain 'sum' using elements from 'arr'.
        return solver(arr, 0, n, sum);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends