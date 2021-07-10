bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
  for (auto it : adj[node]) {
    if (color[it] == -1) {
      color[it] = 1 - color[node];
      if (!bipartiteDfs(it, adj, color)) {
        return false;
      }
    } else if (color[it] == color[node])
      return false;
  }
  return true;
}
bool checkBipartite(vector<int> adj[], int n) {
  int color[n];
  memset(color, -1, sizeof color);
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 1;
      if (!bipartiteDfs(i, adj, color)) {
        return false;
      }
    }
  }
  return true;
}

/*
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

// bipartite graph example
*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5
// not bipartite example
*/