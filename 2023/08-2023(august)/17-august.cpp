//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        vector<int> res(num, num + n);
        int m = (n + 1) / 2;

        // converting res array to palindrome
        while (m < n)
        {
            res[m] = res[n - m - 1];
            m++;
        }

        // checking if 'res' is greater than 'num'
        bool isResBig = false;
        for (int i = n / 2; i < n; i++)
        {
            if (res[i] > num[i])
            {
                isResBig = true;
                break;
            }
            if (res[i] < num[i])
                break;
        }

        if (isResBig)
            return res;

        m = (n % 2) ? n / 2 : (n / 2 - 1);
        int k = n / 2;
        // Incrementing numbers from the middle to the corners
        while (m >= 0)
        {
            if (res[m] < 9)
            {
                res[m] = res[k] = res[m] + 1;
                return res;
            }
            res[m] = res[k] = 0;
            m--;
            k++;
        }
        res[0] = 1;
        res.push_back(1);
        return res;
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
        int num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends