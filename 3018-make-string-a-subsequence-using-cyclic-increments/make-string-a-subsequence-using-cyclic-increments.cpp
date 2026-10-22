class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        if(n1<n2) return false;
        int i=0;
        int j=0;
        while(i<str1.size()){
            if(str1[i]==str2[j]||str1[i]+1==str2[j]){
                j++;
                i++;
            }
            else if(str1[i]=='z'&&str2[j]=='a'){
                i++;
                j++;
            }
            else i++;
        }
        if(j==str2.size()) return true;
        else return false;
    }
};