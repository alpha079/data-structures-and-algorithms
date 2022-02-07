class Solution
{
  public:
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return ans;
        ans.push_back(root->val);
        dfs(root->left, true, false);
        dfs(root->right, false, true);
        return ans;
    }
    void dfs(TreeNode *root, bool lft, bool rgt)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            ans.push_back(root->val);
            return;
        }
        if (lft)
            ans.push_back(root->val);
        dfs(root->left, lft, rgt && !root->right);
        dfs(root->right, lft && !root->left, rgt);
        if (rgt)
            ans.push_back(root->val);
    }
};
