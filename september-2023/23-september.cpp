//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int equilibriumPoint(long long a[], int n)
    {
        long long smr = 0; // sum of elements to the right
        long long sml = 0; // sum of elements to the left

        // Calculate the total sum of all elements in the array
        for (int i = 0; i < n; i++)
        {
            smr += a[i];
        }

        for (int i = 0; i < n; i++)
        {
            smr -= a[i]; // Subtract the current element from the sum of elements to the right

            // Check if the sum of elements to the left is equal to the sum of elements to the right
            if (sml == smr)
            {
                return i + 1; // Equilibrium point found, return the index
            }

            sml += a[i]; // Add the current element to the sum of elements to the left
        }

        return -1; // No equilibrium point found, return -1
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends