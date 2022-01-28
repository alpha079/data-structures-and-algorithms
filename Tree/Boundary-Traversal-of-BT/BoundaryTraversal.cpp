
//Boundary Traversal of tree
//Print left Boundary excluding leaf node
//Print leaf Nodes
//Print Right Boundary Excluding leaf node

class Solution{

    bool isLeaf(Node* root)
    {
        return !root->left && !root->right;
    }

    void printLeftBoundary(Node* root, vector<int>& ans)
    {
        Node* curr=root;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                ans.push_back(curr->data);
            }
            if(curr->left)
            {
                curr=curr->left;
            }
            else curr=curr->right;
        }
    }

    void printRightBoundary(Node* root, vector<int>& ans)
    {
        Node* curr=root;
        vector<int> temp;
        while(curr)
        {
            if(!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }
            if(curr->right)
            {
                curr=curr->right;
            }
            else curr=curr->left;
        }
   reverse(temp.begin(), temp.end());
     ans.push_back(temp);

    }
    void printLeaf(Node* root,vector<int>& ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
       if(root->left) printLeaf(root->left);
       if(root->right) printLeaf(root->right);


    }

public:
    vector<int> PrintBoundaryTraversal(Node* root)
    {
        if(root==NULL)return {};
        vector<int> ans;

        if(!isLeaf(root))
        {
            ans.push_back(root->data);
        }
        printLeftBoundary(root->left,ans);

        //Do inorder for leaf nodes
        printLeaf(root,ans);

        printRightBoundary(root->right,ans);
         return ans;
    }
}
