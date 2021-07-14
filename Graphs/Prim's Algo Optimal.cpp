#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[]) {
  int parent[N];

  int key[N];

  bool mst[N];

  for (int i = 0; i < N; i++)
    key[i] = INT_MAX, mst[i] = false;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  key[0] = 0;
  parent[0] = -1;
  pq.push({0, 0});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    mstSet[u] = true;

    for (auto it : adj[u]) {
      int v = it.first;
      int weight = it.second;
      if (mstSet[v] == false && weight < key[v]) {
        parent[v] = u;
        key[v] = weight;
        pq.push({key[v], v});
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
};