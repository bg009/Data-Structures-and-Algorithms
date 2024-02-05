#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pp pair<int , int> // dist , node
    int reachableNodes(vector<vector<int>>& e, int m, int n) {
        
        int ans = 0;
        vector<vector<int>> adj[n];
        
        for(auto& x : e)
        {
            adj[x[0]].push_back({x[1] , x[2]});
            adj[x[1]].push_back({x[0] , x[2]});
        }
        
        vector<int> dist(n , INT_MAX);
        priority_queue<pp , vector<pp> , greater<pp>> q;
        
        dist[0] = 0;
        q.push({0 , 0});
        
        while(!q.empty())
        {
            int i = q.top().second;
            int d = q.top().first;
            
            q.pop();
            
            for(auto& x : adj[i])
            {
                if(dist[x[0]] > d + x[1] + 1)
                {
                    dist[x[0]] = d + x[1] + 1;
                    q.push({d + x[1] + 1 , x[0]});
                }
            }
        }
        
        for(auto& x : e)
        {
            int a = x[0];
            int b = x[1];
            
            int c = x[2];
            
            if(dist[a] < m)
            {
                int k = m - dist[a];
                k = min(k , c);
                
                ans += k;
                c = c - k;
            }
            
            a = b;
            
            if(dist[a] < m)
            {
                int k = m - dist[a];
                k = min(k , c);
                
                ans += k;
                c = c - k;
            }
            
        }
        
        for(auto& x : dist)
        {
            if(x <= m)
                ans++;
        }
        
        return ans;
        
    }
};