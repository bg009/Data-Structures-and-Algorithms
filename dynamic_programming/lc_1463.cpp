#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
    int col[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    int f(vector<vector<int>> &v, int i, int a, int b, vector<vector<vector<int>>> &dp)
    {
        if (i >= v.size() || a < 0 || b < 0 || a >= v[0].size() || b >= v[0].size())
            return 0;

        if (dp[i][a][b] != -1)
            return dp[i][a][b];

        int ans = 0;
        int temp = 0;

        if (a == b)
            temp = v[i][a];

        else
            temp = v[i][a] + v[i][b];

        for (int k = 0; k < 9; k++)
            ans = max(ans, f(v, i + 1, a + row[k], b + col[k], dp));

        return dp[i][a][b] = ans + temp;
    }

    int cherryPickup(vector<vector<int>> &v)
    {

        int n = v.size();
        int m = v[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return f(v, 0, 0, m - 1, dp);
    }
};