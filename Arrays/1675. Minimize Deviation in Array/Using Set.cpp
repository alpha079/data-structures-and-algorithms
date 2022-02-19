//https://leetcode.com/problems/minimize-deviation-in-array/discuss/1782587/C%2B%2B-oror-Discussed-the-approach-stepwise


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        set<int> s;
        
      //Making All the odd Elements to Even
        for(auto it: nums)
        {
             if(it&1)
             {
                 s.insert(it*2);
             }
            else s.insert(it);
        }
        //Now in Set , Begin() element is Smallest, and End element is largest
        int ans=INT_MAX;
        
        while(*s.rbegin()%2==0)
        {
            int currMax=*s.rbegin();
            s.erase(*s.rbegin());
            s.insert(currMax/2);
            ans=min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};
