//First Solution is to search the Target in the matrix
//Tc:- O(Row*Col)

//Using Binary search in each row

class Solution {
public:
    //TC:- O(Row*log(col))
    bool Search(vector<int> ar, int key)
    {
        int low=0,high=ar.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(ar[mid]==key)
                return true;
            else if(ar[mid]>key)
                 high=mid-1;
            else low=mid+1;
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0)return false;
        
        for(int i=0;i<matrix.size();i++)
        {
            if(Search(matrix[i],target)==true)
                return true;
        }
        return false;
        
    }
};


//Using Two pointers
class Solution {
public:
    //TC:- O(row+col)
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0)return false;
        
        int i=0,j=matrix[0].size()-1;
        
        while(i<matrix.size() and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                 j--;
            else i++;
        }
        return false;
    }
};
