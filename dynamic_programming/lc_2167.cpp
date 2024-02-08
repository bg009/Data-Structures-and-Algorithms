#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTime(string s)
    {

        int n = s.size();
        vector<int> a(n, 0);
        vector<int> b(n, 0);

        int c = 0;

        if (s[0] == '1')
            a[0] = 1;

        if (s[n - 1] == '1')
            b[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
            {
                a[i] = min(i + 1, a[i - 1] + 2);
            }

            else
            {
                a[i] = a[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                b[i] = min(n - i, b[i + 1] + 2);
            }

            else
            {
                b[i] = b[i + 1];
            }
        }

        int ans = min(b[0], a[n - 1]);

        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, a[i] + b[i + 1]);
        }

        return ans;
    }
};