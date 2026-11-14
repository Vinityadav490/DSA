class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int mx=0;
        int l=0;
        int v=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])) v++;
            if(i-l+1==k){
                mx=max(mx,v);
                if(isVowel(s[l])) v--;
                l++;
            }
        }
        return mx;
    }
};