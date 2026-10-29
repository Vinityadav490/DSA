class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'){
                if(st.size()>0){
                    count++;
                    st.pop();
                }
            }
            else st.push(s[i]);
        }
        return count;
    }
};