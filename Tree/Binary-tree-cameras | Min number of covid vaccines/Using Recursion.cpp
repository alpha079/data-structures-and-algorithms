You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.
  
  
  //Very Important question
//See this video for Explanation
// https://www.youtube.com/watch?v=fORHMo5yzNk

class Solution {
public:
    int cnt=0;
    
    string CountCamera(TreeNode* root)
    {
        if(root==NULL)
            return"ok";
        string left=CountCamera(root->left);
        string right=CountCamera(root->right);
        
        if(left=="want" || right=="want")
        {
            cnt++;
            return "provide";
        }
        else if(left=="provide" || right=="provide")
        {
            return "ok";
        }
        else return "want";
    }
    int minCameraCover(TreeNode* root) {
       
        if(CountCamera(root)=="want")
        {
            cnt++;
        }
        
        return cnt;
        
    }
};
