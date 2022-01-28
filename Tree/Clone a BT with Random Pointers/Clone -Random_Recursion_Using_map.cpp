Node* cloneUtil(Node* root,unordered_map<Node*,Node*>& map)
{
    if(root==NULL)return NULL;
    Node* cloneRoot=new Node(root->val);
    map[root]=cloneRoot;
    cloneRoot->left=cloneUtil(root->left,map);
    cloneRoot->right=cloneUtil(root->right,map);
    return cloneRoot;
}
void AttachRandomPointer(Node* root,Node* cloneRoot,unordered_map<Node*, Node*>& map)
{
      if(root==NULL)return;

      cloneRoot->random=map[root->random];
      AttachRandomPointer(root->left,cloneRoot->left,map);
      AttachRandomPointer(root->right,cloneRoot->right,map);
      return;
}

Node* CloneTree(Node* root)
{
    if(root==NULL)return NULL;
    unordered_map<Node*,Node*> map;
    map[NULL]=NULL;
    Node* cloneRoot=cloneUtil(root,map);

    //Now we got the map ready and clone tree ready

   AttachRandomPointer(root,cloneRoot,map);
   return cloneRoot;

   //Time:- O(N)
   //Space:- O(N) for map 
}
