//Using Unordered_map
//TC:- O(N)
//SC;- O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        unordered_map<int,int> map;
        
        for(auto it: nums)
        {
            if(++map[it]>nums.size()/2)
            {
                return it;
            }
        }
        
        return 0;
       
    }
};

//using Sorting 
//TC: O(nlogn) SC:- O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the vector
        return nums[nums.size()/2];     // middle element will be the most frequent Element
    }
};

//Using MooreVoting Algorithm
//TC:- O(n) SC:- O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate=0;
        int cnt=0;
        
        for(auto it: nums)
        {
            if(cnt==0)
            {
                candidate=it;
                
            }
            if(candidate==it)
            {
                cnt++;
            }
            else cnt--;
        }
        return candidate;
        
    }
};
