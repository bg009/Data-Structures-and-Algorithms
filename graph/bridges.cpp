#include <bits/stdc++.h>
using namespace std;

void f(vector<int> adj[], vector<vector<int>> &ans, int i, int pr, vector<int> &t, vector<int> &l, int &c)
{
    t[i] = c;
    l[i] = c++;

    for (auto &x : adj[i])
    {
        if (x == pr)
            continue;

        if (t[x] != INT_MAX)
        {
            l[i] = min(l[i], t[x]);
            continue;
        }

        f(adj, ans, x, i, t, l, c);

        l[i] = min(l[i], l[x]);

        if (l[x] > t[i])
            ans.push_back({x, i});
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<int> adj[v];

    for (auto &x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> t(v, INT_MAX);
    vector<int> l(v, INT_MAX);
    int c = 0;

    vector<vector<int>> ans;

    for (int i = 0; i < v; i++)
    {
        if (t[i] == INT_MAX)
            f(adj, ans, i, -1, t, l, c);
    }

    return ans;
}