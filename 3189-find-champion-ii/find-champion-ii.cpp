class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0);
        for(auto &edge:edges){
            indeg[edge[1]]++;
        }
        int cnt=0;
        int node=0;
        for(int i=0; i<indeg.size(); i++){
            if(indeg[i]==0) {
                cnt++;
                node=i;
            }
        }
        if(cnt==1) return node;
        return -1;
    }
};