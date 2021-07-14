int parent[10001];
int rank[10001];

void main() {
  makeSet(int n);
  //....//
}

void makeSet(int n) {
  for (int i = 0; i <= n; i++)
    parent[i] = i, rank[i] = 0;
}

void findPar(int node) {
  if (parent[node] == node)
    return node;

  return parent[node] = findPar(parent[node]);
}

void union(int u, int v) {
  u = findPar(u);
  v = findPar(v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}