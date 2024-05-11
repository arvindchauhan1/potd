//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function
    void recurPermute(string s, int index, vector<string> &ans)
    {
        if (index == s.length() - 1)
        {
            ans.push_back(s);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            char t = s[index];
            swap(s[index], s[i]);
            recurPermute(s, index + 1, ans);
            swap(s[index], s[i]);
        }
    }

    vector<string> permutation(string S)
    {
        vector<string> ans;
        recurPermute(S, 0, ans);
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