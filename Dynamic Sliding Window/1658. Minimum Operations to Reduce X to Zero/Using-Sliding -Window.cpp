/*
//Post Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/1080880/Are-you-stuck-once-read-this-.-logic-explained-clearly-or-easy-to-understand
so , the problem is saying that we can remove either leftmost or rightmost element and we have to remove them in such a way that
1.remove minimum number of elements and
2. sum of all removed element is X

Now main point is that if successfully remove elements such that sum of removed elements is X , then

sum of remaining array elements will be (sum-X)
remaing array will be subarray of original array.

So , now our task is find subaarray whose sum is (sum - X) and its length is maximum ( because we want to remove minimum number of elements , so we will have to maximise remianing element ) .

time - O(N)
space - O(1)

*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum < x) return -1;
        if(sum==x)return nums.size();
        int target=sum-x;
        int low=0;
        
        int ans=0;
        int current=0;
        for(int high=0;high<nums.size();high++)
        {
            current+=nums[high];
            
            while(current>target)
            {
                current-=nums[low++];
            }
            if(current==target)
            {
                ans=max(ans,high-low+1);
            }
         
        }
        return ans==0 ?-1:nums.size()-ans;
    }
};
