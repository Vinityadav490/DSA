class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        for(int i=0; i<n; i++){
            vector<int>fq;
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                int num=nums[j];
                if(mp.find(num)==mp.end()){
                    mp[num]=fq.size();
                    fq.push_back(1);
                }
                else fq[mp[num]]++;
                bool ok=true;
                for(int t=0; t<fq.size(); t++){
                    if(fq[t]!=t+1){
                        ok=false;
                        break;
                    }
                }
               if(ok) cnt++;
            }
        }
        return cnt;
    }
};