
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
  
  //Longest Common Prefix will be common in all the String of vector
  

class Solution {
public:
    //TC:- O(NlogN)
    
    string longestCommonPrefix(vector<string>& str) {
        
        if(str.size()==0)
            return "";
        
        string res="";
        
        sort(str.begin(),str.end());
        
        auto start=str.front();
        auto back=str.back();
        
        for(int i=0;i<size(start);i++)
        {
            if(start[i]==back[i])
            {
                res+=start[i];
            }
            else break;
        }
        return res;
        
        
        
    }
};
