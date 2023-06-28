#include <iostream>

using namespace std;

//! recursive method
int climbStairs(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int one_step = climbStairs(n - 1);
    int two_step = climbStairs(n - 2);

    return one_step + two_step;
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