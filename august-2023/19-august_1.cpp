//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    long long sum_of_sub(vector<int> v, int f, int l)
    {
        int sum = 0;
        for (int i = f; i <= l; i++)
        {
            sum += v[i];
        }
        return sum;
    }

    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        vector<int> v;
        if (s == 0)
        {
            v.push_back(-1);
            return v;
        }
        int i = 0, j = 0;
        while (j < n)
        {
            long long sum = sum_of_sub(arr, i, j);
            if (sum == s)
            {
                v.push_back(i + 1);
                v.push_back(j + 1);
                return v;
            }
            if (sum < s)
                j++;
            if (sum > s)
                i++;
        }
        if (v.size() == 0)
            v.push_back(-1);
        return v;
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
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends