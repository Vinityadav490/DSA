class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto &num:nums) num%=k;
        int l=0;
        int r=0;
        int ans=1;
        while(r<n){
            if(nums[l]!=nums[r]) l=r;
            long long sum=1LL*nums[r]*(r-l+1);
            if(sum%k==nums[r]) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};