//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        bool isNeg = false;
        for (int i = 0; i < s1.length(); i++)
            if (s1[i] == '-')
            {
                isNeg ^= true;
                s1 = s1.substr(i + 1);
                break;
            }

        for (int i = 0; i < s2.length(); i++)
            if (s2[0] == '-')
            {
                isNeg ^= true;
                s2 = s2.substr(1);
                break;
            }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int n = s1.length(), m = s2.length();
        vector<int> v(n + m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int t = (int(s1[i] - '0') * int(s2[j] - '0')) + v[i + j];
                if (t > 9)
                {
                    v[i + j] = t % 10;
                    v[i + j + 1] += t / 10;
                }
                else
                    v[i + j] = t;
            }
        }
        int i = 0;
        reverse(v.begin(), v.end());
        while (v[i] == 0)
            i++;

        string res;
        while (i < v.size())
        {
            res.push_back(char(v[i] + '0'));
            i++;
        }

        return isNeg ? '-' + res : res;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
}
// } Driver Code Ends