//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Define the maximum value for the array and the modulo value.
    const int MAXN = 1e5 + 5;
    const int MOD = 100000;

    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        int n = arr.size();

        // Create a boolean array to mark visited numbers.
        vector<bool> visited(MAXN, false);
        visited[start] = true;

        // Create a queue for BFS.
        queue<int> q;
        q.push(start);

        // Initialize the number of steps.
        int steps = 0;

        // Start BFS.
        while (!q.empty())
        {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++)
            {
                // Get the current number from the front of the queue.
                int x = q.front();
                q.pop();

                // If we reach the target number 'end', return the number of steps.
                if (x == end)
                {
                    return steps;
                }

                // Try all possible multiplications from the 'arr' vector.
                for (int num : arr)
                {
                    // Calculate the new number after multiplication and modulo operation.
                    int newX = (x * 1LL * num) % MOD;

                    // If the new number hasn't been visited, mark it as visited and enqueue it.
                    if (!visited[newX])
                    {
                        q.push(newX);
                        visited[newX] = true;
                    }
                }
            }
            // Increment the number of steps since we're exploring the next level of numbers.
            steps++;
        }

        // If 'end' is unreachable from 'start', return -1.
        return -1;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends