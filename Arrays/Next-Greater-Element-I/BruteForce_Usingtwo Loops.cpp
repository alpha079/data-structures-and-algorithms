class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums1.size());
        int k=0;
        vector<int>::iterator it;
        for(int i=0;i<nums1.size();i++)
        {
            int x=nums1[i];
            it=find(nums2.begin(),nums2.end(),x);
            
            int index=it-nums2.begin();
             int t=0;
            for(;index<nums2.size();index++)
            {
                if(nums2[index]>x)
                { 
                    t=1;
                    ans[i]=nums2[index];
                    break;
                    
                }
                
            }
            if(t==0)
            {
                 ans[i]=-1;
            }
            
        }
        return ans;
        
        //Time Complexity:- O(n^2)
        
    }
};
