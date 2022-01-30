
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next)return head;
        //Solution
        //https://leetcode.com/problems/odd-even-linked-list/discuss/1607746/C%2B%2B-Simple-Solution-w-Images-and-Explanation-or-Brute-Force-%2B-O(1)-In-place-Transformation
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* neweven=even;
        
        while(even && even->next)
        {
            odd=odd->next=even->next;
           
            even=even->next=odd->next;
            
            
           
        }
        odd->next=neweven;
        return head;
        
    }
};
