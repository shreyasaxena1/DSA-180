class Solution {
public:
  // Function to return list containing vertices in Topological order.
  void getTopoSortOrder(int node, vector<int> &vis, stack<int> &s,
                        vector<int> adj[]) {
    vis[node] = 1;
    for (auto x : adj[node]) {
      if (!vis[x])
        getTopoSortOrder(x, vis, s, adj);
    }
    s.push(node);
  }
  vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> topo;
    stack<int> s;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i])
        getTopoSortOrder(i, vis, s, adj);
    }

    while (!s.empty()) {
      topo.push_back(s.top());
      s.pop();
    }

    return topo;
  }
};