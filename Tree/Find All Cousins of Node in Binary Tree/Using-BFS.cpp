
//We can also use Level-order Traversal to Find the cosuins of a node.
// We will use a boolean variable to check if we have got the Given node or not.
// If we got the given node, then we will not push any of its child in the queue.

vector<int> FindCousin(Node* root,Node* node)
{
    if(root==node)
    {
        return {};
    }
    vector<int> res;
    queue<Node*> q;
    bool found=false;

    q.push(root);
    while(!q.empty() and !found)
    {
        int size=q.size();

        while(size--)

        {
            Node* curr=q.front();
            q.pop();

            if(curr->left==node || curr->right==node)
            {
                found=true;
            }
            else
            {
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
    }

    if(found)
    {
        int size=q.size();
        while(size--)
        {
            res.push_back(q.front());
            q.pop();
        }
    }
    return res;
    //TC:- O(N)
    //SC:- O(N)
}
