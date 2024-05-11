//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution
{
public:
    bool isLucky(int n)
    {
        int x = 2;     // Initialize x to 2, the first divisor to check.
        while (x <= n) // Continue the loop until x is less than or equal to n.
        {
            if (n % x == 0)   // Check if n is divisible by x (not a prime number).
                return false; // If it's divisible, n is not a lucky number, return false.

            n -= n / x; // Reduce n by dividing it by x and subtracting the result.
            x++;        // Increment x to check the next divisor.
        }
        return true; // If no divisors are found, n is a lucky number, return true.
    }
};

//{ Driver Code Starts.
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution obj;
        // calling isLucky() function
        if (obj.isLucky(n))
            cout << "1\n"; // printing "1" if isLucky() returns true
        else
            cout << "0\n"; // printing "0" if isLucky() returns false
    }
}
// } Driver Code Ends