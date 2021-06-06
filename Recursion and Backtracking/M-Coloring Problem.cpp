//TC - O(N^m)  SC - O(N)

bool isSafe(int node, int colors[], bool graph[101][101], int N, int col)
{
    for (int k = 0; k < N; k++)
    {
        if (k != node && graph[k][node] == 1 && colors[k] == col) // check if adjacent has same color
            return false;
    }
    return true;
}

bool solve(int node, int colors[], int m, int N, bool graph[101][101])
{
    if (node == N)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, colors, graph, N, i))
        {
            colors[node] = i;
            if (solve(node + 1, colors, m, N, graph) == true)
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int colors[N] = {0};

    return solve(0, colors, m, N, graph);
}