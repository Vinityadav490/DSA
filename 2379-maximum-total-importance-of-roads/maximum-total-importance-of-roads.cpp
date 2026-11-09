class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>deg(n);
        for(auto road:roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<deg.size(); i++){
            pq.push({deg[i],i});
        }
        long long sum=0;
        for(int i=n; i>=1; i--){
            if(pq.size()>0){
                long long deg=pq.top().first;
                sum+=deg*i;
                pq.pop();
            }
            else break;
        }
        return sum;
    }
};