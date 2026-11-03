class Solution {
public:
    bool solve(vector<vector<pair<int,int>>>adj,int mid,int n){
        queue<int>q;
        q.push(0);
        vector<int>vis(n,-1);
        vis[0]=1;
        while(q.size()>0){
            int node=q.front();
            q.pop();
            for(auto neigh:adj[node]){
                int weight=neigh.second;
                int NODE=neigh.first;
                if(weight<=mid&&vis[NODE]!=1){
                    vis[NODE]=1;
                    q.push(NODE);
                }
            }
        }
        for(int i=0; i<vis.size(); i++){
            if(vis[i]==-1) return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        int h=INT_MIN;
        for(auto &edge:edges){
            int u=edge[1];
            int v=edge[0];
            int wt=edge[2];
            h=max(h,wt);
            adj[u].push_back({v,wt});
        }
        int l=0;
        int ans=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(solve(adj,mid,n)){
                ans=mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};