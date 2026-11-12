class Solution {
public:
    int maxDistance(string s, int k) {
        int n=0;
        int so=0;
        int e=0;
        int w=0;
        int ans=0;

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='N') n++;
            else if(s[i]=='E') e++;
            else if(s[i]=='S') so++;
            else w++;

            int curr=abs(n-so)+abs(e-w);

            int ext1=min(n,so);
            int ext2=min(e,w);

            int changes=min(k,ext1+ext2);

            curr+=2*changes;

            ans=max(ans,min(i+1,curr));
        }

        return ans;
    }
};