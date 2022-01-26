/*

Implement a function meetingPlanner that given the availability, slotsA and slotsB, of two people and a meeting duration dur, 
returns the earliest time slot that works for both of them and is of duration dur. If there is no common time slot that satisfies the duration requirement, 
return an empty array.

input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 8
output: [60, 68]

input:  slotsA = [[10, 50], [60, 120], [140, 210]]
        slotsB = [[0, 15], [60, 70]]
        dur = 12
output: [] # since there is no common slot whose duration is 12

*/

SlotsA= [10, 15], [20, 40]
SlotsB= [10, 11], [20, 21], [25, 30]
dur = 5
  vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{
  
     vector<int> result;

     int i(0),j(0);
     int start,end;
     while(i<slotsA.size() and j<slotsB.size())
     {
           start=max(slotsA[i][0],slotsB[j][0]);
           end=min((slotsA[i][1],slotsB[j][1]));

           if(start+dur<=end)
           {
           	   result.push_back(start,start+dur);
           	   return result;
           	   //Return the first interval only.
           }

           if(slotsA[i][1]<slotsB[j][1])
           {
           	i++;
           }
           else{
           	j++;
           }
     }
     return result;
  
  //TC:- O(n+m)
  
  
  
}
