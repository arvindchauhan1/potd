//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        int max_sum = 0, curr_sum = 0, count_one = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                count_one++;

            int val = a[i] == 0 ? 1 : -1;
            curr_sum += val;
            max_sum = max(max_sum, curr_sum);

            if (curr_sum < 0)
                curr_sum = 0;
        }

        return max_sum + count_one;
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
        int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxOnes(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends