#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        int a = sqrt(n);

        if (n == a * a)
            return 1;

        int ans = INT_MAX;

        for (int i = a; i >= 1; i--)
        {
            int temp = f(n - (i * i), dp) + 1;
            ans = min(ans, temp);
        }

        return dp[n] = ans;
    }

    int numSquares(int n)
    {

        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};