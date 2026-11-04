class Solution {
public:
    int solve(int n,vector<vector<int>>&dp,int i){
        if(n==0) return 1;
        if(dp[i][n]!=-1) return dp[i][n];
        int ans=0;
        for(int j=i; j<5; j++){
           ans+=solve(n-1,dp,j);
        }
        return dp[i][n]=ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(5,vector<int>(n+1,-1));
        return solve(n,dp,0);
    }
};