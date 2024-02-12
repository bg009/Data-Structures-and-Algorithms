#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define pp vector<int>

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int minimumTime(vector<vector<int>> &v)
    {

        int n = v.size();
        int m = v[0].size();

        priority_queue<pp, vector<pp>, greater<pp>> q;
        q.push({0, 0, 0});

        if (v[0][1] > 1 && v[1][0] > 1)
            return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        while (!q.empty())
        {
            int t = q.top()[0];
            int i = q.top()[1];
            int j = q.top()[2];

            q.pop();

            if (vis[i][j] == 1)
                continue;

            vis[i][j] = 1;

            if (i == n - 1 && j == m - 1)
                return t;

            for (int k = 0; k < 4; k++)
            {
                int a = i + row[k];
                int b = j + col[k];

                if (a < 0 || b < 0 || a >= n || b >= m || vis[a][b] == 1)
                    continue;

                if (v[a][b] <= t + 1)
                {
                    q.push({t + 1, a, b});
                }

                else
                {
                    if ((v[a][b] - t) % 2 == 0)
                        q.push({v[a][b] + 1, a, b});

                    else
                        q.push({v[a][b], a, b});
                }
            }
        }

        return -1;
    }
};