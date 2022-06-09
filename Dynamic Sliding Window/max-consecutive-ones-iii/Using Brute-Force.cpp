class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                int len=j-i+1;
                if(sum+k>=len)
                {
                    ans=max(ans,len);
                }
                
            }
        }
        return ans;
        
    }
};
