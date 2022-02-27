
class Solution {
public:
    unordered_map<string,int> map;
    vector<TreeNode*> ans;
    
    string inorder(TreeNode* root)
    {
        if(root==NULL)
            return "";
        string str="(";
        str+=inorder(root->left);
        str+=to_string(root->val);
        str+=inorder(root->right);
       str+=")";
        
        if(map[str]==1)
        {
            ans.push_back(root);
        }
        map[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        inorder(root);
        
        for(auto it: map)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        return ans;
        
        
    }
};
