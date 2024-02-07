#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pr[10005];
    int sz[10005];

    void make_set(int a)
    {
        pr[a] = a;
        sz[a] = 1;
    }

    int find_set(int a)
    {
        if (pr[a] == a)
            return a;

        return pr[a] = find_set(pr[a]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        sz[a] += sz[b];
        pr[b] = a;
    }

    vector<bool> friendRequests(int n, vector<vector<int>> &v, vector<vector<int>> &l)
    {

        vector<bool> ans;

        for (int i = 0; i < n; i++)
            make_set(i);

        vector<int> adj[n];

        for (auto &x : v)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for (auto &x : l)
        {
            int i = x[0];
            int j = x[1];

            int a = find_set(i);
            int b = find_set(j);

            int flag = 1;

            for (auto &y : v)
            {
                int aa = find_set(y[0]);
                int bb = find_set(y[1]);

                if ((aa == a && bb == b) || (aa == b && bb == a))
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                ans.push_back(true);
                union_set(i, j);
            }

            else
                ans.push_back(false);
        }

        return ans;
    }
};