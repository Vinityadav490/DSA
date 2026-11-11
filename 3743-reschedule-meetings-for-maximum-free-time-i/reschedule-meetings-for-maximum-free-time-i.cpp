class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freeTime;
        int n=startTime.size();
        for(int i=0; i<startTime.size(); i++){
            if(i==0) freeTime.push_back(startTime[i]-0);
            else{
                freeTime.push_back(startTime[i]-endTime[i-1]);
            }
        }
        freeTime.push_back(eventTime-endTime[n-1]);
        k=k+1;
        int ans=0;
        int sum=0;
        for(int i=0 ;i<k; i++){
            sum+=freeTime[i];
        }
        ans=max(ans,sum);
        for(int i=k; i<freeTime.size(); i++){
            sum-=freeTime[i-k];
            sum+=freeTime[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};