class Solution {
public:
    bool solve(vector<vector<char>>&grid,int i,int j,int balance, vector<vector<vector<int>>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m||j>=n) return false;
        if(grid[i][j]=='(') balance++;
        else{
            balance--;
        }
        if(balance<0) return false;
        if(balance>(m-1-i)+(n-1-j)) return false;
        if(i==m-1&&j==n-1){
           if(balance==0) return true;
           return false;
        }
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        return dp[i][j][balance]=solve(grid,i+1,j,balance,dp)||solve(grid,i,j+1,balance,dp); 
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==')'||grid[m-1][n-1]=='(') return false;
        if((m+n-1)%2!=0) return false;
        int balance;
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(m+n+1,-1)));
        return solve(grid,0,0,0,dp);
    }
};