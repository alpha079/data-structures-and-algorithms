class Solution {
public:
    
/*In this approach , we :

Sort the STRING_1 .
Then we consider every substring of STRING_2 of size equal to size of STRING_1 (Sizeof(substring)==sizeof(STRING1)) .
We sort that substring, and check if the sorted version is equal to the sorted STRING_1.
If yes, then return true. Else , we check the next substring.
If after checking all the possible susbtrings , none of them fulfill the condition, return false.
*/
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        
        sort(s1.begin(),s1.end());
        
        for(int i=0;i+s1.size()<s2.size()+1;i++)
        {
            string temp=s2.substr(i,s1.size());
            sort(temp.begin(),temp.end());
            if(temp==s1)
                return true;
            
        }
        return false;
        
        
    }
};
