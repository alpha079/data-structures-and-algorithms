//Minimum arros to shot all the Ballons lying in intervals
LC 452
// Post Link:- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/888416/C%2B%2B-or-Solution-With-FULL-Explanation-or-Greedy

class Solution {
public:
	//We can sort by starting time or End time
	// This answer is sorted by StartTime
   
    int findMinArrowShots(vector<vector<int>>& p) {
        
        
        int arrow=0;
        int ans=0;
        sort(p.begin(),p.end());
        int current=p[0][1];
        for(auto it: p)
        {
            if(current>=it[0])
            {
                current=min(current,it[1]);
            }
            else{
                ans++;
                current=it[1];
            }
            cout<<current<<" ";
        }
        ans++;
        return ans;
        
    }
};
