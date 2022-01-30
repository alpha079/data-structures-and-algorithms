//Optimize it to O(N)

//Algorithm:- 

1: let us chosse a candidate which can be a possible celebrity. (we will iterate over the matrix and check the outdegree);

2: Now after finding the candidate, we will confirm, whethere it is a celebrity or not. If it is not, we will return -1;


int FindCelebrity(int n)
{

   int candidate=0; //intial we assume , 0 is the candidate.

   for(int i=1;i<n;i++)
   {
       if(matrix[candidate][i]==1)
       {
             candidate=i;                //change the candidate.
            
       }
   }

   //now verify if the chosen candidate is the celebrity

   for(int i=0;i<n;i++)
   {
    if(i==candidate)continue;

    else {
            //if candidate know i OR if i dont know the candidate, then no celebrity is there
        if(matrix[candidate][i]==1 || matrix[i][candidate]==0) 
            return -1;
         }
   }

   return candidate; 


}
