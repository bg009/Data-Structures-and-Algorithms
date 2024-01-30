#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, f(v, i, k, dp) + f(v, k, j, dp) + v[j] - v[i]);
    }

    return dp[i][j] = ans;
}

int cost(int n, int c, vector<int> &v)
{
    // Write your code here.
    v.push_back(0);
    v.push_back(n);

    sort(v.begin(), v.end());
    int t = v.size() - 1;

    vector<vector<int>> dp(v.size(), vector<int>(v.size(), -1));

    return f(v, 0, t, dp);
}