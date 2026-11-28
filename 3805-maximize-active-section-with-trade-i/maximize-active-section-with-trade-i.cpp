class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ans=0;
        vector<int>z;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n&&s[i]=='0') i++;
                z.push_back(i-start);
            }
            else{
                ans++;
                i++;
            }
        }
        int gain=0;
        for(int i=1; i<z.size(); i++){
            gain=max(gain,z[i]+z[i-1]);
        }
        return ans+gain;
    }
};