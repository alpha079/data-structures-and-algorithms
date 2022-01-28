//INvert Binary Tree
//Just Swap the left and right pointers
class Solution {
public:

    void swap(TreeNode* node1,TreeNode* node2)
    {
           TreeNode* tmp = node1->left;
        node1->left = node2->right;
        node2->right = tmp;
    }

    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)return NULL;
        
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
        
    }
};

//BFS Appraoch using Queue
TreeNode* invertTree(TreeNode* root) {
    
    if(nullptr == root) return root;
    
    queue<TreeNode*> myQueue;   // our queue to do BFS
    myQueue.push(root);         // push very first item - root

    while(!myQueue.empty()){    // run until there are nodes in the queue 
        
        TreeNode *node = myQueue.front();  // get element from queue
        myQueue.pop();                     // remove element from queue
                 
        if(node->left != nullptr){         // add left kid to the queue if it exists
            myQueue.push(node->left);
        }
        
        if(node->right != nullptr){        // add right kid 
            myQueue.push(node->right);
        }
        
        // invert left and right pointers      
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;

    }

    return root;
}
