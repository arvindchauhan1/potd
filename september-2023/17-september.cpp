//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n)
    {
        vector<long long> fibbNumbers;
        if (n <= 0)
        {
            return fibbNumbers; // Return an empty vector for invalid input
        }

        fibbNumbers.push_back(1); // First Fibonacci number (changed from 0 to 1)
        if (n == 1)
        {
            return fibbNumbers;
        }

        fibbNumbers.push_back(1); // Second Fibonacci number (changed from 1 to 1)
        if (n == 2)
        {
            return fibbNumbers;
        }

        // Generate the remaining Fibonacci numbers
        for (int i = 2; i < n; ++i)
        {
            long long nextFibb = fibbNumbers[i - 1] + fibbNumbers[i - 2];
            fibbNumbers.push_back(nextFibb);
        }

        return fibbNumbers;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of elements
        int n;
        cin >> n;
        Solution obj;
        // calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        // printing the elements of vector
        for (long long i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends