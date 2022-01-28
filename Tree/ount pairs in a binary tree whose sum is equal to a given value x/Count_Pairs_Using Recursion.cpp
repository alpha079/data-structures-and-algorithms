//https://www.geeksforgeeks.org/count-pairs-in-a-binary-tree-whose-sum-is-equal-to-a-given-value-x/
//Count pairs in a binary tree whose sum is equal to a given value x

//See this Problem as a Two Sum Problem over Tree. Curr is node starting from root, going to left and then Right

bool findPairs(Node* root, Node* curr, int x)
{
    if(!curr)
        return false;

    if(root!=curr && (root->data + curr->data==x))
    {
        return true;
    }
    if(findPairs(root->left,curr,x) || findPairs(root->right,curr,x))
    {
        return true;
    }
    return false;
}

int countPair(Node* root, Node* curr, int x, int& count)
{
    if(!curr) return;

    if(findPairs(root,curr,x)==true)
    {
        count++;
    }

    countPair(root,curr->left,x,count);
    countPair(root,curr->right,x,count);

    return count/2;

    //Time: O(n^2)
    //Space: Recursion Stack used
}
