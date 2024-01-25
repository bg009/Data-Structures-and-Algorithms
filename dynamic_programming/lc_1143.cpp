#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int f(string& a , string& b , int i , int j , vector<vector<int>>& dp)
    {
        if(i >= a.size() || j >= b.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(a[i] == b[j])
            return dp[i][j] = 1 + f(a , b , i + 1 , j + 1 , dp);
        
        return dp[i][j] = max(f(a , b , i + 1 , j , dp) , f(a , b , i , j + 1 , dp));
    }
        
    
    
    int longestCommonSubsequence(string a, string b) {
    
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            for(int j = m - 1 ; j >= 0 ; j--)
            {
                if(a[i] == b[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                
                else
                    dp[i][j] = max(dp[i + 1][j] , dp[i][j + 1]);
            }
        }
        
        return dp[0][0];
        
    }
};