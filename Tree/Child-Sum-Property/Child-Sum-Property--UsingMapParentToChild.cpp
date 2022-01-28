//Optimise code

//We are starting from Root, and going towards the leaf nodes.
// We are only changing the values , if Root->val > left value + Right Value
void ChangeTree(Node* root)
{
    if(!root or !root->left and !root->right)
        return;

    int diff= root->val -(root->left ?root->left->val : 0) +(root->right ?root->right->val : 0);


    if(diff>0)
    {
        (root->left ? root->left : root->right)->val+=diff;
    }

    //if diff is negative, then don't chnage it now. After making every Node changed, at last make the chnages
    ChangeTree(root->left);
    ChangeTree(root->right);

    root->val=(root->left ?root->left->val : 0) +(root->right ?root->right->val : 0);
    //Time is:- O(N)
    //Left operations in tree;
}
