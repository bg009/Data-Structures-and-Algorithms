#include <bits/stdc++.h>
using namespace std;

set<TreeNode<int> *> s;

void f(TreeNode<int> *root, int &k, int sum, int &ans)
{
    if (root == NULL)
        return;

    if (s.find(root) == s.end())
    {
        f(root->left, k, 0, ans);
        f(root->right, k, 0, ans);
        s.insert(root);
    }

    sum += root->data;

    if (sum == k)
    {
        ans++;
    }

    f(root->left, k, sum, ans);
    f(root->right, k, sum, ans);
}

int noWays(TreeNode<int> *root, int k)
{
    // Write your code here.
    if (root == NULL)
        return 0;

    int ans = 0;
    int sum = 0;

    f(root, k, 0, ans);
    s.clear();
    return ans;
}