ListNode* mergeList(vector<ListNode*>& list)
{
	int n=list.size();
	priority_queue<ListNode*,vector<ListNode*>, greater<ListNode*>>pq;

	for(int i=0;i<n;i++)
	{
		if(list[i]!=NULL)
		   pq.push(list[i]);
	}

	ListNode* dummy= new ListNode(-1);
	ListNode* head=dummy;

	while(!pq.empty())
	{
		ListNode* curr=pq.top();
		pq.pop();

		head->next=curr;
		head=head->next;

		if(curr->next!=NULL)
           pq.push(curr->next);

	}
	return dummy->next;
  //Only returning the pointers.
  //not creating any new List

  //O(n*k*logk) where N is total number of elements in the list
}
