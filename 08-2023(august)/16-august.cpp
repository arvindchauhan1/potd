//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    unsigned long long int fact(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        return (n * fact(n - 1)) % mod;
    }
    // Function to find the nth catalan number.
    int findCatalan(int n)
    {
        unsigned long long int nom = fact(2 * n);
        unsigned long long int a = fact(n + 1);
        unsigned long long int b = fact(n);
        unsigned long long int den = (a * b) % mod;

        // Calculate the modular inverse of den
        // This is equivalent to den^(mod-2) under modulo mod
        // Since you are working in a modular arithmetic context with a modulus value (mod), simply dividing the numerator by the denominator might not yield the correct result.
        // To handle division in modular arithmetic, you need to compute the modular inverse of the denominator and then multiply it with the numerator.
        unsigned long long int den_inverse = 1;
        int power = mod - 2; // Since mod is prime
        while (power > 0)
        {
            if (power % 2 == 1)
            {
                den_inverse = (den_inverse * den) % mod;
            }
            den = (den * den) % mod;
            power /= 2;
        }

        // Calculate the result using the modular inverse of den
        unsigned long long int result = (nom * den_inverse) % mod;

        return result;
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
        Solution obj;
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends