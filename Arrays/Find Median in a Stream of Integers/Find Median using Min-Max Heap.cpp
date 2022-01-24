Finding Median In a stream of integers

//Brure Force :- Insert the coming integers in vector<int> and then sort the vector;
//Find the lenght of the vector 
//If its odd ,then ar[length/2] is the result. Otherwise double(ar[length/2 -1] +ar[length/2])*/2
//Time Complexity will be O(nlogn)+O(1) := O(nlogn)
//Space complexity will be O(n) for extra vector used

//Using Two priority Queue Method
  //Nice Explanation here:
    https://leetcode.com/problems/find-median-from-data-stream/discuss/1330646/C%2B%2BJavaPython-MinHeap-MaxHeap-Solution-Picture-explain-Clean-and-Concise

    //The idea is two divide the two 


//https://www.hackerrank.com/rest/contests/master/challenges/ctci-find-the-running-median/hackers/jana96/download_solution



    class MyHeap{

    private: 
    	priority_queue<int> maxHeap;
    	priority_queue<int,vector<int>,greater<int>> minHeap;
    public:
    	void push(int num)
    	{
    		if(minHeap.empty())
    		{
    			minHeap.push(num);
    			return;
    		}

    		//if current num is greater then top of MinHeap.
    		//First Insert in Minheap. then Pop the top element from MinHeap and insert into MaxHeap

    		if(num>minHeap.top())
    		  minHeap.push(num);
    		else 
    		  maxHeap.push(num);

    		 if(minHeap.size() != maxHeap.size()){
                if(minHeap.size()>maxHeap.size()){
                    int t = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(t);
                }
                else{
                    int t = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(t);
                }
                    
            }
    	}

    	float GetMedian()
    	{
    		 if(minHeap.size()==maxHeap.size()){
                return (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                if(minHeap.size()>maxHeap.size()) 
                    return minHeap.top();
                else
                    return maxHeap.top();
            }
    	}
    };

    int main()
    {
    	int n;
    	cin>>n;
    	vector<int> ar(n);
    	MyHeap mh;

    	for(int i=0;i<n;i++)
    	{
    		cin>>ar[i];
    		mh.push(ar[i]);
    		cout<<hm.GetMedian()<<" ";

    	}
    	return 0;
    }
