#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int f(string& s , vector<int>& v , char prev)
    {
        int ans = 0;
        int i = 0;
        int j = 0;
        
        int flag = 0;
        
        while(j < s.size())
        {
            if(s[j] != prev)
                flag++;
            
            while(i <= j && flag > 1)
            {
                if(s[i] != prev)
                    flag--;
                
                i++;
            }
             
            ans = max(ans , j - i + 1);
            j++;
        }
        
        return min(ans , v[prev - 'a']);
    }
    
    int maxRepOpt1(string s) {
        
        vector<int> v(26 , 0);
        
        for(auto& x : s)
        v[x - 'a']++;
        
        int ans = 0;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            ans = max(ans , f(s , v , (char)('a' + i)));
        }
        
        return ans;
    }
};