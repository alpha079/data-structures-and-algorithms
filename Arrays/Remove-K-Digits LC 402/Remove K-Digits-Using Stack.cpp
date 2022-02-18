
//Brute Force appraoch is, we will use Teo nested loops and Find out number greater than the current one in left side.
////Logic Is Pretty Simple I have to Just Find the digit which are greater than from next one or we can say 
//that previous digit which are greater than from next one.

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
  
  //Logic:- 1 traversed, then 4 (1<4) no k--
  //        3 is traversed, then 4>3 , so k--
  //        2 is traversed, 3>2, so k--
  //        2 is traversed, 2>2 , no , so k remains k=1
  //        1 is traversed, 2>1, so k--
  
  TC:- O(N^2)
    //Test cases: "12345" k=3 
    //Test Cases:- "100200" k=1, we dont have to print "00" in ans. Output should be"200"
    
  //We can reduced to O(N) buy using Stack
    
    class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.size();
        if(k==n)return "0";
        
        
        stack<char> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(num[i]);
            }
            else{
                
                while(!s.empty() && s.top()>num[i] && k>0)
                {
                    k--;
                    s.pop();
                }
                s.push(num[i]);
            }
        }
    // Ex: "12345", k=3
	// For the above example, while inserting the elements, no element will be popped
	// But we need to remove 'k' characters 
	// Hence remove the top k characters
        while(k!=0)
        {
            s.pop();
            k--;
        }
        
    //Empty the stack to get the number;
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans;
        
        // Removing leading zeroes
	while(ans.length() > 0 && ans[0] == '0'){
		ans.erase(0, 1);
	}
        return ans.empty() ?"0" :ans;
        
    }
};
