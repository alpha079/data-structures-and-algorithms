//Print All Cousins of a Given Node

//Recursion Appraoch:- 
//First Find the level of the Given Node. We know that for cousins , parent should be different ,but Grandparent might be the same.
//After findng, start from Root, Just Ignore the siblings of the given node

Input : root of below tree 
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7
       and pointer to a node say 5.

Output : 6, 7

//TC:- O(N)
 //SC:- O(n)
int getLevel(Node* root, Node* node, int &level)
{
    if(root==NULL)
        return 0;
    if(root==node)
        return level;

    int down=getLevel(root->left,node,level+1);
    if(down!=0)
    {
        return level;
    }
    return getLevel(root->right,node,level+1);

}
void PrintLevel(Node* root, Node* node,int level,vector<int>& res)
{
    if(root==NULL)
        return;
    if(level==1)
    {
        res.push_back(root->val);
        return;

    }

    if((root->left!=NULL && root->left!=node) && (root->right!=NULL && root->right!=node))
    {
        PrintLevel(root->left,node,level-1,res);
        PrintLevel(root->right,node,level-1,res);
    }
}
vector<int> FindCousin(Node* root, Node* node)
{
    if(root==NULL || root->val==node->val)
        return {};
    vector<int> res;

    int level=getLevel(root,node,1);
    PrintLevel(root,node,level,res);
    return res;
}
