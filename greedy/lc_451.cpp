#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {

        unordered_map<char, int> m;

        for (auto &x : s)
            m[x]++;

        vector<pair<int, char>> a;

        for (auto &x : m)
        {
            a.push_back({x.second, x.first});
        }

        sort(a.rbegin(), a.rend());

        string ans = "";

        for (auto &x : a)
        {
            for (int i = 0; i < x.first; i++)
                ans.push_back(x.second);
        }

        return ans;
    }
};