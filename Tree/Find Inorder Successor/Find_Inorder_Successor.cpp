An inorder successor of a node in the BST is the next node in the inorder sequence. For example, consider the following BST:

//I know that , In a BST, Left is smaller than root, Right is greater than root.
//If root->val==key, then i will Find Minimum in the Right of it, if exits
// If not , then I will return the root itself
 
//Find Inorder Successor

Node* findMinimum(Node* root)
{
    while (root->left) {
        root = root->left;
    }
 
    return root;
}
Node* FindSuccessor(Node* root, int key,Node* succ)
{
    if(root==NULL)
        return succ;
    if(root->val==key)
    {
        if(root->right!=NULL)
        {
            return FindMinimumRight(root->right);
        }
    }
    else if(key<root->val)

    {
        succ=root;
        return FindSuccessor(root->left,key,succ);

    }
    else return FindSuccessor(root->right,key,succ);

    return succ;
    //TC:- O(H), where H is height of the tree
}
