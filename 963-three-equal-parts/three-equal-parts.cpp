class Solution {
public:
    vector<int> threeEqualParts(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        for(auto &x:nums){
            if(x==1) count1++;
        }
        if(count1==0) return {0,n-1};
        if(count1%3!=0) return {-1,-1};
        int p1=-1,p2=-1,p3=-1;
        int curr1=0;
        int equal=count1/3;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
               curr1++;
               if(curr1==1) p1=i;
               else if(curr1==equal+1) p2=i;
               else if(curr1==2*equal+1) p3=i;
            }
        }
        while(p3<n){
            if(nums[p1]==nums[p2]&&nums[p2]==nums[p3]){
                p1++;
                p2++;
                p3++;
            }
            else return {-1,-1};
        }
        return {p1-1,p2};
    }
};