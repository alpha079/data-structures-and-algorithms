//MInimum Depth of a Binary  lC 111

//Use BFs, if at any node, you found , Root->left==NULL, Root->right==NULL, return res from there
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        //MInimum Depth using BFS
        //Using Normal Max Recursion , we will stuck in test case
        //2, null, 3,4,5,null,null,6
        //Ans is 3 , but that code gives 4. So its wrong
        
        queue<TreeNode*> q;
        q.push(root);
        int res=0;
        while(!q.empty())
        {
            res++;
            int _size=q.size();
            for(int i=0;i<_size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                if(curr->left==NULL && curr->right==NULL)
                    return res;
            }
        }
        return -1;
    }
TC:- O(N)
SC:- O(N)
