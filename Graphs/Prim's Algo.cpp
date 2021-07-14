// Solved at GFG
// Here graph declared as vector<vector<int>>adj[]

class Solution {
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[]) {
    int key[V];
    bool mst[V];
    int part[V];

    for (int i = 0; i < V; i++)
      key[i] = INT_MAX, mst[i] = false, part[i] = -1;

    key[0] = 0;
    part[0] = -1;

    for (int i = 0; i < V - 1; i++) {
      int mini = INT_MAX, u;
      for (int v = 0; v < V; v++) {
        if (mst[v] == false && key[v] < mini)
          mini = key[v], u = v;
      }
      mst[u] = true;

      for (auto x : adj[u]) {
        int v = x[0];
        int wt = x[1];
        if (mst[v] == false && wt < key[v]) {
          key[v] = wt;
          part[v] = u;
        }
      }
    }
    int sum = 0;
    for (int i = 1; i < V; i++) {
      for (auto x : adj[part[i]]) {
        if (x[0] == i)
          sum += x[1];
      }
    }
    return sum;
  }
};