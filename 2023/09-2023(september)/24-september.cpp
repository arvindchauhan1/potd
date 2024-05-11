//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        // Create a map 'm' to store the frequency of each element in the array.
        map<int, int> m;

        // Create a vector 'res' to store the duplicate elements.
        vector<int> res;

        // Iterate through the input array 'arr'.
        for (int i = 0; i < n; i++)
        {
            // Increment the frequency of the current element in the map 'm'.
            m[arr[i]]++;
        }

        // Iterate through the map 'm' using an iterator 'i'.
        for (auto i : m)
        {
            // If the frequency of the current element is greater than 1, it is a duplicate.
            if (i.second > 1)
            {
                // Add the duplicate element to the 'res' vector.
                res.push_back(i.first);
            }
        }

        // If no duplicates were found, add -1 to the 'res' vector.
        if (res.empty())
        {
            res.push_back(-1);
        }

        // Return the 'res' vector containing duplicate elements (or -1 if no duplicates were found).
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends