class Solution {
public:
//Time:- O(Nlogk)
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        ListNode* head;
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1->val<l2->val){
        head=l1;
        head->next=mergeList(l1->next,l2);
    }
    else{
         head=l2;
        head->next=mergeList(l1,l2->next);
    }
    return head;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* head=NULL;
        for(auto list: lists)
        {
            head=mergeList(head,list);
        }
        return head;
    }
};
