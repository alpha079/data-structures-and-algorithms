class Solution {
public:
    
    //Brute Force Appraoch
    //Run the two loop. Count the number of zeroes and ones in inner loop
    //When zeroes==ones, update the max range count
    int findMaxLength(vector<int>& nums) {
        int zero=0;
        int one=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            zero=0,one=0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]==0)zero++;
                else one++;
                
                if(zero==one)
                {
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
        
    }
};
