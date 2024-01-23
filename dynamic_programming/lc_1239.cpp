#include<bits/stdc++.h>
using namespace std;
/*
A very interesting question...used bitmask and dp
*/


int f(vector<string>& v , int i , int vis , map<pair<int , int> , int>& dp)
{
    if(i >= v.size())
    {
        int ans = 0;
        
        while(vis)
        {
            if(vis % 2 == 1)
                ans++;
            
            vis = vis/2;
        }
        
        return ans;
    }
    
    if(dp.find({i , vis}) != dp.end())
        return dp[{i , vis}];
    
    vector<int> a(26 , 0);
    int temp = vis;
    
    int ans = f(v , i + 1 , vis , dp);
    int flag = 0;
    
    for(auto& x : v[i])
    {
        int t = (int)(x - 'a');
        a[x - 'a']++;
        
        if(a[x - 'a'] > 1)
        {
            flag = 1;
            break;
        }
        
        if((vis & (1 << t)) != 0)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag)
        return dp[{i , temp}] = ans;
    
    for(auto& x : v[i])
    {
        int t = (int)(x - 'a');
        t = (1<<t);
        
        vis = vis | t;
    }
    
    return dp[{i , temp}] = max(ans , f(v , i + 1 , vis , dp));
}


int maxLength(vector<string>& v) {
    
    map<pair<int , int> , int> dp;
    return f(v , 0 , 0 , dp);
    
}
