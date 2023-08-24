//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
    {
        vector<int> res;
        int col = 0;
        for (int k = 0; k < 2 * N - 1; k++)
        {
            for (int i = 0; i <= col; i++)
            {
                if (k - i <= N - 1)
                {
                    // cout << A[i][k - i] << " - (";
                    // cout << i << "," << k - i << ") -" << col << "\n";
                    res.push_back(A[i][k - i]);
                }
            }
            if (col < N - 1)
                col++;
        }
        return res;
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

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends