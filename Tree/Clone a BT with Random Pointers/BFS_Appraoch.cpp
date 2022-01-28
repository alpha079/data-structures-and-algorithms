/BFS appraoch for Clone a Binary Tree

Node* CloneTree(Node* root)
{
    if(root==NULL)return NULL;
    unordered_map<Node*,Node*> map;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();

        if(curr!=NULL)
        {
            Node* newNode= new Node(curr->val);
            map[curr]=newNode;
            q.push(curr->left);
            q.push(curr->right);

        }
    }
    q.push(root);

    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();

        if(curr!=NULL)
        {
            Node* cloneNode=map[curr];
            q.push(curr->left);
            q.push(curr->right);

            if(curr->left!=NULL)
            {
                cloneNode->left=map[curr->left];
            }
            if(curr->right!=NULL)
            {
                cloneNode->right=map[curr->right];
            }
            if(curr->random!=NULL)
            {
                cloneNode->random=map[curr->random];
            }

        }
      //TC:- O(N)
    }
    return map[root];

}
