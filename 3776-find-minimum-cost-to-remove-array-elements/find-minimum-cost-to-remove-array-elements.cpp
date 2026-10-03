class Solution {
public:
    int solve(int ext,vector<int>&nums,int i,vector<vector<int>>&dp){
        if(i==nums.size()) return nums[ext];
        if(i==nums.size()-1) return max(nums[ext],nums[i]);
        if(dp[ext][i]!=-1) return dp[ext][i];
        int f=max(nums[i],nums[i+1])+solve(ext,nums,i+2,dp);
        int s=max(nums[ext],nums[i+1])+solve(i,nums,i+2,dp);
        int t=max(nums[ext],nums[i])+solve(i+1,nums,i+2,dp);
        return dp[ext][i]=min({f,s,t});
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,1,dp);
    }
};