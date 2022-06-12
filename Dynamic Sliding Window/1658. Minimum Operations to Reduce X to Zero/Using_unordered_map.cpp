Approach 1: Doing the PrefixSum from start to end, and store the sum at each index into the unordered_map. 
            Again doing the SuffixSum from end to start, and checking if we are able to find the X-sum, in the map.
            At each step , update the result if X==Sum.size


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        unordered_map<int,int> mp;
        int ans=INT_MAX;
                
        int n=nums.size();

        for(int i=0,preSum=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            mp[preSum]=i+1;
            if(preSum==x)
            {
                ans=min(ans,i+1);
            }
        }
        
        for(int i=nums.size()-1,sufSum=0;i>=0;i--)
        {
            sufSum+=nums[i];
            if(sufSum==x)
            {
                
                ans=min(ans,n-i);
            }
            if(mp[x-sufSum]>0 && i+1>mp[x-sufSum])
            {
                ans=min(ans,n-i+mp[x-sufSum]);
            }
            
        }
        return ans==INT_MAX?-1: ans;
        
    }
};
