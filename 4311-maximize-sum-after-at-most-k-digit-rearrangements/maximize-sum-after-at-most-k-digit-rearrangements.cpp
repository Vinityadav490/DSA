class Solution {
public:
    string solve(string n){
        sort(n.begin(),n.end());
        reverse(n.begin(),n.end());
        return n;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        priority_queue<pair<long long,int>>pq;
        int n=nums.size();
        for(int i=0; i<n; i++){
            string num=to_string(nums[i]);
            string s=solve(num);
            long long mod=stoll(s);
            if(mod>nums[i]) pq.push({mod-nums[i],i});
        }
        long long sum=0;
        while(k>0&&pq.size()>0){
            long long num=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            sum+=num;
            k--;
        }
        
        for(auto it:nums)  sum+=it;
        return sum;
    }
};