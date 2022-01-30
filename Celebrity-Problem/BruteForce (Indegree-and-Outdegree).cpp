int FindCelebrity(int n)
{
    int indegree[n]={0};
    int outdegree[n]={0};

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;i++)
        {
            if(m[i][j]==1)
            {
                outdegree[i]+=1;
                indegree[j]+=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(outdegree[i]==0 && indegree[i]==n-1)
            return i;
    }
    return -1;


}
