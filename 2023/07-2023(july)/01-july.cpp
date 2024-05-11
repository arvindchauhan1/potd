//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        // Set bits in a binary number is represented by 1
        int rem = 0, count = 0;
        while (N > 0)
        {
            rem = N % 2;
            if (rem == 1)
                count++;
            N /= 2;
        }
        if (N == 1)
            count++;

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends