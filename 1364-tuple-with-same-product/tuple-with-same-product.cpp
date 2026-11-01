class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int prdt=nums[i]*nums[j];
                mp[prdt]++;
            }
        }
        int tuples=0;
        for(auto &it:mp){
            int prdt=it.first;
            int fq=it.second;
            tuples+=(fq*(fq-1))/2;
        }
        return tuples*8;
    }
};