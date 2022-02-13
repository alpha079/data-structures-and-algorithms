//TC: Exponential
////Time and Space: O(2^(n+m)) and O(N)stack + O(m-1, n-1);
class Solution {
public:
    
    int helper(vector<vector<int>>& grid, int row, int col)
               {
                   if(row<0 || col<0)
                       return INT_MAX;
                   if(row==0 and col==0)
                       return grid[row][col];
                   
                   return grid[row][col] + min(helper(grid,row-1,col),helper(grid,row,col-1));
               }
    int minPathSum(vector<vector<int>>& grid) {
        
        return helper(grid,grid.size()-1,grid[0].size()-1);
        
        
        
    }
};
