class Solution {
public:
    int find(vector<int>&start1,vector<int>&end1,vector<int>&start2,vector<int>&end2){
        int fin1=INT_MAX;
        for(int i=0; i<start1.size(); i++){
            fin1=min(fin1,start1[i]+end1[i]);
        }
        int fin2=INT_MAX;
        for(int i=0; i<start2.size(); i++){
            fin2=min(fin2,max(fin1,start2[i])+end2[i]);
        }
        return fin2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int act1=find(landStartTime,landDuration,waterStartTime,waterDuration);
        int act2=find(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(act1,act2);
    }
};