//Do it in Less then O(N)
int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> s;
        int sum=0;
        
        while(!s.empty() || root!=NULL)
        {
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;
                
            }
            root=s.top();s.pop();sum+=root->val;
            if(--k==0)
            {
                cout<<sum;
                return root->val;
            }
                
            root=root->right;
        }
        
     return -1;   
    }
    //Tc:- O(H+k) 
    //Space:- O(H) , O(N ) in worst case
