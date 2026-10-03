class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        if(n==1) return 0;
        if(n==2){
            if(word[0]==word[1]) return 1;
        }
        int cnt=0;
        for(int i=1; i<word.size(); i++){
           if(word[i]==word[i-1]){
             word[i]='#';
             cnt++;
           }
           else if(word[i]-1==word[i-1]){
            word[i]='#';
            cnt++;
           }
           else if(word[i]==word[i-1]-1){
             word[i]='#';
             cnt++;
           }
        }
        return cnt;
    }
};