//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here

        // solution 1 (failed : 1016 /1111)
        // for (int i = 0; i < k; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (j + 1 >= updates[i])
        //         {
        //             a[j]++;
        //         }
        //     }
        // }

        // solution 2 (passed)
        vector<int> arr(n + 1, 0);

        // counting number of occurrences of each value in the updates array.
        for (int i = 0; i < k; i++)
        {
            ++arr[updates[i]];
        }
        a[0] = arr[1];
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + arr[i + 1];
        }
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
        int a[n] = {0}, updates[k] = {0};
        for (int i = 0; i < k; i++)
            cin >> updates[i];
        Solution ob;
        ob.update(a, n, updates, k);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends