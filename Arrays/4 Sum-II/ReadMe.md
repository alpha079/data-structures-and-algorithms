See, this is possibly the easiest Sum problem among 2Sum, 3Sum, 4Sum. Just store the frequency of array OR array sum in an hashmap, using a loop OR nested loop (say loop 1). Use another loop OR nested loop to find the required sum in hashmaps. Don't worry if you won't get it, let me explain:

	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for(int i=0; i<nums4.size(); i++){ // loop 1 to store frequency of num4 elements
            m[nums4[i]]++;
        }
        
        int count=0;
        
        for(int i=0; i<nums1.size(); i++){  
            for(int j=0; j<nums2.size(); j++){
                for(int k=0; k<nums2.size(); k++){   // nested loop 2, to find the remaining sum from hashmap
				
                    int sum= nums1[i]+nums2[j]+nums3[k];
                    int search= (-1)*sum;
                    if(m.count(search) >0 ){
                        count+=m[search];
                    }
                }
            }
        }
        
        return count;
    }
So, here the complexity is O(n) [loop 1]+ O(n^3) [for nested loop 2] == O(n^3) [TLE] ✖
We could perform another approach: Using nested loop1 to store num1[i] + num2[j] + num3[k]frquency in hashmap and use another loop to find -num4[i] in hashmap but this will also results in TC O(n^3)
O(n^3) [to store 3 array sum frequency] + O(n) to seach in hashmap == O(n^3) [TLE] ✖
We can play optimally if we use nested loop 1 to store frequency of num1[i] + num2[j] in and use another nested loop 2 to search -(num3[i] + num4[j]) in hashmap. This would improve the complexity to a great extent.
O(n^2)[ to store 2 array sum frequency] +O(n^2)[ to search in hasmap] == O(n^2) [Passed]✔
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for(int i=0; i<nums3.size(); i++){  // nested loop 1 [ O(n^2) ]
            for(int j=0; j<nums4.size(); j++){
                m[ nums3[i]+nums4[j] ]++;
            }
        }
        
        int count=0;
        
        for(int i=0; i<nums1.size(); i++){   // nested loop 2 [ O(n^2) ]
            for(int j=0; j<nums2.size(); j++){
                int sum= nums1[i] + nums2[j];
                int search= (-1)*sum;
                if(m.count(search) >0 ){
                    count+=m[search];
                }
        
            }
        }
        
        return count;
    }
