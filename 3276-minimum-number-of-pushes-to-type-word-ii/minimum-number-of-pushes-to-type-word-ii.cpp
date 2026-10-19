class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(char c:word){
            mp[c]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        if(pq.size()<=8) return word.size();
        int count=0;
        vector<int>fq;
        int i=0;
        while(pq.size()>0){
            int n=pq.top().first;
            count+=n*(i/8+1);
            pq.pop();
            i++;
        }
        return count;
    }
};