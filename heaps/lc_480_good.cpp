#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pp pair<int , int>
    
    void f(priority_queue<pp>& a , priority_queue<pp , vector<pp> , greater<pp>>& b , vector<int>& c , int& i , int& aa , int& bb)
    {
        while(!a.empty() && a.top().second < i)
            {
                if(c[a.top().second] == 0)
                    aa--;
                
                else
                    bb--;
                
                c[a.top().second] = -1;
                a.pop();
            }
            
            while(!b.empty() && b.top().second < i)
            {
                if(c[b.top().second] == 0)
                    aa--;
                
                else
                    bb--;
                
                c[b.top().second] = -1;
                b.pop();
            }
            
    }
    
    
    vector<double> medianSlidingWindow(vector<int>& v, int k) {
        
        int n = v.size();
        int i = 0;
        int j = 0;
        
        vector<double> ans;
        
        priority_queue<pp> a;
        priority_queue<pp , vector<pp> , greater<pp>> b;
        
        vector<int> c(n , -1);
        
        int aa = 0;
        int bb = 0;
        
        while(j < n)
        {
            if(a.size() - aa <= b.size() - bb)
            {
                a.push({v[j] , j});
                c[j] = 0;
            }
            
            else
            {
                b.push({v[j] , j});
                c[j] = 1;
            }
            
            if(j - i + 1 < k)
            {
                j++;
                continue ;
            }
            
            f(a , b , c , i , aa , bb);
            
            while(!a.empty() && !b.empty() && a.top().first > b.top().first)
            {
                pp xa = a.top();
                pp xb = b.top();
                
                a.pop();
                b.pop();
                
                c[xa.second] = 1;
                c[xb.second] = 0;
                
                a.push(xb);
                b.push(xa);
                
                f(a , b , c , i , aa , bb);
            }
            
            f(a , b , c , i , aa , bb);
            
            while(a.size() - aa < (b.size() - bb) + 1)
            {
                pp temp = b.top();
                b.pop();
                
                c[temp.second] = 0;
                a.push(temp);
                
                f(a , b , c , i , aa , bb);
            }
            
            f(a , b , c , i , aa , bb);
            
            while(a.size() - aa > (b.size() - bb) + 1)
            {
                pp temp = a.top();
                a.pop();
                
                c[temp.second] = 1;
                b.push(temp);
                
                f(a , b , c , i , aa , bb);
            }
            
            
            double temp = 0;
            
            if(k % 2 == 0)
                temp = ((double)a.top().first + (double)b.top().first)/(double)2;
            
            else
                temp = a.top().first;
            
            ans.push_back(temp);
        
            if(c[i] != -1)
            {
                if(c[i] == 0)
                    aa++;
                
                else
                    bb++;
            }
            
            f(a , b , c , i , aa , bb);
            
            j++;
            i++;
        }
        
        return ans;
    }
};