//Construct Binary Tree form String (Negative and multi digits input is possible)
//-43(2(3)(1))(6(5))
//https://www.youtube.com/watch?v=BH_btihSwVM

//Start will be passed by reference
//TC O(n) , n is length of string
Node* ConstructTreeFromString(String s,int& start)
{

    if(start>=s.size())return NULL;

    //Declare a variable for negative value
    bool negative=false;

    if(s[start]=='-')
    {
        negative=true;
        start++;
    }
     int num=0;
    while(start<s.size() && s[start]!='(' && s[start]!=')')
    {
       int _num=s[start]-'0';
       num=num*10 + _num;
       start++;
    }

    if(negative==true)
    {
        num=-num;
    }
    TreeNode* root= new TreeNode(num);
    if(start>=s.size())return root;

    if(start<s.size() && s[start]=='(')
    {
        start++;
        root->left=ConstructTreeFromString(s,start);
        start++; //Skipping of ")" brackett
    }
    i
    if(start<s.size() and s[start]=='(')
    {
        start++;
        root->right=ConstructTreeFromString(s,start);
        start++;   //Skipping of ")" brackett
    }
     
    
    return root;


}
