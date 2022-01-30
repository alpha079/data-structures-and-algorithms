//Generate Parenthesis Problem
//We have been given with "N".Print All the Valid Parenthesis. 

class Solution {
public:
    
    void helper(int &n, int open, int close,string result,vector<string> &finalResult)
    {
        if(open==n and close==n)
        {
            finalResult.push_back(result);
            return;
        }
        if(open<n)
        {
            
            helper(n,open+1,close,result+"(",finalResult);
        }
        if(open>close && close<n)
        {
            
            helper(n,open,close+1,result+")",finalResult);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        int idx=0;
        string result;
        vector<string> finalResult;
        
        helper(n,0,0,result,finalResult);
        return finalResult;
        
        
    }
};

//Another Backtraking Method
//1: Add one to the score when adding opening brackets to the string
//2: Sub one from the score when adding close brackets to the string

//Bases Cases:- 1: if Score is Less than zero
//              2: If length of resultant string is more than 2*input
//              3: If length of string is equal to 2*input && score==0
vector<string> answer;
void Helper(int n, int score, string &result)
{
	if(score<0)
	{
		return; //to previous function call
	}
	if((int)result.size()>2*n)
	{
		return; //to previous function call
	}
	if((int)result.size()==2*n && score==0)
	{
       answer.push_back(result);
	}
	Helper(n,score+1,result+"("); 
	Helper(n,score-1,result+")");
	return;  //return to previous function call
}

vector<string> generateParenthesis(int n) {
        
        string result;
        
        
        helper(n,0,result);
        return answer;
        
        
    }


//Another Methid
    class Solution {
public:
    
    void _helper(int n, vector<string> &res, string s, int bal)
    {
        if(n==0 && bal==0)
        {
            res.push_back(s);
            return;
        }
        
        if(n<0 || bal<0)
            return;
        
        _helper(n-1,res,s+'(',bal+1);
         _helper(n-1,res,s+')',bal-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        _helper(2*n,res,"",0);
        
        return res;
        
    }
};
