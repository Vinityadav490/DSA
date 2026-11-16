class Solution {
public:
    int dfs(int u,vector<int>&op,vector<int>&score,vector<vector<int>>&tree){
        if(tree[u].empty()) return score[u];
        int sm=0;
        int mn=INT_MAX;
        for(int v:tree[u]){
            int val=dfs(v,op,score,tree);
            sm+=val;
            mn=min(mn,val);
        }
        return score[u]+sm-(op[u]==1?mn:min(0,mn));
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>tree(n);
        for(int i=1; i<n; i++){
            tree[parent[i]].push_back(i);
        }
        return dfs(0,op,score,tree);
    }
};