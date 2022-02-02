class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        priority_queue<pair<int,char>> maxh;
        for(auto itr:m){
            maxh.push({itr.second,itr.first});
        }
        string ans="";
        while(maxh.size()>1){
            auto [a,b]=maxh.top();
            maxh.pop();
            auto [c,d]=maxh.top();
            maxh.pop();
            ans.push_back(b);
            ans.push_back(d);
            a--;
            c--;
            if(a>0){
                maxh.push({a,b});
            }
            if(c>0){
                maxh.push({c,d});
            }
        }
        if(maxh.size()==1){
            auto [a,b]=maxh.top();
            maxh.pop();
            if(a>1)return "";
            ans.push_back(b);
        }
        return ans;
    }
};
