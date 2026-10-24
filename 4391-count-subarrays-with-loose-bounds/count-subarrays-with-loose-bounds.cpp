class Solution {
public:
long long countSubarrays(vector<int>& nums, int minK, int maxK){
        long long l=0;
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=minK&&nums[i]<=maxK) l++;
            else {
                ans+=l*(l+1)/2;
                l=0;
            }
        }
        ans+=l*(l+1)/2;
        return ans;
    }
};