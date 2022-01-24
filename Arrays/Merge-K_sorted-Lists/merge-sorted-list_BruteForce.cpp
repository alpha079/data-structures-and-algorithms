ListNode* mergeList(vector<ListNode*>& list)
{
	int n=list.size();
	vector<int> ar;

	for(int i=0;i<n;i++)
	{
		ListNode* temp=list[i];
		while(temp!=NULL)
		{
			ar.push_back(temp->val);
			temp=temp->next;
		}

	}
	//O(n*k)
	sort(ar.begin(),ar.end());  //O(n*klog(n*k))

	ListNode* tail=new ListNode(-1);
	ListNode* head=tail;
	for(int& i:ar)
	{
		head->next=new ListNode(i);
		head=head->next;

	}
	head=tail->next;
	
	delete tail;
	return head;

//Total Time Complexity:- /O(nklog(nk)) + O(n*k)= (nklog(nk))
	//Space Complexity:- O(n*k);
}
