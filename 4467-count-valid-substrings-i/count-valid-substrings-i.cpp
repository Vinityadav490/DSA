class Solution {
public:
    long long countValidSubstrings(string s) {
        long long l=0;
        long long ans=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            while(i-l>=2&&s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c'){
               l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};