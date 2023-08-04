// ! leetcode dp(easy)
#include <iostream>
#include <vector>

using namespace std;

//! recursive method
int fib(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

// !DP bottom to up approach

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = fib(n);
        cout << ans << endl;
    }

    return 0;
}