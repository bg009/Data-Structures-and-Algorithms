#include<bits/stdc++.h>
using namespace std;

/*

Flatten a binary tree to ll 

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
        left = NULL;
        right = NULL;
    }
};

TreeNode* f(TreeNode* root)
{
    if(root == NULL)
        return NULL;
    
    TreeNode* l = f(root->left);
    TreeNode* r = f(root->right);
    
    root->left = NULL;
    
    if(l)
    root->right = l;
    
    while(l && l->right)
    {
        l = l->right;
    }
    
    if(l)
    l->right = r;
    
    return root;
}

void flatten(TreeNode* root) {
    
    f(root);
    
}