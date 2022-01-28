//O(n) Approach
//SC:- O(N)

Input : 
        5      
       / \      
      3   7      
     / \ / \  
    2  4 6  8   

        x = 10

Output : 3
The pairs are (3, 7), (2, 8) and (4, 6).

void helper(Node* root, int x, unordered_map<int,int>& map, int& cnt)
{
      if(!root)return;

      if(map.find(root)!=map.end())
      {
        cnt++;
      }
      else{
        map[x-root->data]++;
      }
      helper(root->left,x,map,cnt);
      helper(root->right,x,map,cnt);
}

int countPair(Node* root, int x)
{
    unordered_map<int, int> map;

    int cnt=0;
     helper(root,x,map,cnt);
    return cnt;
}
