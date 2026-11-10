class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>mentions(n,0);
        unordered_map<int,int>mp;
        sort(events.begin(),events.end(),[](auto &a,auto &b){
            int t1=stoi(a[1]);
            int t2=stoi(b[1]);
            if(t1==t2) return a[0]=="OFFLINE";
            return t1<t2;
        });
        for(int i=0; i<events.size(); i++){
            vector<string>status=events[i];
            int time=stoi(status[1]);
            if(status[0]=="MESSAGE"){
                string s=status[2];
                if(s=="HERE"){
                   for(int j=0; j<n; j++){
                       if(mp.find(j)==mp.end()||mp[j]<=time){
                            mentions[j]++;
                       }
                   }
                }
                else if(s=="ALL"){
                    for(int j=0; j<n; j++) mentions[j]++;
                }
                else{
                    stringstream ss(s);
                    string word;
                    while(ss>>word){
                        int id=stoi(word.substr(2));
                        mentions[id]++;
                    }
                }
            }
            else{
                int id=stoi(status[2]);
                mp[id]=time+60;
            }
        }
        return mentions;
    }
};