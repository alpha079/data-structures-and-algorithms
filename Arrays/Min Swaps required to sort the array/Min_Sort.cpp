//Min Swaps to srt the array

//I will try to sort the second (pair.second) after sorting the vector by first element
int minSwapToSort(int ar[], int n)

{
	if(n==0)return 0;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		v[i].first=ar[i];
		v[i].second=i;
	}
	sort(v.begin(),v.end()); //Sort by first value

	int swaps=0;

	for(int i=0;i<n;i++)
	{
		if(v[i].second==i)continue;

		else{
			swap(v[i].first,v[v[i].second].first);
			swap(v[i].second,v[v[i].second].second);

		}
		if(v[i].second!=i)
		{
			--i;
		}
		swap++;
	}
	return swaps;
	//Time Complexity:O(nlogn)
	//Space complexity:0- O(n)
}
