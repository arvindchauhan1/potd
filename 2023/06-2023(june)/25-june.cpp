//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        vector<bool> vis(row, false); // Avoid redundant checks by examining the visited array for non-unique index values.
        vector<vector<int>> out;

        for (int i = 0; i < row; ++i)
        {
            if (vis[i]) // If we encounter the same row value, we continue.
                continue;

            vis[i] = true; // Mark the ith index as visited.
            vector<int> binArr(col);

            for (int j = 0; j < col; ++j) // Convert the unique row array into a vector.
                binArr[j] = M[i][j];

            out.push_back(binArr); // Push the unique row into the output vector.

            for (int j = i + 1; j < row; ++j)
            {
                bool isEqual = true;

                for (int k = 0; k < col; ++k)
                { // Logic to check for two equal rows.
                    if (M[i][k] != M[j][k])
                    {
                        isEqual = false;
                        break;
                    }
                }

                vis[j] = isEqual | vis[j]; // If we find that this row is not unique, mark it as visited.
            }
        }

        return out;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

// } Driver Code Ends