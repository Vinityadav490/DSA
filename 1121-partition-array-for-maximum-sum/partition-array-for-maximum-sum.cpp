class Solution {
public:
    int solve(vector<int>&arr,int i,int k,vector<int>&dp){
        int n=arr.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        int curr=INT_MIN;
        for(int j=i; j<n&&j-i+1<=k; j++){
            curr=max(curr,arr[j]);
            ans=max(ans,((j-i+1)*curr)+solve(arr,j+1,k,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=1; i<=n; i++){
            int curr=INT_MIN;
            for(int j=1; j<=k&&i-j>=0; j++){
                curr=max(curr,arr[i-j]);
                dp[i]=max(dp[i],curr*j+dp[i-j]);
            }
        }
        return dp[n];
    }
};