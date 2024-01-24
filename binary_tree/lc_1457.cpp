#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
public:
    
    int f(TreeNode* root , vector<int>& v)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        v[root->val]++;
        
        if(!root->left && !root->right)
        {
                int flag = 0;
            
            for(int i = 1 ; i < 10 ; i++)
            {
                if(v[i] % 2 == 1)
                {
                    if(flag)
                    {
                        v[root->val]--;
                        return 0;
                    }
                    flag = 1;
                }
            }
            
            v[root->val]--;
            return 1;
        
        }
        
        int ans = f(root->left , v) + f(root->right , v);
        v[root->val]--;
        
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> v(10 , 0);
        return f(root , v);
        
    }
};