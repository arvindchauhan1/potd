//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b)
    {
        vector<int> res; // Initialize a vector to store the result.

        // Sort the input vectors a and b in ascending order.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Create a max heap (priority queue) to store pairs of sums and their corresponding indices.
        priority_queue<pair<int, pair<int, int>>> pq;

        // Create a set to keep track of visited pairs of indices.
        set<pair<int, int>> st;

        // Push the sum of the largest elements from both vectors and their indices into the priority queue and set.
        pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
        st.insert({n - 1, n - 1});

        while (k--)
        {
            auto p = pq.top();       // Get the pair with the maximum sum from the priority queue.
            int sum = p.first;       // Extract the sum.
            int i = p.second.first;  // Extract the index from vector a.
            int j = p.second.second; // Extract the index from vector b.

            res.push_back(sum); // Add the maximum sum to the result vector.
            pq.pop();           // Remove the maximum sum pair from the priority queue.

            // Check if the pair with index (i - 1, j) has not been visited yet.
            if (st.find({i - 1, j}) == st.end())
            {
                pq.push({a[i - 1] + b[j], {i - 1, j}}); // Push the sum and indices to the priority queue.
                st.insert({i - 1, j});                  // Mark the pair as visited in the set.
            }

            // Check if the pair with index (i, j - 1) has not been visited yet.
            if (st.find({i, j - 1}) == st.end())
            {
                pq.push({a[i] + b[j - 1], {i, j - 1}}); // Push the sum and indices to the priority queue.
                st.insert({i, j - 1});                  // Mark the pair as visited in the set.
            }
        }

        return res; // Return the vector containing the k maximum sums.
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends