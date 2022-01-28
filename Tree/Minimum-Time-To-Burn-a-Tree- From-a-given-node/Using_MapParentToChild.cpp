//Given is Address of RootNode and Value of start Node.
// We know, we can go right and left , and increment the count, But how we go up.
// For this , we will make a map called mapChildToParent, which will map child to their parent.

//After that using BFS(BFS gives minimum result in every useCase) , we can calculate the result.


//Tc:- O(N)
//SC:- //O(2*N)

Node* mapChildToParentFunction(Node* root,map<Node*,Node*> mapChildToParent,int start )
{
    Node* res=NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(curr->val==start)
        {
            res=curr;
        }
        if(curr->left)
        {
            map[curr->left]=curr;
            q.push(curr->left);
        }
         if(curr->right)
        {
            map[curr->right]=curr;
            q.push(curr->right);
        }
    }
    return res;
}

int FindMaxDist(map<Node*,Node*> mapChildToParent, Node* root)
{
    queue<Node*> q;
    q.push(root);
    int cnt=0;
    map<Node*,int> vis;
    vis[root]=1;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            auto curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left]=1;
            }
             if(curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right]=1;
            }
            if(map[curr] && !vis[map[curr]])
            {
              vis[map[curr]]=1;
              q.push(map[curr]);
            }

        }
        cnt++;
    }
    return cnt;

}
int TimeToBurn(Node* root, int start)
{
    if(root==NULL)return 0;

    map<Node*,Node*> mapChildToParent;

    Node* targetNode=mapChildToParentFunction(root,map,start);
    int maxDist=FindMaxDist(mapChildToParent,target);
    return maxDist;
  
 
}

