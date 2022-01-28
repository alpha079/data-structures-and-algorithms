//Find the sum of nodes at max Depth level
//The sum of nodes at the last level
//TC:- O(N) where N is number of nodes

int maxDepth(Node* root)  //This is also called height of the tree
{
	if(root==NULL)return 0;  //base case

	return 1+max(maxDepth(root->left),maxDepth(root->right));
}
int maxDepthSumUtil(Node* root, int max)
{
	if(root=NULL)return 0;

	if(max==1)return root->data;

	return maxDepthSumUtil(root->left,max-1)+maxDepthSumUtil(root->right,max-1);
}

int maxDepthSum(Node* root)
{
	if(root==NULL)return 0;

	int maxdep=maxDepth(root);

	return maxDepthSumUtil(root,maxdep);
}
