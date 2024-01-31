#include<bits/stdc++.h>
using namespace std;

class LockingTree
{
public:
    vector<int> vis;
    vector<int> pr;

    vector<vector<int>> adj;

    LockingTree(vector<int> &a)
    {

        pr = a;
        vector<int> temp(a.size(), -1);

        vector<vector<int>> ad(a.size());

        for (int i = 1; i < a.size(); i++)
        {
            ad[a[i]].push_back(i);
        }

        adj = ad;
        vis = temp;
    }

    bool lock(int n, int u)
    {

        if (vis[n] != -1)
            return false;

        vis[n] = u;
        return true;
    }

    bool unlock(int n, int u)
    {

        if (vis[n] != u)
            return false;

        vis[n] = -1;
        return true;
    }

    bool upgrade(int n, int u)
    {

        int i = n;
        int flag = 1;

        while (i != -1)
        {
            if (vis[i] != -1)
            {
                flag = 0;
                break;
            }

            i = pr[i];
        }

        if (flag == 0)
            return false;

        flag = 0;
        queue<int> q;
        q.push(n);

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (vis[i] != -1)
            {
                flag = 1;
                vis[i] = -1;
            }

            for (auto &x : adj[i])
            {
                q.push(x);
            }
        }

        if (flag == 0)
            return false;

        vis[n] = u;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */