
class Solution {
public:
  void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for (auto x : adj[node]) {
      if (!vis[x]) {
        dfs(x, vis, adj, st);
      }
    }
    st.push(node);
  }

  void revDFS(int node, vector<int> transpose[], vector<int> &vis) {
    // cout<<node;
    vis[node] = 1;
    for (auto x : transpose[node]) {
      if (!vis[x]) {
        revDFS(x, transpose, vis);
      }
    }
  }
  // Function to find number of strongly connected components in the graph.
  int kosaraju(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i])
        dfs(i, vis, adj, st);
    }

    vector<int> transpose[V];

    for (int i = 0; i < V; i++) {
      vis[i] = 0;
      for (auto x : adj[i])
        transpose[x].push_back(i);
    }
    int count = 0;
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      if (!vis[node]) {
        revDFS(node, transpose, vis);
        // cout<<endl;
        count++;
      }
    }
    return count;
  }
};