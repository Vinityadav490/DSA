class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==0&&j==0){
            if(k>0) return max(0,grid[0][0]);
            return grid[0][0];
        }
        if(i<0||j<0||k<0) return -1e9;
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int x=grid[i][j];
        int ans=x+max(solve(grid,i-1,j,k,dp),solve(grid,i,j-1,k,dp));
        if(x<0&&k>0) ans=max({ans,solve(grid,i-1,j,k-1,dp),solve(grid,i,j-1,k-1,dp)});
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        int k=2;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1, INT_MIN)));
        return solve(coins,m-1,n-1,2,dp);
    }
};