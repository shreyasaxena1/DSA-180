#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    //As per constraints
    int t[1002][1002];

    int max(int n, int m)
    {
        if (n > m)
            return n;
        else
            return m;
    }

public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n == 0)
        {
            return 0;
        }
        if (t[n][W] != -1) //already solved subproblem ? 
            return t[n][W];

        if (wt[n - 1] <= W)
        {
            return t[n][W] = max(val[n - 1] + f(W - wt[n - 1], wt, val, n - 1), f(W, wt, val, n - 1));
        }
        else if (wt[n - 1] > W)
        {
            return f(W, wt, val, n - 1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        
        memset(t, -1, sizeof t);
        return f(W, wt, val, n);
    }
};