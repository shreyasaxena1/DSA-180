//Got no platform to run

//striver's taking decimal places too

#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * number;
    }
    return ans;
}

double getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << low << " " << high << endl;

    // just to check
    cout << pow(m, (double)(1.0 / (double)n));
}
int main()
{
    int n, m;
    cin >> n >> m;
    getNthRoot(n, m);
    return 0;
}

//Solved at gfg - need integer roots else -1

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int low = 1;
        int high = m;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (pow(mid, n) < m)
                low = mid + 1;
            else if (pow(mid, n) > m)
                high = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};