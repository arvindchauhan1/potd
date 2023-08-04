//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        int ans = x;
        vector<int> s1;
        vector<int> s2;
        for (int i = 0; i < 32; i++)
        {
            s1.push_back(x % 2);
            x = x / 2;
        }
        for (int i = 0; i < 32; i++)
        {
            s2.push_back(y % 2);
            y = y / 2;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            cout<<s1[i]<<" ";
        }
        
        
        for (int i = l - 1; i < r; i++)
        {
            if (s1[i] == 0 && s2[i] == 1)
            {
                ans = ans + pow(2, i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        Solution ob;
        cout << ob.setSetBit(x, y, l, r) << "\n";
    }
    return 0;
}
// } Driver Code Ends