class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
  sort(nums.begin(),nums.end());
	for(int i=0;i<n-3;i++)
	{
        if(i>0 && nums[i]==nums[i-1]) continue;
		for(int j=i+1;j<n-2;j++)
		{
            if(j>i+1 && nums[j]==nums[j-1])continue;
			int target_2=target-nums[i]-nums[j];
			int low=j+1;
			int high=n-1;

			while(low<high)
			{
				int two_sum=nums[low]+nums[high];
				if(two_sum<target_2)
				{
					low++;
				}
				else if(two_sum>target_2)
				{
					high--;
				}
				else{
					vector<int> temp(4,0);
					temp[0]=nums[i];
					temp[1]=nums[j];
					temp[2]=nums[low];
					temp[3]=nums[high];
					result.push_back(temp);
                    low++;high--;

					while(low<high and nums[low]==temp[2])++low;
					while(low<high and nums[high]==temp[3])--high;
				}
			}
			//while(j<n and nums[j+1]==nums[j])++j;

		}
		//while(i<n and nums[i+1]==nums[i])++i;
	}
	return result;
        
    }
};
