class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int low=0;
        int res=0;
        int sum=0;
        int right=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            
            while(sum+k<right-low+1)
            {
                res=max(res,right-low);
                sum-=nums[low];
                low++;
            }
            right++;
        }
        return res=max(res,right-low); //This test case is important
        //[0,0,0,1] k=4 , output=4

        
    }
};

//Other Sliding Window Solution 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left=0;
        int zero=0;
        int res=0;
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]==0)
                zero++;
            if(zero>k)
            {
                if(nums[left]==0)zero--;
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};
