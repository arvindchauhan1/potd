//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Initialize the result
        double res = 0;

        // Define a custom comparator to sort the 'arr' based on value-to-weight ratio in descending order
        auto comparator = [](const auto &left, const auto &right)
        { return (double)left.value / left.weight > (double)right.value / right.weight; };

        // Sort 'arr' using the custom comparator
        std::sort(arr, arr + n, comparator);

        // Iterate through the sorted array to fill the knapsack
        for (int i = 0; i < n; i++)
        {
            // If the entire item can fit into the knapsack
            if (W > arr[i].weight)
            {
                // Add the entire value of the item to the result
                res += arr[i].value;
                // Reduce the remaining capacity of the knapsack
                W -= arr[i].weight;
            }
            else
            {
                // If only a fraction of the item can fit into the knapsack
                res += ((double)arr[i].value / arr[i].weight) * W;
                // Break the loop as the knapsack is full
                break;
            }
        }

        // Return the final result
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends