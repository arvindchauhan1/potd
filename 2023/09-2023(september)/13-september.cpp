//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findLargest(int n, int s)
    {
        // Step 1: Check if s is non-positive and n is greater than 1, return "-1"
        if (s <= 0 && n > 1)
            return "-1";

        // Step 2: Initialize an empty string to store the result
        string res = "";

        // Step 3: Loop through each digit of the result string
        for (int i = 0; i < n; i++)
        {
            // Step 4: If s is greater than or equal to 9, add '9' to the result
            if (s >= 9)
            {
                res += '9';
                s -= 9;
            }
            // Step 5: If s is less than 9, add the remaining s as a digit to the result
            else
            {
                res += s + '0'; // Convert the integer to a character
                s = 0;          // Set s to 0 as it has been fully used
            }
        }

        // Step 6: If there is any remaining s, return "-1", otherwise return the result
        return s > 0 ? "-1" : res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends