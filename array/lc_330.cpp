#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long

    int minPatches(vector<int> &v, int n)
    {

        int ans = 0;
        ll till = 0;

        int j = 0;
        ll i = 0;

        for (i; i <= (ll)n;)
        {
            if (till >= n)
                break;

            while (j < v.size() && v[j] <= i)
            {
                till += (ll)v[j];
                j++;
            }

            if (till >= i)
            {
                i = till + 1LL;
                continue;
            }

            ans++;
            till += (ll)i;
            i = till + 1LL;
        }

        return ans;
    }
};