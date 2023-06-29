//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int calculateSumOfSquare(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += (n % 10) * (n % 10);
            n = n / 10;
        }
        return count;
    }
    bool isHappyNumber(int n)
    {
        int slow = n;
        int fast = n;

        while (true)
        {
            slow = calculateSumOfSquare(slow);                       // Move slow pointer one step using sum of squares of digits
            fast = calculateSumOfSquare(calculateSumOfSquare(fast)); // Move fast pointer two steps using sum of squares of digits

            // cout << slow << " " << fast << endl;

            if (fast == 1)
                return true; // Number is a happy number (reached 1)

            if (fast == slow)
                return false; // Number has entered a cycle, not a happy number
        }
    }
    int nextHappy(int N)
    {
        bool ans;
        while (true)
        {
            N++;
            ans = isHappyNumber(N);
            if (ans)
                break;
        }

        return N;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0;
}
// } Driver Code Ends