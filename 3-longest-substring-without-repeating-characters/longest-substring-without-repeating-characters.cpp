class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int ans=0;
        int l=0;
        int n=s.size();
        for(int i=0; i<s.size(); i++){
            while(st.count(s[i])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};