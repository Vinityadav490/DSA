class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>n1;
        int n=nums1.size();
        vector<long long>ans(n);
        for(int i=0; i<nums1.size(); i++){
            n1.push_back({nums1[i],i});
        }
        sort(n1.begin(),n1.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        int j=0;
        for(int i=0; i<n; i++){
            int idx=n1[i].second;
            while(j<i){
                int prev=n1[j].second;
                if(n1[j].first>=n1[i].first) break;
                pq.push(nums2[prev]);
                sum+=nums2[prev];
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                j++;
            }
            ans[idx]=sum;
        }
        return ans;
    }
};