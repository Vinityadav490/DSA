class Solution {
public:
    long long solve(int i,int last,int next,int n,vector<vector<vector<long long>>>&dp,vector<vector<int>>&cost){
        if(i>=n/2) return 0;
        if(dp[i][last+1][next+1]!=-1) return dp[i][last+1][next+1];
        long long mini=LLONG_MAX;
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j!=k&&j!=last&&k!=next){
                   mini=min(mini,cost[i][j]+cost[n-i-1][k]+solve(i+1,j,k,n,dp,cost));
                }
            }
        }
        return dp[i][last+1][next+1]=mini;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(4+1,vector<long long>(4+1,-1)));
        return solve(0,-1,-1,n,dp,cost);
    }
};