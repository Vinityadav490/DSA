class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++) if(nums[i]==k) cnt++;
        int ans=cnt;
        for(int i=1; i<=50; i++){
            if(i==k) continue;
            int maxi=0;
            int s=0;
            for(auto &x:nums){
                if(x==i) s++;
                else if(x==k) s--;
                if(s<0) s=0;
                maxi=max(maxi,s);
            }
            ans=max(ans,cnt+maxi);
        }
        return ans;
    }
};