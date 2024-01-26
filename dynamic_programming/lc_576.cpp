#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    
    int row[4] = {1 , -1 , 0 , 0};
    int col[4] = {0 , 0 , -1 , 1};
    
    ll f(int n , int m , int i , int j , int c , vector<vector<vector<ll>>>& dp)
    {
        if(i >= n || j >= m || i < 0 || j < 0)
            return 1;
        
        if(c == 0)
            return 0;
        
        if(dp[i][j][c] != -1)
            return dp[i][j][c];
        
        int ans = 0;
        
        for(int k = 0 ; k < 4 ; k++)
            ans = (ans + f(n , m , i + row[k] , j + col[k] , c - 1 , dp)) % mod;
        
        return dp[i][j][c] = ans % mod;
    }
    
    
    int findPaths(int n, int m, int c, int i, int j) {
     
        vector<vector<vector<ll>>> dp(n , vector<vector<ll>>(m , vector<ll>(c + 1 , -1)));
        return f(n , m , i , j , c , dp);
        
    }
};