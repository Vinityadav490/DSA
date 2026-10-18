class Solution {
public:
    int dsum(int n){
        int sum=0;
        while(n!=0){
            int d=n%10;
            sum+=d;
            n/=10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>nums2(nums);
        sort(nums.begin(),nums.end(),[this](int a,int b){
            int dsum1=dsum(a);
            int dsum2=dsum(b);
            if(dsum1!=dsum2) return dsum1<dsum2;
            return a<b;
        });
        
        for(int i=0; i<nums.size(); i++){
            mp[nums2[i]]=i;
        }
        int ans=0;
        for(int i=0; i<nums2.size(); i++){
            int n1=nums2[i];
            int n2=nums[i];
            int idx=mp[n2];
            if(n1==n2) continue;
            swap(nums2[i],nums2[idx]);
            ans++;
            mp[n1]=idx;
            mp[n2]=i;
        }
        return ans;
    }
};