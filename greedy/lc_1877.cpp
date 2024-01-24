#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& v) {
        
        sort(v.begin() , v.end());
        
        int ans = INT_MIN;
        int i = 0;
        int j = v.size() - 1;
        
        while(i < j)
        {
            ans = max(ans , v[i] + v[j]);
            i++;
            j--;
        }
        
        return ans;
    }
};