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
        int sz=pq.size();
        vector<int>fq;
        while(pq.size()>0){
            int n=pq.top().first;
            fq.push_back(n);
            pq.pop();
        }
        for(int i=0; i<fq.size(); i++){
            if(i<8) count+=fq[i];
            else if(i>=8&&i<16){
                count+=fq[i]*2;
            }
            else if(i>=16&&i<24){
                count+=fq[i]*3;
            }
            else count+=fq[i]*4;
        }
        return count;
    }
};