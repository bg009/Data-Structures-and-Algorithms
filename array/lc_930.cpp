#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &v, int k)
    {

        int ans = 0;
        map<int, int> m;
        m[0] = 1;

        int t = 0;

        for (int i = 0; i < v.size(); i++)
        {
            t += v[i];
            m[t]++;

            ans += m[t - k];
        }

        if (k == 0)
            ans -= v.size();

        return ans;
    }
};