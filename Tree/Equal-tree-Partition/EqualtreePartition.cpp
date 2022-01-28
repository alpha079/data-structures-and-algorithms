//Equal tree partition
//Given a binary tree with n nodes, your task is to check if it's 
//possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

//Logic: Find the sum of the whole tree
//If Sum is odd, then it is not possible to partition the tree.
//If sum is even, then it is possible to partition the tree

        -8(0)
       /     \
    3(-1)    9(9)          : Note that values withing bracket are representing 
  /   \                           the sum of the subtree rooted with itself.  
-8    4                          ex: sum of subTree (3) = 3 + (-8) + 4 = -1
(-8)   (4)

//Check this test case, why total_sum is not inserted in set
//video Link:- https://www.youtube.com/watch?v=wxe6rjaE8cA
int dfs(Node* root, unordered_set<int>& st)
{
    if(root==NULL)return 0;

    int sum= root->val +dfs(root->left,st) + dfs(root->right,st);
    st.insert(sum);
    return sum;
}
bool EqualPartition(Node* root)
{
    if(root==NULL)return false;
    unordered_set<int> st;

    int totalSum=root->val +dfs(root->left,st) +dfs(root->right,st);
    if(totalSum&1)
        return false;

    return (totalSum%2==0) and (st.find(totalSum/2)!=s.end());

}
