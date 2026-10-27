class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k=unordered_set<int>(nums.begin(),nums.end()).size();
        int l=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            while(mp.size()==k){
                ans+=nums.size()-i;
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};