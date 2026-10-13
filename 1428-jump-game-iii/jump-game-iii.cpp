class Solution {
public:
    bool solve(vector<int>&arr,int i,vector<int>&vis){
        int n=arr.size();
        if(i<0||i>=n) return false;
        if(arr[i]==0) return true;
        if(vis[i]==0) return false;
        vis[i]=0;
        bool jumpLeft=solve(arr,i-arr[i],vis);
        bool jumpRight=solve(arr,i+arr[i],vis);
        return jumpLeft||jumpRight;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,-1);
        return solve(arr,start,vis);
    }
};