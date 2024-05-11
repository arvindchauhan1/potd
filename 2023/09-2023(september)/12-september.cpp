//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isPerfectNumber(long long n)
    {
        if (n <= 1)
            return 0; // If n is less than or equal to 1, it's not a perfect number.

        long long sum = 1; // 1 is always a proper divisor of any number.

        // Loop through all potential divisors from 2 to the square root of n.
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0) // Check if i is a divisor of n.
            {
                sum += i; // Add i to the sum if it's a divisor.

                if (i != n / i)   // Check if i is not equal to n / i to avoid adding n twice.
                    sum += n / i; // Add n / i to the sum as well (if it's not equal to i).
            }
        }

        // If sum is equal to n, then n is a perfect number; otherwise, it's not.
        return sum == n;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends