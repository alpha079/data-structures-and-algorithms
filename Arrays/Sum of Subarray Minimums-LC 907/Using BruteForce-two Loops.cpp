//optimization of  problem: time O(n^2)
//in previous solution  , we are creating subarrays from start to end.
//now we will start creating subarrays from end to start .
// we will create subarrays like end to end , end-1 to end , then end-2 to end .....start to end.In this process we are calculating min also.
//so no need to calculate min individually
class Solution {

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int res=0;
        for(int i=0;i<arr.size();i++)
        {
            int small=arr[i];
            
            for(int j=i;j>=0;j--)
            {
                small=min(small,arr[j]);
                res+=small;
            }
        }
        return res%1000000007;
        
    }
};
