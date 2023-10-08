//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    void recurPermute(string s, string ds, vector<string> &ans, vector<bool> &m)
    {
        if (ds.length() == s.length())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (!m[i])
            {
                m[i] = 1;
                ds += s[i];
                recurPermute(s, ds, ans, m);
                ds.pop_back();
                m[i] = 0;
            }
        }
    }

    vector<string> permutation(string S)
    {
        vector<string> ans;
        string ds;
        vector<bool> m(S.length(), false);
        recurPermute(S, ds, ans, m);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for (string s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends