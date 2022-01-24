/*
Input : arr[] = { 10, 5, 2, 7, 1, 9 }, 
            k = 15
Output : 4
The sub-array is {5, 2, 7, 1}.

Input : arr[] = {-5, 8, -14, 2, 4, 12},
            k = -5
Output : 5
*/

//[10,0]
 // [15,1]
 //  [17,2]
     24,3
     25,4 
int maxSubarraySum(int ar[], int n, int k)
{
  if(n==0) return 0;
  int max_sum=0;
  for(int i=0;i<n;i++)
  {int sum=0;
  	for(int j=i;j<n;j++)
  	{
      sum+=ar[j];
      if(sum==k)
          max_sum=max(max_sum,j-i+1);
  	}
  }
}
int maxSubarraySumOptimize(int ar[], int n ,int k)
{
	if(n==0) return 0;

	unordered_map<int, int> m;
	int sum=0;
	int maxLen=0;
	for(int i=0;i<n;i++)
	{
		sum+=ar[i];

		if(sum==k)
			maxLen=i+1;
		if(m.find(sum)==m.end())
		{
			//make an entry if sum is not present
			m[sum]=i;
		}
		if(m.find(sum-k)!=m.end())
		{
            if(maxLen<(i-m[sum-k]))
            {
            	maxLen=i-m[sum-k];
            }
		}

	}
	return maxLen;

  //TC:- O(N)
}
