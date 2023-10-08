//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int isDivisible(string s)
    {
        // If the difference between Np.vof non-zero odd and non-zero even bits from the right is divisible by 3, then the number is divisible by 3.
        int odd = 0, even = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                if (i % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }

        return abs(even - odd) % 3 == 0 ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
    return 0;
}

// } Driver Code Ends