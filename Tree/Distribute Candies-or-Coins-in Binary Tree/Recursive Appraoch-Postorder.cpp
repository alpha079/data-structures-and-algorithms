// Solution link
//https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal
class Solution {
public:
    
   int helper(TreeNode* root,int& coins)
   {
       if(root==NULL)
           return 0;
       int l=helper(root->left,coins);
       int r=helper(root->right,coins);
       
       coins+=abs(l)+abs(r);
       
       return root->val+l+r-1;
   }
    int distributeCoins(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int coins=0;
        
        helper(root,coins);
        
        return coins;
        
    }
};
