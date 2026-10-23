class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int>wP;
        for(int i=0; i<n; i++){
            if(nums[i]!=i) wP.push_back(nums[i]);
        }
        if(wP.size()==0) return 0;
        if(wP.size()==1) return wP[0];
        long long ans=wP[0];
        for(size_t i=1; i<wP.size(); i++){
            ans&=wP[i];
        }
        return ans;
    }
};