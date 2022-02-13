class Solution {
public:
    
       
    //TC: O(n(2 ^ n)). 
//For every index i two recursive cases originate, So Time Complexity is O(2^n). If we include the time taken to copy the subset vector into the res vector the time taken will be equal to the size of the subset vector.
    //Blog for TC:- https://medium.com/@vasanths294/permutation-combination-subset-time-complexity-eca924e00071
    void helper(vector<int>& nums, int idx,vector<int>& ans, vector<vector<int>>& res)
    {
        if(idx==nums.size())
        {
            res.push_back(ans); //Copy vector takes O(N) time max for full length
            return;
        }
        ans.push_back(nums[idx]);
        helper(nums,idx+1,ans,res);
        ans.pop_back();
        helper(nums,idx+1,ans,res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums,0,ans,res);
        
        return res;
        
    }
};

//Iterative Version
//
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 

//Using for Loop
class Solution {
public:
  void helper(vector<int>& nums, int idx,vector<int>& ans, vector<vector<int>>& res)
    {
       res.push_back(ans);
      for(int i=idx;i<nums.size();i++)
      {
          ans.push_back(nums[i]);
          helper(nums,i+1,ans,res);
          ans.pop_back();
          
      }
      
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums,0,ans,res);
        
        return res;
        
    }
};

//Using Bitmask
class Solution {
public:
    
    //TC:- O((2^N)*N)
   
    vector<vector<int>> generate(vector<int>& nums, int size)
    {
        
        int subCnt=(1<<size); //2*size 1 left shift 2
        
        vector<vector<int>> res(subCnt);
        for(int mask=0; mask<subCnt;++mask)  //O(2^N)
        {
           
            for(int i=0;i<size;++i)   //O(N)
            {
                cout<<i<<" ";
                if((mask &(1<<i))!=0)
                {
                    res[mask].push_back(nums[i]);
                }
            }
            cout<<endl;
            
            
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
    
        
        return generate(nums,nums.size());
       
        
    }
};
