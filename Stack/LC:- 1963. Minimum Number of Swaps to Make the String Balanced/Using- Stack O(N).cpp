//TC:- O(N) SC:- O(N)
//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1390319/How-to-reach-the-optimal-solution-or-Explained-with-Intuition-and-Diagram
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int swap=0;
       for(int i=0;i<size(s);i++)
       {
           if(s[i]=='[')
           {
               st.push(s[i]);
           }
           else{
               if(!st.empty())
               {
                   st.pop();
               }
               else swap++;
           }
           
       }
        return (swap+1)/2;
    }
};
