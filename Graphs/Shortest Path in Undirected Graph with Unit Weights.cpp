int BFS(vector<int> adj[], int N, int src) {
  int dis[N];
  queue<int> q;
  for (int i = 0; i < N; i++)
    dis[i] = INT_MAX;

  q.push(src);
  dis[src] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto x : adj[node]) {
      if (dis[x] > dis[node] + 1) {
        dis[x] = dis[node] + 1;
        q.push(x);
      }
    }
  }
  return dis;
}