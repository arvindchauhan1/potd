#include <iostream>
#include <vector>

using namespace std;

//! recursive method
// int climbStairs(int n)
// {
//     if (n == 0)
//         return 1;
//     if (n < 0)
//         return 0;

//     int one_step = climbStairs(n - 1);
//     int two_step = climbStairs(n - 2);

//     return one_step + two_step;
// }

// !DP bottom to up approach
int climbStairs(int n)
{
    int one = 1; // Initialize the variable "one" to represent the number of distinct ways to reach the first step (base case for n = 1)
    int two = 1; // Initialize the variable "two" to represent the number of distinct ways to reach the second step (base case for n = 2)

    for (int i = 0; i < n - 1; i++) // Iterate from the third step up to the n-th step
    {
        int temp = one;  // Temporary variable to store the previous value of "one" before updating it
        one = one + two; // Update "one" by adding the previous "one" and "two" (number of ways to reach the current step)
        two = temp;      // Update "two" to store the previous value of "one" (number of ways to reach the previous step)
    }
    return one; // Return the final value of "one" which represents the total number of distinct ways to reach the top step
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = climbStairs(n);
        cout << ans << endl;
    }

    return 0;
}