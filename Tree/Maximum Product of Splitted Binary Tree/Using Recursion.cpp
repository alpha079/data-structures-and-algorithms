//First Calculate the TotalSum of the tree.
//Now for each subtree . calculate seaparate totalSum of each subtree, subtract from TotalSum, and then find the product.
//If it is maximum, store in the result.

class Solution {
public:
    
    long long ans=0;
    
    int getTotal(TreeNode* root)
    {
        return root->val + (root->left ? getTotal(root->left):0) + (root->right ? getTotal(root->right):0);
    }
    
    int getProduct(TreeNode* root, long long totalSum,long long &res)
        
    {
        long tmp=root->val;
        
        tmp+= (root->left ? getProduct(root->left,totalSum,res) : 0);
        
        tmp+= (root->right ? getProduct(root->right,totalSum,res) : 0);
        
        res = max(res, (totalSum - tmp) * tmp); 
         
        return tmp;
        
        
    }
    
    int maxProduct(TreeNode* root) {
        
        long long totalSum=getTotal(root);
        long long res=0;
        getProduct(root,totalSum,res);
        res=res%1000000007;
        return res;
    }
};
