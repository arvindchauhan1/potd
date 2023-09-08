//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
    {
        // Create a 2D vector to store the adjacency list for 'V' vertices
        vector<vector<int>> ans(V);

        // Loop through each edge in the 'edges' vector
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i].first;  // Get the first vertex of the edge
            int b = edges[i].second; // Get the second vertex of the edge

            // Add 'b' to the adjacency list of 'a' and vice versa (since it's an undirected graph)
            ans[a].push_back(b);
            ans[b].push_back(a);
        }

        // Return the adjacency list for each vertex
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> edges;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for (int i = 0; i < V; i++)
        {
            sort(adj[i].begin(), adj[i].end());
            for (auto it : adj[i])
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends