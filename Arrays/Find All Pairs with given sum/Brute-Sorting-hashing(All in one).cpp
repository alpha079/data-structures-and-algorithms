//Print All Pairs with the given sum 
//Link: https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/

//BruteForce Approach
auto FindAllPairs(int ar[] ,int n, int sum)
{

   vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{

		for(int j=i+1;j<n;j++)
		{
			if(ar[i]+ar[j]==sum)
			{
               v.push_back({ar[i],ar[j]});

			}
		}
	}
	return v;
	//Time Complexity:- O(n^2)
	//Space Complexoty: O(n)
}
//One Approach is that we can sort the array and then run the two pinter approach 
//assiging low pointer to the left and the right pointer to the rightmost (nlogn)
//Optimize Approach //Use Unordered_map

void FindAllPairsOptimize(int ar[], int sum, int n )
{
      unordered_map<int, int> m;
      for(int i=0;i<n;i++)
      {
      	
      	int rem= sum-ar[i];
      	if(m.find(rem)!=m.end())
      	{
           int count=m[rem];
           for(int j=0;j<count;j++)
           {
           	cout<<ar[i]<<" "ar[j]<<endl;
           }
      	}
      	m[ar[i]]++;
      }

}
