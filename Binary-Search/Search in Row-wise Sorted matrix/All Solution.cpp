Solution 1
Time Complexity - O(row x col)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


//TC:- O(row+col)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        int i=0,j=col-1;
        
        while(i<row and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target)
                i++;
            else j--;
        }
        return false;
        
    }
};


//try to convert this while matric into single array
//TC:- log(row*col) => log(n) where is row*col

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
       int low=0,high=row*col-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int midVal=matrix[mid/col][mid%col];
            
            if(midVal==target)
            {
                return true;
            }
            else if(target>midVal)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
        
    }
};
