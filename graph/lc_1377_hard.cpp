#include<bits/stdc++.h>
using namespace std;

/*Just used bfs....not a very hard problem*/


class Solution {
public:
    #define pp pair<int , double>
    double frogPosition(int n, vector<vector<int>>& e, int t, int b) {
        
        vector<int> adj[n];
        b--;
        
        for(auto& x : e)
        {
            adj[x[0] - 1].push_back(x[1] - 1);
            adj[x[1] - 1].push_back(x[0] - 1);
        }
     
        queue<pp> q;
        q.push({0 , 1});
        
        vector<int> vis(n , 0);
        vis[0] = 1;
        
        int c = 0;
        
        while(!q.empty())
        {
            int l = q.size();
            
            while(l--)
            {
                int a = q.front().first;
                double temp = q.front().second;
                
                q.pop();
                
                if(a == b)
                {
                    if(t == c || (a != 0 && adj[a].size() == 1) || (a == 0 && adj[a].size() == 0))
                    return temp;
                    
                    else
                        return 0;
                }
                
                if(a != 0 && adj[a].size() == 1)
                    continue ;
                
                double aa = 1/(double)(adj[a].size() - 1);
                
                if(a == 0)
                aa = 1/(double)(adj[a].size());
                
                temp = temp*aa;
                
                for(auto& x : adj[a])
                {
                    if(vis[x] == 1)
                        continue ;
                    
                    vis[x] = 1;
                    q.push({x , temp});
                }
            }
            
            if(c == t)
                return 0;
            
            c++;
        }
        
        return 0;
    }
};