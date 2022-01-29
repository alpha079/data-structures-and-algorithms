//We have to check ,If the node is leaf node and if it value has 0, then Return NULL.


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        
        if(root->val==0 && root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        return root;
    }
};
