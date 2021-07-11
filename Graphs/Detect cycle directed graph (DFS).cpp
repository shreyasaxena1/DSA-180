class Solution {
public:
  // Function to detect cycle in a directed graph.
  bool checkCycleDFS(int node, vector<int> &vis, vector<int> &dfsVis,
                     vector<int> adj[]) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto x : adj[node]) {
      if (!vis[x]) {
        if (checkCycleDFS(x, vis, dfsVis, adj))
          return true;
      } else if (dfsVis[x])
        return true;
    }
    dfsVis[node] = 0;
    return false;
  }
  bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (checkCycleDFS(i, vis, dfsVis, adj))
          return true;
      }
    }
    return false;
  }
};