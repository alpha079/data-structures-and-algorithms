class Solution {
public:
    
    //TC:- O(2^N)
    //TC Discussed here :- https://leetcode.com/problems/combination-sum/discuss/16634/If-asked-to-discuss-the-time-complexity-of-your-solution-what-would-you-say
    void solve(vector<int>& num, int target,vector<vector<int>>& res,vector<int>& mid, int begin)
    {
        if(target==0)
        {
            res.push_back(mid);
            return;
        }
        for(int i=begin;i!=num.size() && target>=num[i];++i)
        {
            mid.push_back(num[i]);
            solve(num,target-num[i],res,mid,i);
            mid.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
         vector<vector<int>> res;
        vector<int> mid;
        solve(candidates,target,res,mid,0);
        return res;
        
    }
};
