//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
public:
    void Rearrange(int arr[], int n)
    {
        // Your code goes here
        // solution 1
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }

        int size = neg.size();
        for (int i = 0; i < size; i++)
            arr[i] = neg[i];
        for (int i = size; i < n; i++)
            arr[i] = pos[i - size];
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long j = 0;
        Solution ob;
        ob.Rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends