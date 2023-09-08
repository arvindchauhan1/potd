//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to perform a Depth-First Search (DFS) traversal of the graph

    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1; // Mark the current node as visited.

        // Iterate through all adjacent nodes of the current node.
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, adj); // Recursively visit unvisited adjacent nodes.
        }
    }

    // find a Mother Vertex.
    int findMotherVertex(int V, vector<int> adj[])
    {
        int ans = -1;          // Initialize the answer to -1 (no mother vertex found yet).
        vector<int> vis(V, 0); // Create a visited array to track visited nodes.

        // Step 1: Perform a DFS traversal to find a potential mother vertex.
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj); // Call DFS on unvisited nodes.
                ans = i;          // Update the potential mother vertex.
            }
        }

        // Step 2: Check if the potential mother vertex is indeed a mother vertex.

        vector<int> vis2(V, 0); // Create another visited array.
        dfs(ans, vis2, adj);    // Perform DFS starting from the potential mother vertex.

        // Check if any node was left unvisited in the second DFS traversal.
        for (auto x : vis2)
        {
            if (x == 0)
                return -1; // If any node is unvisited, there is no mother vertex.
        }

        return ans; // Return the potential mother vertex as the result.
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
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        int ans = obj.findMotherVertex(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends