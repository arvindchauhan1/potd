//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        // Initialize variables
        int res = 0;
        int r1, c1, r2, c2;
        r1 = c1 = 0;     // Start from the top-left corner of mat1
        r2 = c2 = n - 1; // Start from the top-right corner of mat2

        // Loop until either matrix boundaries are reached
        while (r2 >= 0 && c2 >= 0 && r1 < n && c1 < n)
        {
            // Calculate the sum of elements at the current positions in mat1 and mat2
            int sum = mat1[r1][c1] + mat2[r2][c2];

            // Check if the sum is equal to the target value x
            if (sum == x)
            {
                res++; // Increment the result count
                c1++;  // Move to the next column in mat1
                c2--;  // Move to the previous column in mat2
            }
            else if (sum < x)
            {
                c1++; // If sum is less than x, move to the next column in mat1
            }
            else
            {
                c2--; // If sum is greater than x, move to the previous column in mat2
            }

            // If reached the end of a row in mat1, move to the next row and reset to the first column
            if (c1 == n)
            {
                r1++;
                c1 = 0;
            }

            // If reached the beginning of a row in mat2, move to the next row and reset to the last column
            if (c2 == -1)
            {
                r2--;
                c2 = n - 1;
            }
        }

        return res; // Return the final count of pairs
    }

    //{ Driver Code Starts.

    int main()
    {

        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        int t;
        cin >> t;
        while (t--)
        {
            int n, x;
            cin >> n >> x;

            vector<vector<int>> mat1(n, vector<int>(n, -1));
            vector<vector<int>> mat2(n, vector<int>(n, -1));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> mat1[i][j];
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> mat2[i][j];
                }
            }

            Solution ob;

            cout << ob.countPairs(mat1, mat2, n, x) << "\n";
        }

        return 0;
    }
    // } Driver Code Ends