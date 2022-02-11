int m=s1.length(),n=s2.length();
		//base condition
        if(m>n) return false;
        vector<int> m1(26,0),m2(26,0);
        for(int i=0;i<m;i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
		//if the permutation occurs at the beginning
        if(m1==m2) return true;
        int start=0,end=m;
		//Apply sliding window and check for permutation in each iteration
        while(end<n){
            m2[s2[start++]-'a']--;
            m2[s2[end++]-'a']++;
            if(m1==m2) return true;
        }
        return false;
