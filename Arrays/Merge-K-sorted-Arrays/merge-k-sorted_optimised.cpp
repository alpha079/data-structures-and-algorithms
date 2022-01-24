
//We will use priority queue to solve this question
//
                     {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
//
typedef pair<int,pair<int, int>> ppi;
vector<int> MergeKSortedArray(vector<vector<int>> ar)
{

	int n=ar.size();
	priority_queue<ppi,vector<ppi>,greater<ppi>> pq;

	for(int i=0;i<n;i++)
	{
		pq.push({ar[i][0],{i,0}});   //Inseretd All the first row element in the queue

	}
	vector<int> result;
	while(!pq.empty())
	{
		ppi temp=pq.front();
		pq.top();

		int row=temp.second.first;
		int col=temp.second.second;
		result.push_back(temp.first);

		if(col+1<ar[row].size())
			pq.push({ar[row][col+1],{row,col+1}});

	}
return result;
//Time Complexity:- O(Nlogk) where N= n*k total number of element
//and logk for queue min heapify

}
