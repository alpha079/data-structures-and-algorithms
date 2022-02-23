class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<int> res;
        while(pq.size()>0)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        
        return res;
        
        //TC:- O(nlogk) + O(nlogn) in worst case
        //SC:- O(N) in worst case
    }
};
