class Solution {
public:
    
    void Inorder(TreeNode* root, int& k, int& cnt)
    {
        if(root==NULL)return;
        
        Inorder(root->left,k,cnt);
        k--;
        if(k==0){cnt=root->val;}
        Inorder(root->right,k,cnt);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return 0;
            int cnt=0;
            Inorder(root,k,cnt);
        return cnt;
        
    }

    //Tc:- O(n),
    //Recursion space is used.
};
