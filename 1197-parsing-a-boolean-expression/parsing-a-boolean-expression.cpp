class Solution {
public:
    char solve(vector<char>&val,char oprn){
        if(oprn=='!') return val[0]=='t'?'f':'t';
        if(oprn=='&'){
            for(char ch:val){
                if(ch=='f') return 'f';
            }
            return 't';
        }
        if(oprn=='|'){
        for(char ch:val){
            if(ch=='t') return 't';
        }
        return 'f';
        }
        return 'f';
        
    }
    bool parseBoolExpr(string e) {
        stack<char>st;
        for(int i=0; i<e.size(); i++){
            if(e[i]==')'){
                vector<char>val;
                while(st.top()!='('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char oprn=st.top();
                st.pop();
                st.push(solve(val,oprn));
            }
            else if(e[i]==',') continue;
            else st.push(e[i]);
        }
        return st.top()=='t'?true:false;
    }
};