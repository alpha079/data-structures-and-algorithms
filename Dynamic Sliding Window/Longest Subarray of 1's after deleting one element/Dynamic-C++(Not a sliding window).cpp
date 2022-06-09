class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        int sum(0), maxsum(0),prevsum(0);
        
        for(auto it: nums)
        {
            if(it==0)
            {
                prevsum=sum;
                sum=0;
            }
            else sum++;
            maxsum=max(maxsum,prevsum+sum);
        }
        return maxsum;
    }
};
